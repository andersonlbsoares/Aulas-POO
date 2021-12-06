#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

class Fone{
    private:
        std::string numero;
        std::string id;
    public:
        Fone(std::string numero ="", std::string id=""){
            this->numero = numero;
            this->id = id;
        }
        bool isvalid(std::string numero){
            std::string validado = "0123456789()-.";
            for(char c : numero){
                if(validado.find(c) == std::string::npos){
                    return false;
                }
            }
            return true;
        }
        void setId(std::string id){
            this->id = id;
        }
        
        std::string getId(){
            return this->id;
        }
       
        void setNumero(std::string numero){
            if(isvalid(numero)){
                this->numero = numero;
            }
        }

        std::string getNumero(){
            return this->numero;
        }

};

class Contato{
    private:
        std::string prefix="->";
        std::string nome;
    public:
        std::vector<Fone> fones;
        
        Contato(std::string nome=""){
            this->nome = nome;
        }
        bool addFone(Fone fone){
            for(Fone &f : fones){
                if(f.getNumero() == fone.getNumero()){
                    return false;
                }
            }
            this->fones.push_back(fone);
            return true;
        }
      
        void rmFone(int index){
            this->fones.erase(this->fones.begin()+index);
        }

        void setNome(std::string nome){
            this->nome = nome;
        }

        std::string getNome(){
            return this->nome;
        }

        std::string getFones(){
            std::stringstream ss;
            for(int i=0; i<(int)fones.size(); i++){
                ss << this->prefix << this->fones[i].getNumero() << std::endl;
            }
            return ss.str();
        }
        
        std::string toString(){
            std::stringstream ss;
            ss << prefix << " " <<this->nome << std::endl;
            for(int i=0; i<(int)fones.size(); i++){
                ss << i << " - " << "[ " << fones[i].getId() << " : " << fones[i].getNumero() << " ]" << std::endl;
            }
            return ss.str();
        }
};

class Agenda{
    private:
        std::map<std::string, Contato*> contatos;
    public:

        bool addContato(Contato& contato){
            Contato* contatoNovo = contatos[contato.getNome()];
            if(contatoNovo == nullptr){
                contatos[contato.getNome()] = &contato;
                return true;
            }
            return false;
        }
        
        bool rmContato(std::string nome){
            return this->contatos.erase(nome);
        }
        
        void searchContato(std::string nome){
            bool encontrado = false;
            for(auto& c : this->contatos){
                if(c.first.find(nome) != std::string::npos || c.second->getFones().find(nome) != std::string::npos){
                    std::cout << c.second->toString() << std::endl;
                    encontrado = true;
                }
            }
            if(!encontrado){
                std::cout << "Nenhum contato encontrado" << std::endl;
            }

        }
        
        Contato* getFirstContato(std::string nome){
            return contatos.begin()->second;
        }

        int size(){
            return this->contatos.size();
        }
        
        std::string toString(){
            std::stringstream ss;
            ss << "Agenda: " << std::endl;
            for(auto it = contatos.begin(); it != contatos.end(); it++){
                ss << it->second->toString() << std::endl;
            }
            return ss.str();
        }

        Contato* getContato(std::string nome){
            return contatos[nome];
        }
};

int main(){
    Contato* contatoatual = nullptr;
    Agenda agenda;
    Fone fone;
    bool vazio = true;
    
    while(true){
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        std::string cmd;
        ss >> cmd;
        if(cmd == "add"){
            std::string nome;
            std::string id;
            std::string numero;
            ss >> nome >> numero >> id;
            Contato* aux = new Contato(nome);
            if(fone.isvalid(numero)){
                if(agenda.addContato(*aux)){
                    contatoatual = aux;
                }else{
                    contatoatual = agenda.getContato(nome);
                }
                fone = Fone(numero, id);
                if(contatoatual->addFone(fone)){
                    std::cout << "Fone adicionado com sucesso" << std::endl;
                    vazio = false;
                }else{
                    std::cout << "Fone ja existente" << std::endl;
                }
                std::cout << contatoatual->toString() << std::endl;
            }else{
                std::cout << "Numero invalido" << std::endl;
            }

        }else if(cmd == "rm" && vazio == false){
            std::string nome;
            Contato* aux;
            int index;
            ss >> nome >> index;
            aux = agenda.getContato(nome);
            if(aux != nullptr){
                contatoatual = aux;
                contatoatual->rmFone(index);
                std::cout << contatoatual->toString() << std::endl;
            }else{
                std::cout << "Contato nao encontrado" << std::endl;
            }

        }else if(cmd == "deletar" && vazio == false){
            std::string nome;
            ss >> nome;
            if(agenda.rmContato(nome)){
                std::cout << "Contato deletado com sucesso" << std::endl;
                contatoatual = agenda.getFirstContato(nome);
            
            }else{
                std::cout << "Contato nao encontrado" << std::endl;
            }

            if(agenda.size()== 0){
                contatoatual = nullptr;
                std::cout << "Agenda vazia" << std::endl;
            }            

        
        }else if(cmd == "search" && vazio == false){
            std::string nome;
            ss >> nome;
            agenda.searchContato(nome);
        }else if(cmd == "show"){
            std::cout << agenda.toString() << std::endl;
        }else if(cmd == "exit"){
            break;
        }else{
            std::cout << "Comando invalido" << std::endl;
        }
    }
};