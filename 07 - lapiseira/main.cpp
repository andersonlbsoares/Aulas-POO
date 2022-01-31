#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza ="", int tamanho = 0) : 
    calibre{calibre}, dureza{dureza}, tamanho{tamanho} {}    

    friend std::ostream& operator<<(std::ostream& os, const Grafite& grafite) {
        os << "Calibre: " << grafite.calibre << "mm, "; 
        os << " Dureza: " << grafite.dureza << ", ";
        os << " Tamanho: " << grafite.tamanho << "mm\n";
        return os;
    }

};

struct Lapiseira{
    float calibre;
    Grafite* grafite;

    Lapiseira(float calibre, Grafite* grafite = nullptr) :
    calibre{calibre}, grafite{grafite} {}


    bool inserirGrafite(Grafite* grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Lapiseira ja possui grafite\n";
            return false;
        }
        if(grafite->calibre > this->calibre) {
            std::cout << "Grafite nao pode ser inserido\n";
            return false;
        }
        this->grafite = grafite;        
    }

    Grafite* retirarGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Lapiseira nao possui grafite\n";
            return nullptr;
        }
        return std::exchange(this->grafite, nullptr);
    }
};




int main(){
    Grafite grafite(0.5, "HB", 10);

    Lapiseira lapiseira(0.5, &grafite);
    lapiseira.grafite->tamanho -= 2;

    std::cout << grafite.tamanho << std::endl;
    std::cout << lapiseira.grafite->tamanho << std::endl;

    return 0;
}