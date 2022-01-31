#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <memory>

class Kid{
    int idade;
    std::string nome;

public:
    Kid(int idade = 0, std::string nome = ""):
        idade{idade}, nome{nome}{
    }

    void setNome(std::string nome){
        this->nome = nome;
    }

    void setIdade(int idade){
        this->idade = idade;
    }

    int getIdade(){
        return this->idade;
    }

    std::string getNome(){
        return this->nome;
    }

    std::string toString(){
        std::string texto{"|" + this->nome + ":" + std::to_string(this->idade) + "| "};
        return texto;
    }
};

class Trampolim{
    private:
        std::list<Kid> dentro;
        std::list<Kid> fora;
    
    public:
        bool vazio(){
            if(this->fora.empty()){
                return true;
            }
        }

        bool vazio_dentro(){
            if(this->dentro.empty()){
                return true;
            }
        }

        std::string remove(std::string name){
            for(auto it = this->fora.begin(); it != this->fora.end(); it++){
                if((*it).getNome() == name){
                    this->fora.erase(it);
                    return "Crianca Removida";
                }
            }

            for(auto it = this->dentro.begin(); it != this->dentro.end(); it++){
                if((*it).getNome() == name){
                    this->dentro.erase(it);
                    return "Crianca Removida";
                }
            }
            return "Crianca nao encontrada";
        }

        void add(Kid kid){
            this->fora.push_back(kid);
        }

        std::string enter(){
            if(vazio()){
                return "Nao ha criancas para entrar";
            }else{
                this->dentro.push_back(fora.front());
                this->fora.pop_front();
                return "Crianca Entrou";
            }
        }

        std::string leave(){
            if(vazio_dentro()){
                return "Nao ha criancas para sair";
            }else{
                this->fora.push_back(dentro.front());
                this->dentro.pop_front();
                return "Crianca Saiu";
            }
        }

        void clear(){
            this->fora.clear();
            this->dentro.clear();
        }

        std::string toString(){
            std::string texto{"[Fora]: "};
            for(auto it = this->fora.rbegin(); it != this->fora.rend(); it++){
                texto += it->toString() + " ";
            }
            texto += "\n[Dentro]: ";
            for(auto it = this->dentro.rbegin(); it != this->dentro.rend(); it++){
                texto += it->toString() + " ";
            }
            return texto;
        }

};

int main(){
    Trampolim trampolim;
    while(true){
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss{line};
        std::string command;
        ss >> command;

        if(command == "exit"){
            break;
        }else if(command == "show"){
            std::cout << trampolim.toString() << std::endl;
            std::cout << "\n";
        }else if(command == "add"){
            std::string name;
            int idade;
            ss >> name >> idade;
            Kid kid{idade, name};
            trampolim.add(kid);
            std::cout << trampolim.toString() << std::endl;
            std::cout << "\n";
        }else if(command == "remove"){
            std::string name;
            ss >> name;
            std::cout << trampolim.remove(name) << std::endl;
        }else if(command == "enter"){
            std::cout << trampolim.enter() << std::endl;
        }else if(command == "leave"){
            std::cout << trampolim.leave() << std::endl;
        }else if(command == "clear"){
            trampolim.clear();
            std::cout << trampolim.toString() << std::endl;
        }else{
            std::cout << "Comando invalido" << std::endl;
        }

    }
}