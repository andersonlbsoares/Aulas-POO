#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

struct Pencil{
  sf::Font font;
  sf::Text text;
  sf::RenderWindow& window;

    Pencil(sf::RenderWindow& window) : window { window }{
        if(!font.loadFromFile("Wolfskin.ttf")){
        std::cout << "Nao deu bom\n";
        }
        text.setFont(font);
    }

    void escrever(std::string str, int x, int y, int size, sf::Color color){
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};


struct Pencilfinal{
  sf::Font font;
  sf::Text text;
  sf::RenderWindow& window;

    Pencilfinal(sf::RenderWindow& window) : window { window }{
        if(!font.loadFromFile("satan.ttf")){
        std::cout << "Nao deu bom\n";
        }
        text.setFont(font);
    }

    void escrever(std::string str, int x, int y, int size, sf::Color color){
        text.setString(str);
        text.setCharacterSize(size);
        text.setPosition(x, y);
        text.setFillColor(color);
        window.draw(text);
    }
};


struct Bubble{
    int x;
    int y;
    char letrinha;
    int velocidade;
    bool viva{true};

    static const int radius{20};

    Bubble(int x, int y, char letrinha, int velocidade) : x{x}, y{y}, letrinha{letrinha}, velocidade{velocidade}{}

    void update(){
        this->y += this->velocidade;
    }

    void desenhar(sf::RenderWindow& window){
        sf::CircleShape bubble(Bubble::radius);
        bubble.setPosition(x, y);
        bubble.setFillColor(sf::Color::White);
        window.draw(bubble);
        static Pencil pencil(window);
        pencil.escrever(std::string(1, letrinha), x+ 0.4 * Bubble::radius, y, Bubble::radius * 1.5, sf::Color::Blue);
    }
};

struct Board{
    std::vector<Bubble> bubbles;
    sf::RenderWindow& window;
    Pencil pencil;

    int ACERTOS{0};
    int PERDIDAS{0};

    Board(sf::RenderWindow& window) : window{window}, pencil{window} {
        bubbles.push_back(Bubble(100, 100, 'A', 1));
        bubbles.push_back(Bubble(200, 100, 'B', 2));
        bubbles.push_back(Bubble(300, 100, 'C', 3));
    }

    void update(){
        if(this->checarnovasbolinhas()){
            this->adicionarnovasbolinhas();
        }else{
            for(Bubble& bubble : bubbles){
            bubble.update();
        }
            this->bolinhasperdidas();
            this->removerbolinhasmortas();
        }
    }

    void adicionarnovasbolinhas(){
        int x = rand() % (this->window.getSize().x-2*Bubble::radius);
        int y = -2 * Bubble::radius;
        int velocidade = rand() % 7 + 3;
        char letrinha = rand() % 26 + 'A';
        bubbles.push_back(Bubble(x, y, letrinha, velocidade));
    }

    void bolinhasperdidas(){
        for(Bubble& bubble : bubbles){
            if(bubble.y + 2 * Bubble::radius > (int) this->window.getSize().y){
                if(bubble.viva){
                    bubble.viva = false;
                    this->PERDIDAS++;
                }
            }
        }
    }

    void acertos(char letrinha){
        for(Bubble& bubble : bubbles){
            if(bubble.viva){
                if(bubble.letrinha == letrinha){
                    bubble.viva = false;
                    this->ACERTOS++;
                    break;
                }
            }
        }
    }

    bool checarnovasbolinhas(){
        static const int newBubbleTimeout{30};
        static int newBubbleTimer{0};
        newBubbleTimer--;
        if(newBubbleTimer <= 0){
            newBubbleTimer = newBubbleTimeout;
            return true;
        }
        return false;
    }

    void removerbolinhasmortas(){
        std::vector<Bubble> bubblesviva;
        for(Bubble& bubble : bubbles){
            if(bubble.viva){
                bubblesviva.push_back(bubble);
            }
        }

        this->bubbles = bubblesviva;
    }

    void desenhar(){
        pencil.escrever("ACERTOS: " + std::to_string(this->ACERTOS) + " PERDIDAS: " + std::to_string(this->PERDIDAS), 10, 10, 30, sf::Color::White);
        pencil.escrever("Bolinhas na tela: " + std::to_string(this->bubbles.size()), 10, 40, 20, sf::Color::White);
        for(Bubble& bubble : bubbles){
        bubble.desenhar(window);
        }
    }
};

struct Game{
    sf::RenderWindow window;
    Board board;
    std::function<void()> onUpdate;

    Game() : window(sf::VideoMode(800, 600), "Bubbles"), board(window){
            this->onUpdate = [&](){
            this->jogar();
        };
        window.setFramerateLimit(30);
    }

    void checareventos(){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if(event.type == sf::Event::TextEntered){
                char code = static_cast<char>(event.text.unicode);
                code = toupper(code);
                board.acertos(code);
            }
        }
    }

    void jogar(){
        board.update();
        window.clear(sf::Color::Cyan);
        board.desenhar();
        window.display();
        if (board.PERDIDAS >= 5){
            this->onUpdate = [&](){
            this->gameover();
            };
        }
    }

    void gameover(){
        window.clear(sf::Color::Red);
        static Pencilfinal pencil(window);
        pencil.escrever("Morreu", 100, 70, 250, sf::Color::Black);
        window.display();
    }

    void loop_principal(){
        while (window.isOpen()){
            checareventos();
            this->onUpdate();
        }
    }
};

int main(){
    Game joguinho;
    joguinho.loop_principal();
    return 0;
}