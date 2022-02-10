#include <iostream>
#include "controller.h"

int main(){
    Controller controller;
    while(true){
        std::string command;
        std::cin >> command;
        try{
            if(command == "add"){
                std::string username;
                std::cin >> username;
                controller.addUser(username);   
            }else if(command == "follow"){
                std::string username, username2;
                std::cin >> username >> username2;
                controller.getUser(username)->follow(controller.getUser(username2));
            }else if(command == "unfollow"){
                std::string username, username2;
                std::cin >> username >> username2;
                controller.getUser(username)->unfollow(controller.getUser(username2));
            }else if(command == "twittar"){
                std::string username, msg;
                std::cin >> username;
                getline(std::cin, msg);
                controller.sendTweet(username, msg);
            }else if(command == "timeline"){
                std::string username;
                std::cin >> username;
                std::cout << controller.getMytweets(username) << std::endl;
                std::cout << controller.getTimeline(username) << std::endl;
            }else if(command == "like"){
                std::string username;
                std::cin >> username;
                int idTw;
                std::cin >> idTw;
                controller.getUser(username)->like(controller.getTweet(idTw));
            }else if(command == "rt"){
                std::string username;
                std::cin >> username;
                int idTw;
                std::cin >> idTw;
                std::string msg;
                getline(std::cin, msg);
                controller.sendRt(username, idTw, msg);
            }else if(command == "rm"){
                std::string username;
                std::cin >> username;
                controller.rmUser(username);
            }else if(command == "show"){
                std::cout << controller.toString() << std::endl;
            }else if(command == "end"){
                break;
            }else{
                std::cout << "Comando invalido" << std::endl;
            }
        }catch(std::invalid_argument& e){
                std::cout << e.what() << std::endl;
        }
    }
    return 0;
}   