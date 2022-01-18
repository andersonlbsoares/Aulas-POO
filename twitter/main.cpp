#include <iostream>
#include <string>
#include <map>
#include <vector>

//foward declaration
class User {
friend class Inbox;
friend class Controller;

public:
    std::string username;
    std::map<std::string, User*> following;
    std::map<std::string, User*> followers;
    User(std::string username) {
        this->username = username;
    }

    void follow(User* user) {
        following[user->getUsername()] = user;
        user->followers[this->getUsername()] = this;
    }

    void unfollow(User* user) {
        following.erase(user->getUsername());
        user->followers.erase(this->getUsername());
    }

    std::string getUsername() {
        return username;
    }

    //print followers and following
    void printFF() {
        std::cout <<  username << ":" << std::endl;
        std::cout << "followers [ ";
        for (auto it = followers.begin(); it != followers.end(); ++it) {
                std::cout << it->first<<" ";
        }
        std::cout << "]" << std::endl;  

        std::cout << "following [ ";
        for (auto it = following.begin(); it != following.end(); ++it) {
            std::cout << it->first<<" ";
        }
        std::cout << "]" << std::endl << std::endl;
    }
    
};

class Message{
friend class Inbox;
friend class Controller;
private:
    int id;
    std::string msg;
    std::string username;
    std::vector<std::string> likes;
public:
    Message(int id, std::string msg, std::string username) {
        this->id = id;
        this->msg = msg;
        this->username = username;
    }

    std::string getMsg() {
        return msg;
    }
    int getId() {
        return id;
    }
    std::string getUsername() {
        return username;
    }

    std::vector<std::string> &getLikes() {
        return likes;
    }
};

class Inbox{

friend class Controller;
friend class User;
std::map<int, Message*> messages;

public:

    void showMessages() {
       
    }

    void like(std::string username, int id) {
        for (auto it = messages.begin(); it != messages.end(); ++it) {
            if (it->first == id) {
                it->second->likes.push_back(username);
            }
        }
    }

    void addMessage(Message* msg) {
        int aux = messages.size() + 1;
        messages[aux] = msg;
    }

    void printMessages() {
        for (auto it = messages.begin(); it != messages.end(); ++it) {
            std::cout << it->first << ": " << it->second->getUsername() << "(" << it->second->getMsg() << ")" << std::endl;
        }
    }


    void printTimeline(std::string username){
        //mostra mensagens usuario e curtidas
        for (auto it = messages.begin(); it != messages.end(); ++it) {
            if (it->second->getUsername() == username) {
                std::cout << it->first << ": " << it->second->getUsername() << "(" << it->second->getMsg() << ")" << std::endl;
                std::cout << "likes: ";
                for (auto it2 = it->second->getLikes().begin(); it2 != it->second->getLikes().end(); ++it2) {
                    std::cout << *it2 << " ";
                }
                std::cout << std::endl;
            }
        }
        // for (auto it = messages.begin(); it != messages.end(); ++it) {
        //     if (it->second.getUsername() == username) {
        //         std::cout << it->first << ": " << it->second.getUsername() << "(" << it->second.getMsg() << ")" << std::endl;
        //     }
        // }
    }
};
Inbox auxinbox;

class Controller {
friend class User;
friend class Message;
friend class Inbox;
public:
    std::map<std::string, User*> users;
    void addUser(std::string username) {
        if(users.find(username) == users.end()) {
            users[username] = new User(username);
        }
    }

    std::map<std::string, User*> getFollowings(std::string username) {
        return users[username]->following;
    }

    User *getUser(std::string username) {
        return users[username];
    }

    void print(){
        for (auto it = users.begin(); it != users.end(); ++it) {
            it->second->printFF();
        }
    }


    void tweetar(std::string username, std::string msg) {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if(it->first == username) {
                int aux = 0;

                Message* m = new Message(aux, msg, username);
                auxinbox.addMessage(m);
            }
        }
    }
    
    void timeline(std::string username){
        auxinbox.printTimeline(username);       
    
    }
    void showalltweets(){
        auxinbox.printMessages();
    }
};

int main(){
    Controller c;
    while(true){
        std::string command;
        std::cin >> command;
        if(command == "add"){
            std::string username;
            std::cin >> username;
            c.addUser(username);
        }
        else if(command == "follow"){
            std::string username1, username2;
            std::cin >> username1 >> username2;
            User *user1 = c.getUser(username1);
            User *user2 = c.getUser(username2);
            user1->follow(user2);
        }
        else if(command == "unfollow"){
            std::string username1, username2;
            std::cin >> username1 >> username2;
            User *user1 = c.getUser(username1);
            User *user2 = c.getUser(username2);
            user1->unfollow(user2);
        }
        else if(command == "print"){
            c.print();
        }
        else if(command=="tweetar"){
            std::string username, msg;
            std::cin >> username >> msg;
            c.tweetar(username, msg);
        }
        else if(command =="tweets"){
            c.showalltweets();
        }
        else if(command == "timeline"){
            std::string username;
            std::cin >> username;
            std::map<std::string, User*> followings = c.getFollowings(username);
            for (auto it = followings.begin(); it != followings.end(); ++it) {
                c.timeline(it->first);

            }
        }else if(command =="like"){
            std::string username;
            int id;
            std::cin >> username >> id;
            auxinbox.like(username, id);
        }
        else if(command == "exit"){
            break;
        }
     
    }



}