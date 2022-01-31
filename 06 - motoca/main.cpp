#include <iostream>
#include <sstream>

struct Pessoa {
    std::string nome;
    int idade;

    Pessoa(std::string nome="", int idade=0) {
        this->nome = nome;
        this->idade = idade;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa) {
        os << "Nome: " << pessoa.nome << " Idade: " << pessoa.idade;
        return os;
    }
};

struct Motinha{
    Pessoa * pessoa{nullptr};
    int tempo{0};
    int potencia{1};
    Motinha(int pot) : potencia{pot}{}

    bool inserirPessoa(Pessoa * p){
        if(pessoa != nullptr){
            std::cout << "Pessoa ja inserida" << std::endl;
            return false;
        }else{
            this->pessoa = p;
            return true;
        }
    }

    std::string buzinar(){
        return "R" + std::string(this->potencia, 'o') + "nc";
    }

    Pessoa * removerpessoa(){
        Pessoa * p = this->pessoa;
        this->pessoa = nullptr;
        return p;
    }

    void addTempo(int tempo){
        this->tempo += tempo;
    }

    bool dirigir(int tempo){
        if(this->pessoa == nullptr){
            std::cout << "Não possui motorista" << std::endl;
            return false;
        }if(tempo > this->tempo){
            std::cout << "Só consigo dirigir " << this->tempo << " minutos" << std::endl;
            this->tempo = 0;
            return true;
        }
            std::cout << "Dirigiu " << this->tempo << " minutos" << std::endl;
            this->tempo =this->tempo - tempo;
            return true;
        
    }

    friend std::ostream& operator<<(std::ostream& os, const Motinha& motinha) {
        os << " Tempo: " << motinha.tempo << " Potencia: " << motinha.potencia;
        os << (motinha.pessoa == nullptr ? " [vazio]" : motinha.pessoa->nome)<< std::endl;
        return os;
    }

};


int main(){
    Motinha motinha(1);
    while(true){
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if(cmd == "init"){
            int pot = 0;
            ss >> pot;
            std::cout<< "Iniciando motinha com potencia " << pot << std::endl;
            motinha = Motinha(pot);
        }else if(cmd == "show"){
            std::cout << motinha << std::endl;
        }else if(cmd == "inserir"){
            std::string nome;
            int idade;
            ss >> nome >> idade;
            Pessoa * p = new Pessoa(nome, idade);
            if(!motinha.inserirPessoa(p)) delete p;                        
        }else if(cmd == "retirar"){
            Pessoa * p = motinha.removerpessoa();
            if(p != nullptr){
                std::cout << "Retirou " << *p << std::endl;
                delete p;
            }else{
                std::cout << "Não possui motorista" << std::endl;
            } 
        }else if(cmd == "end"){
            break;
        }else{
            std::cout<< "Comando invalido" << std::endl;
        }
    }
    return 0;
}