#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>

class Cliente{
    std::string nome;
    std::string telefone;

    public:
        Cliente(std::string nome, std::string telefone){
            this->nome = nome;
            this->telefone = telefone;
        }

        std::string getNome(){
            return this->nome;
        }

        std::string getTelefone(){
            return this->telefone;
        }

        std::string setNome(std::string nome){
            this->nome = nome;
        }

        std::string setTelefone(std::string telefone){
            this->telefone = telefone;
        }

        std::string toString() {
            return nome + ":" + telefone;
        }        
        
};

class Sala{
    private:
        std::vector<Cliente*> vetorCadeira;

    public:
        Sala(int capacidade = 0){
            vetorCadeira = std::vector<Cliente*>(capacidade);
            for(int i = 0; i < capacidade; i++){
                vetorCadeira[i] = nullptr;
            }
        }

        ~Sala(){
            for(int i = 0; i < vetorCadeira.size(); i++){
                delete vetorCadeira[i];
                vetorCadeira[i] = nullptr;
            }
        }

    std::string reservar(std::string nome, std::string telefone, int cadeira){

        if(vetorCadeira[cadeira] != nullptr){
            return "Cadeira ocupada";
        }
        if(!(cadeira > -1 && cadeira < vetorCadeira.size())){
            return "Cadeira nao existe";
        }
        //laço para ver se cliente ja esta cadastrado
        for(int i = 0; i < vetorCadeira.size(); i++){
            if(vetorCadeira[i] != nullptr){
                if(vetorCadeira[i]->getNome() == nome){
                    return "Cliente ja cadastrado";
                }
            }
        }
        if(vetorCadeira[cadeira] == nullptr){
            Cliente* cliente = new Cliente(nome, telefone);
            vetorCadeira[cadeira] = cliente;
            return "Reserva feita com sucesso";
        }

    }

    std::string cancelar(std::string nome){
        for(int i = 0; i < (int) vetorCadeira.size(); i++){
            if(vetorCadeira[i] != nullptr){
                if(vetorCadeira[i]->getNome() == nome){
                    delete vetorCadeira[i];
                    vetorCadeira[i] = nullptr;
                    return "Reserva cancelada com sucesso";
                }
            }
        }
        return "Cliente não possui cadeira no seu nome";
    }
    
    std::string toString(){
        std::stringstream ss;
        ss<<"[";
        for(int i = 0; i < (int) vetorCadeira.size(); i++){
            ss<<" ";
            if(vetorCadeira[i] != nullptr){
                ss << vetorCadeira[i]->toString();
            }else{
                ss << "-";
            }
        }
            ss<<" ]";

        return ss.str();
    }

};

class Controlador{
    private:
        Sala sala;
    
    public:
        void iniciar(int cadeiras){
            while (true){
                std::string comando;
                std::cin >> comando;
                if(comando == "init"){
                    int qntdcadeiras;
                    std::cin>>qntdcadeiras;
                    sala = Sala{qntdcadeiras};
                }else if(comando == "show"){
                    std::cout<<sala.toString()<<std::endl;
                }else if(comando == "reservar"){
                    std::string nome, telefone;
                    int cadeira;
                    std::cin >> nome >> telefone >> cadeira;
                    std::cout << sala.reservar(nome, telefone, cadeira) << std::endl;
                }else if(comando == "cancelar"){
                    std::string nome;
                    std::cin >> nome;
                    std::cout << sala.cancelar(nome) << std::endl;
                }else if(comando == "fim"){
                    break;
                }else{
                    std::cout << "Comando invalido" << std::endl;
                }
            }            
        }
};

int main(){
    Controlador c;
    c.iniciar(10);
    return 0;
}

