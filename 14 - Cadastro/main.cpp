#include <iostream>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>



class Account {
    protected:
        float balance;
        std::string clientId;
        int id;
        std::string type;
    public:

        Account(float balance, std::string clientId, int id, std::string type) {
            this->balance = balance;
            this->clientId = clientId;
            this->id = id;
            this->type = type;
        }
        void deposit(float amount) {
            this->balance += amount;
        }

        void withdraw(float amount) {
            if (amount > this->balance) {
                throw std::runtime_error("Saldo insuficiente");

            } else {
                this->balance -= amount;
            }
        }

        virtual void monthlyUpdate() = 0;

        void transfer(Account &other, float amount) {
            if(this->balance < amount) {
                throw std::runtime_error("Saldo insuficiente");
            }else if(other.id == this->id) {
                throw std::runtime_error("Não e possivel transferir para a mesma conta");
            }else if(amount <= 0) {
                throw std::runtime_error("Valor invalido");
            }

            this->withdraw(amount);
            other.deposit(amount);

        }
        int getId(){
            return id;
        }
        std::string getType() {
            return this->type;
        }

        friend std::ostream &operator<<(std::ostream &os, const Account &account);
        
        virtual ~Account() {
        }
};
std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "-----------------------------" << std::endl;
    os << "Account type: " << account.type << "\n";
    os << "Client ID: " << account.clientId << "\n";
    os << "Account ID: " << account.id << "\n";
    os << "Balance: " << account.balance << "\n";
    os << "-----------------------------" << std::endl << std::endl;
    return os;
}

class savingsAccount : public Account {
    public:
        savingsAccount(float balance, std::string clientId, int id, std::string type) : Account(balance, clientId, id, type) {
        }

        void monthlyUpdate() override {
            this->balance = this->balance + (balance * 0.01); // 1% interest
        }
};

class checkingAccount : public Account {
    public:
        checkingAccount(float balance, std::string clientId, int id, std::string type) : Account(balance, clientId, id, type) {
        }
        void monthlyUpdate() override {
            std::stringstream ss;
            if(this->balance-5 < 0){
                this->balance = 0;
                
                 throw std::runtime_error(clientId +" sua conta " +  std::to_string(id) + "(" + type + ")"+ " foi bloqueada por falta de saldo, deposite algum valor para desbloquear\n");
            } else {
                this->balance = this->balance - 5;
            }
            
        }
};

class Client{
    private:
        std::vector<Account*> accounts;
        std::string id;
    public:
        Client(std::string id){
            this->id = id;
        }
        void addAccount(Account* account){
            accounts.push_back(account);
        }
        std::string getId(){
            return id;
        }
        std::vector<Account*> getAccounts(){
            return accounts;
        }
        void setAccounts(std::vector<Account*> accounts){
            this->accounts = accounts;
        }
        void setId(std::string id){
            this->id = id;
        }

        friend std::ostream& operator<<(std::ostream& os, const Client& client);
        
};
std::ostream& operator<<(std::ostream& os, const Client& client){
    os << "Client: " << client.id << "[ |";
    for(Account* account : client.accounts){
        os << account->getId() << "| " ;
    }
    os << "]" << std::endl;
    return os;
}

class bankAgency{
    private:
        std::vector<Account*> accounts;
        std::vector<Client*> clients;
    public:
        bankAgency(){
        }
        void addClient(std::string clientId){;
            Client* client = new Client(clientId);
            clients.push_back(client);

            int number = rand() % 9999 + 1; 
            int number2 = rand() % 9999 + 1;

            for(auto &account : accounts){
                if(account->getId() == number){
                    number = rand() % 9999 + 1;
                }
                if (account->getId() == number2){
                    number2 = rand() % 9999 + 1;
                }
            }
            
            Account* accountCP = new savingsAccount(0, clientId, number, "POUPANCA");
            Account* accountCC = new checkingAccount(0, clientId, number2, "CORRENTE");
            client->addAccount(accountCP);
            client->addAccount(accountCC);
            accounts.push_back(accountCC);
            accounts.push_back(accountCP);

            std::cout << *client << std::endl;
        
        }
    
        void deposit(int accountId, float amount){
            for(auto &account : accounts){
                if(account->getId() == accountId){
                    account->deposit(amount);
                    std::cout << "Despositado com sucesso!!" << std::endl;
                    return;
                }
            }
            throw std::runtime_error("Conta nao encontrada");
        }

        void withdraw(int accountId, float amount){
            for(auto &account : accounts){
                if(account->getId() == accountId){
                    account->withdraw(amount);
                    std::cout << "Sacado com sucesso!!" << std::endl;
                    return;
                }
            }
            throw std::runtime_error("Conta nao encontrada");
        }

        void monthlyUpdate(){
            for(auto &account : accounts){
                account->monthlyUpdate();
            }
        }

        Account* getAccount(int accountId){
            for(auto &account : accounts){
                if(account->getId() == accountId){
                    return account;
                }
            }
            throw std::runtime_error("Conta nao encontrada");
        }

        void transfer(int accountId, int accountId2, float amount){
            for(auto &account : accounts){
                if(account->getId() == accountId){
                    for(auto &account2 : accounts){
                        if(account2->getId() == accountId2){
                            account->transfer(*account2, amount);
                            std::cout << "Transferido com sucesso!!" << std::endl;
                            return;
                        }
                    }
                    throw std::runtime_error("Conta nao encontrada");
                }
            }
            throw std::runtime_error("Conta nao encontrada");
        }

        friend std::ostream& operator<<(std::ostream& os, const bankAgency& agency);


};

std::ostream& operator<<(std::ostream& os, const bankAgency& agency){
    os << "Clients: " << std::endl;
    for(auto &client : agency.clients){
        os << *client;
    }
    os << std::endl;
    os << "Accounts: " << std::endl;
    for(auto &account : agency.accounts){
        os << *account;
    }
    return os;
}

int main(){
    bankAgency agency;

    while(true){
        std::string input;
        std::cin >> input;
        try{
            if(input == "update"){
                agency.monthlyUpdate();
            }
            else if(input == "exit"){
                break;
            }else if(input == "addCli"){
                std::string id;
                std::cin >> id;
                agency.addClient(id);
            }else if(input == "deposito"){
                int accountId;
                float amount;
                std::cin >> accountId >> amount;
                agency.deposit(accountId, amount);
            }else if(input == "show"){
                std::cout << agency << std::endl;
            }else if(input == "saque"){
                int accountId;
                float amount;
                std::cin >> accountId >> amount;
                agency.withdraw(accountId, amount);
            }else if(input == "transf"){
                int accountId;
                int accountId2;
                float amount;
                std::cin >> accountId >> accountId2 >> amount;
                agency.transfer(accountId, accountId2, amount);
            }else{
                throw std::runtime_error("Comando invalido");
            }
        } catch (std::runtime_error &e){
            std::cout << e.what() << std::endl;
        }

    }


    return 0;
}
