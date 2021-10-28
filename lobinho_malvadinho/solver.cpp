#include <SFML/Graphics.cpp>
#include <iostream>

function ksf {
    g++ -Wall -Wextra -Werror -c $1.cpp && g++ $1.o -o $1-app -lsfml-graphics -lsfml-window -lsfml-system && ./$1-app
}

int main(){

}