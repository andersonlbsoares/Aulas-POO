#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Fone{
    std::string id;
    std::string number;

public:
    Fone(std::string id="VAZIO", std::string number="VAZIO"){
        this->id = id;
        this->number = number;
    }

    //verificar se tem letra
    bool verificar(std::string number){
        for(int i = 0; i < (int)number.size(); i++){
            if(number[i] >= '0' || number[i] <= '9' || number[i] == '.' || number[i] == '(' || number[i] == ')'){
                return true;
            }
        }
        return false;
    }
    std::string getId(){
        return this->id;
    };

    std::string getNumber(){
        return this->number;
    };

    void setId(std::string id){
        this->id = id;
    };

    void setNumber(std::string number){
        this->number = number;
    };

    std::string toString(){
    }
    
};

class Contact{
    std::string prefix = "-";
    std::vector<Fone> fones;
    std::string name;

public:
    Contact(std::string name = ""){
        this->name = name;
    }

    void addFone(Fone fone){
        fones.push_back(fone);
    }
    // remover por indice
    void rmvFone(int index){
        fones.erase(fones.begin() + index);
    }

    //tostring
    std::string toString(){
        std::stringstream str;
        str << prefix << " " << this->name << "\n";
        for(int i = 0; i < fones.size(); i++){
            str << "[" << i << " : " << fones[i].getId() << " : " << fones[i].getNumber() << "]\n";
        }
        return str.str();
    }

    std::string getName(){
        return this->name;
    }

    void setName(std::string name){
        this->name = name;
    }
};

int main(){
    Contact c;
    Fone f;
    while(true){
        std::string str;
        std::cin >> str;
        if(str == "init"){
            std::string name;
            std::cin >> name;
            c = Contact(name);

        }else if(str == "add"){
            std::string id;
            std::string number;
            std::cin >> id >> number;
            if(f.verificar(number)){
                f = Fone(id, number);
                c.addFone(f);
            }else{
                std::cout << "Numero invalido" << std::endl;
            }
        }else if(str == "rmv"){
            int indice;
            std::cin >> indice;
            c.rmvFone(indice);
        }else if(str == "show"){
            std::cout << c.toString() << std::endl;
        }else if(str == "end"){
            break;
        }else{
            std::cout << "Comando invalido" << std::endl;
        }

    }
}