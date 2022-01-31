#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

class Client{
    private:
        std::string id;
        std::string phone;
    public:
        Client(std::string id, std::string phone){
            this->id = id;
            this->phone = phone;
        }

        std::string toString(){
            std::stringstream ss;
            ss << " "<< this->id << ":" << this->phone << " ";
            return ss.str();
        }

        std::string getId(){
            return this->id;
        }

        std::string getPhone(){
            return this->phone;
        }

        void setId(std::string id){
            this->id = id;
        }

        void setPhone(std::string phone){
            this->phone = phone;
        }
};

class Sala{
    private:
        int capacidade;
        std::map<std::string, Client> cadeiras;
    public:
        Sala(int capacidade=0){
            this->capacidade = capacidade;
        }

        std::string reservar(Client client, std::string posicao){
            if(cadeiras.find(posicao) != cadeiras.end()){
                return "Posicao ocupada\n";
            }else{
                cadeiras.insert(std::pair<std::string, Client>(posicao, client));
                return "Reserva realizada com sucesso\n";
            }
        }

        void cancelar(std::string id){
            for(auto it = cadeiras.begin(); it != cadeiras.end(); it++){
                if(it->second.getId() == id){
                    cadeiras.erase(it);
                    std::cout << "Reserva cancelada com sucesso" << std::endl;
                    return;
                }
            }
            std::cout << "Reserva nao encontrada" << std::endl;
        }

        void setCapacidade(int capacidade){
            this->capacidade = capacidade;
        }

        void toString(){
            std::cout << "Capacidade: " << this->capacidade << std::endl;
            std::cout << "[ ";
            for(int i=0; i<this->capacidade; i++){
                if(cadeiras.find(std::to_string(i)) != cadeiras.end()){
                    std::cout<<  cadeiras.find(std::to_string(i))->second.toString();
                
                }else{
                    std::cout<< " - ";
                }
            }
        std::cout << " ]" << std::endl;
        }



};

int main(){
    Sala sala;
    

    while (true){
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string command;
        ss >> command;
        if(command == "exit"){
            break;
        }else if(command == "init"){
            int capacidade; 
            ss >> capacidade;
            sala.setCapacidade(capacidade);
            std::cout << "Sala criada com sucesso" << std::endl;
        }else if(command == "reservar"){
            std::string id, phone, posicao;
            ss >> id >> phone >> posicao;
            Client client(id, phone);
            std::cout << sala.reservar(client, posicao);
        }else if(command == "cancelar"){
            std::string id;
            ss >> id;
            sala.cancelar(id);
        }else if(command == "show"){
            sala.toString();
        }else{
            std::cout << "Comando invalido" << std::endl;
        }
    }
    
}