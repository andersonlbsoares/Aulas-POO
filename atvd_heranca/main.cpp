#include <iostream>
#include <sstream>

class Camera{
    protected:
        int bateria;
        int megaPixels;
        Camera(int bateria, int megaPixels) : bateria(bateria), megaPixels(megaPixels){}
    public:
        Camera(){
            std::cout << "Camera criada" << std::endl;
        }
        
        void setBateria(int bateria){
            this->bateria = bateria;
        }
      
        void setMegaPixels(int megaPixels){
            this->megaPixels = megaPixels;
        }
        
        virtual int getBateria(){
            return this->bateria;
        }
  
        int getMegaPixels(){
            return this->megaPixels;
        }

        virtual void gastarBateria(){
            this->bateria -= 1;
            std::cout << "Bateria: " << this->bateria << std::endl;
        }
};


class camera_pequena : public Camera{
    private:
        bool portabilidade;
    public:
        //construtor completo da classe
        camera_pequena(int bateria, int megaPixels, bool portabilidade) : Camera{bateria, megaPixels}, portabilidade{portabilidade}{
            std::cout << "Camera pequena criada" << std::endl;
        }
        

        bool getPortabilidade(){
            return this->portabilidade;
        }

        void setPortabilidade(bool portabilidade){
            this->portabilidade = portabilidade;
        }
};

class webcam : public camera_pequena{
    public:
        webcam(int megaPixels) : camera_pequena{-1, megaPixels, true}{
            std::cout << "Webcam criada" << std::endl;
        }

        int getBateria()override{
            std::cout << "Webcam n tem bateria" << std::endl;
            return 0;
        }

        void gastarBateria()override{
            std::cout << "Webcam n tem bateria" << std::endl;
        }
};

int main(){
    camera_pequena c{-1, -1, false};
    webcam w{-1};

    while(true){
        std::stringstream ss;
        std::string input;
        std::getline(std::cin, input);
        ss << input;
        std::string comando;
        ss >> comando;
        //sem id
        if(comando == "criar"){
            std::string tipo;
            ss >> tipo;
            if(tipo == "camera_pequena"){
                int bateria, megaPixels;
                ss >> bateria >> megaPixels;
                //seta os atributos
                c.setBateria(bateria);
                c.setMegaPixels(megaPixels);
                c.setPortabilidade(true);

                std::cout << "Camera criada" << std::endl;
            }
            else if(tipo == "webcam"){
                int megaPixels;
                ss >> megaPixels;
                w.setMegaPixels(megaPixels);
                std::cout << "Webcam criada" << std::endl;
            }
            else{
                std::cout << "Tipo de camera n existe" << std::endl;
            }
        }
        else if(comando == "gastar_bateria"){
            std::string tipo;
            ss >> tipo;
            if(tipo == "camera_pequena"){
                if(c.getBateria() == -1 && c.getMegaPixels() == -1){
                    std::cout << "Camera n criada" << std::endl;
                }
                else{
                    c.gastarBateria();
                }
            }
            else if(tipo == "webcam"){
                int megaPixels;
                ss >> megaPixels;
                webcam w{megaPixels};
                w.gastarBateria();
            }
            else{
                std::cout << "Tipo de camera n existe" << std::endl;
            }
        }
    }
}