#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
class Fone{
    public:
        int id;
        std::string prefix;
        std::string number;

        Fone(int id=0, std::string number="", std::string prefix=""){
            this->id = id;
            this->number = number;
            this->prefix = prefix;
        }

        //setters
        void setId(int id){
            this->id = id;
        }
        void setNumber(std::string number){
            this->number = number;
        }
        void setPrefix(std::string prefix){
            this->prefix = prefix;
        }
        //getters
        int getId(){
            return id;
        }
        std::string getNumber(){
            return number;
        }
        std::string getPrefix(){
            return prefix;
        }

        //tostring
        std::string toString(){
            std::stringstream ss;
            ss << "[ "<< id << " ]"<< "[ " << "Prefixo: " << prefix << " ] [ " << "Numero: " << number<< " ]\n";
            return ss.str();
        }


};

class Contact{
    public:
        std::vector<Fone> fones;
        std::string firstName;

        Contact(std::vector<Fone> fones, std::string firstName){
            this->fones = fones;
            this->firstName = firstName;
        }

        void addFone(Fone fone){
            //checa id repetido
            while(true){
                for(int i = 0; i < fones.size(); i++){
                    if(fone.getId() == fones[i].getId()){
                        fone.setId(fone.getId()+1);
                        true;
                    }
                }
            fones.push_back(fone);
            break;
            }
        }
        // remove apenas um numero
        void rmFone(std::string prefix){
            for(int i = 0; i < fones.size(); i++){
                if(fones[i].getPrefix() == prefix){
                    fones.erase(fones.begin() + i);
                    std::cout<<"Numero removido com sucesso!"<<std::endl;
                }else{
                    std::cout<<"Nao ha correspondencia entre esse prefixo e este contato!"<<std::endl;
                }
            }
        }


        //setters
        void setFirstName(std::string firstName){
            this->firstName = firstName;
        }
        void setFone(int indice, std::string number){
            fones[indice].number = number;
        }
        //getters
        std::string getFirstName(){
            return firstName;
        }
        std::string getFone(int indice){
            return fones[indice].number;
        }

        //tostring
        std::string toString(){
            std::stringstream ss;
            ss << "Nome: " << firstName << "\n";
            for(int i = 0; i < fones.size(); i++){
                ss << fones[i].toString();
            }
            return ss.str();

        }

};


class Agenda{
    public:

    std::vector<Contact> contacts;

    //metodos
    void addContact(Contact contact){
        contacts.push_back(contact);
    }
    int getId(int indice){
        return contacts[indice].fones[0].id;
    }
    void rmContact(int indice){
        contacts.erase(contacts.begin() + indice);
    }
    //checa se existe pelo nome e retorna o indice
    int findContact(std::string firstName){
        for(int i = 0; i < (int)contacts.size(); i++){
            if(contacts[i].getFirstName() == firstName){
                return i;
            }
        }
        return -1;
    }
    //encontra contatos pela aproximação do nome
    void encontrapelonome(std::string firstName){
        std::vector<Contact> result;
        for(int i = 0; i < (int)contacts.size(); i++){
            if(contacts[i].getFirstName().find(firstName) != std::string::npos){
                result.push_back(contacts[i]);
            }
        }
        // mostra os contatos encontrados
        for(int i = 0; i < (int)result.size(); i++){
            std::cout<<result[i].toString();
            std::cout<<"\n";
        }
    }

    //encontra contatos pela aproximação de numero
    void encontrapelonumero(std::string number){
        std::vector<std::string> result;
        for(int i = 0; i < (int)contacts.size(); i++){
            for(int j = 0; j < (int)contacts[i].fones.size(); j++){
                if(contacts[i].fones[j].number.find(number) != std::string::npos){
                    std::stringstream str;
                    str << "[" << contacts[i].fones[j].id << "] ";
                    str <<"[" << contacts[i].getFirstName() << "] ";
                    str << "[" << contacts[i].fones[j].number << "] ";
                    result.push_back(str.str());
                }
            }
        }
        // mostra o result
        for(int i = 0; i < (int)result.size(); i++){
            std::cout<<result[i]<<std::endl;
        }
    }






    //tostring
    std::string toString(){
        std::stringstream ss;
        for(int i = 0; i < (int)contacts.size(); i++){
            ss << contacts[i].toString() << "\n";
        }
        return ss.str();
    }

};

int main(){
    std::cout<<"Agenda - COMANDOS\t\n";
    std::cout<<"ADICIONAR - add [prefixo] [numero]\n";
    std::cout<<"REMOVER - rm [Nome] [prefixo]\n";
    std::cout<<"MOSTRAR - show\n";
    std::cout<<"PESQUISAR POR NOME - findName [nome]\n";
    std::cout<<"PESQUISAR POR NUMERO - findNumber [numero]\n";
    std::cout<<"COMANDOS - help\n";
    std::cout<<"FINALIZAR - end\n";
    Agenda agenda;
    while(true){
        std::string str;
        std::cin >> str;
        if(str == "end"){
            break;
        }
        if(str == "add"){
            std::string firstName;
            std::string prefix;
            std::string number;

            std::cin >> firstName;
            std::cin >> prefix;
            std::cin >> number;

            //check if contact exists
            int indice = agenda.findContact(firstName);
            if(indice == -1){
                Contact contact(std::vector<Fone>(), firstName);
                Fone fone(0, number, prefix);
                contact.addFone(fone);
                agenda.addContact(contact);

            }else{
                agenda.contacts[indice].addFone(Fone(0, number, prefix));
            }
        }
        if(str == "show"){
            std::sort(agenda.contacts.begin(), agenda.contacts.end(), [](Contact a, Contact b){
                return a.getFirstName() < b.getFirstName();
            });
            std::cout<<agenda.toString();
        }
        if(str == "rm"){
            std::string firstName;
            std::string prefix;
            std::cin >> firstName;
            std::cin >> prefix;

            int indice = agenda.findContact(firstName);
            if(indice == -1){
                std::cout << "Contato nao existe\n";
            }else{      
                agenda.contacts[indice].rmFone(prefix);
            }
        }
        if(str == "findName"){
            std::string firstName;
            std::cin >> firstName;
            agenda.encontrapelonome(firstName);
        }
        if(str == "findNumber"){
            std::string number;
            std::cin >> number;
            agenda.encontrapelonumero(number);
        }
        if(str == "help"){
            std::cout<<"Agenda - COMANDOS\t\n";
            std::cout<<"ADICIONAR - add [prefixo] [numero]\n";
            std::cout<<"REMOVER - rm [Nome] [prefixo]\n";
            std::cout<<"MOSTRAR - show\n";
            std::cout<<"PESQUISAR POR NOME - findName [nome]\n";
            std::cout<<"PESQUISAR POR NUMERO - findNumber [numero]\n";
            std::cout<<"COMANDOS - help\n";
            std::cout<<"FINALIZAR - end\n";
        }
    }   
    return 0;
}
