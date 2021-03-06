#include <SFML/Graphics.hpp>
#include <iostream>

void setSize(sf::Sprite& sprite, int width, int height){
    auto dim = sprite.getLocalBounds();
    sprite.setScale((float) width / dim.width, (float) height / dim.height);
}

struct Entity{
    int x {0};
    int y {0};
    int step {0};
    sf::Sprite sprite;

    Entity(int x, int y, int step, sf::Texture& texture):
        x{x}, y{y}, step{step}, sprite(texture){ 
        }
    
    

    void draw(sf::RenderWindow& window){
        this->sprite.setPosition(x*step, y*step);
        window.draw(this->sprite);
    }
};

struct Board {
    int nc {0};
    int nl {0};
    int step {0};
    sf::Sprite sprite;
    sf::RectangleShape rect;

    Board(int nc, int nl, int step, sf::Texture& texture) {
        this->nc = nc;
        this->nl = nl;
        this->step = step;
        this->sprite.setTexture(texture);
        setSize(this->sprite, nc * step, nl * step);
        this->sprite.setPosition(0, 0);

        // this->rect.setSize(sf::Vector2f(step, step));
        // this->rect.setFillColor(sf::Color::Transparent);
        // this->rect.setOutlineColor(sf::Color::Black);
        // this->rect.setOutlineThickness(2);
    }
    void draw(sf::RenderWindow& window) {
        window.draw(this->sprite);
        for (int i = 0; i < nc; i++) {
            for (int j = 0; j < nl; j++) {
                rect.setPosition(i * step, j * step);
                window.draw(rect);
            }
        }
    }
};


void moveEntity(sf::Keyboard::Key key, Entity& entity, std::vector<sf::Keyboard::Key> move_keys) {
    if (key == move_keys[0]) entity.x--;
    else if (key == move_keys[1]) entity.y--;
    else if (key == move_keys[2]) entity.x++;
    else if (key == move_keys[3]) entity.y++;
}

sf::Texture loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "Error loading texture" << std::endl;
        exit(1);
    }
    return texture;
}


int main(){

    sf::Texture omar_texture { loadTexture("omar.jpg") };
    sf::Texture bolsonaro_texture { loadTexture("bolsonaro.jpg") };
    sf::Texture fundo_texture { loadTexture("fundo.jpg") };

    const int step{100}; 

    Entity omar(0,0,step,omar_texture);
    Entity bolsonaro(1,1,step,bolsonaro_texture);
    Board board(7,5,step, fundo_texture);

    sf::RenderWindow window(sf::VideoMode(board.nc*step,board.nl*step), "Ta funcionado :D");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else if (event.type == sf::Event::KeyPressed) {
                moveEntity(event.key.code, omar, {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down});
                moveEntity(event.key.code, bolsonaro, {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S});
            }
        }
        window.clear();
        board.draw(window);
        omar.draw(window);
        bolsonaro.draw(window);
        window.display();
    }
    


    return 0;
}