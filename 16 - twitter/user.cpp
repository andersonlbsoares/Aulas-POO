#include "user.h"
#include <sstream>

User::User(std::string username){
    this->username = username;
}

std::string User::toString(){
    std::stringstream ss;
    ss << "User: " << this->username << "\n";
    //mostra todos os seguidores
    ss << "Followers [";
    for(auto it = this->followers.begin(); it != this->followers.end(); it++){
        if(it == this->followers.begin()){
            ss << it->first;
        }else{
            ss << ", " << it->first;
        }
    }
    ss << "]\n";
    ss<< "Following [";
    for(auto it2 = this->following.begin(); it2 != this->following.end(); it2++){
        if(it2 == this->following.begin()){
            ss << it2->first;
        }else{
            ss << ", " << it2->first;
        }
    }
    ss << "]\n";

    return ss.str();
}

void User::follow(User* other){
    if(following.find(other->username) == following.end()){
        following[other->username] = other;
        other->followers[this->username] = this;
    }else{
        throw std::invalid_argument("Você já está seguindo esse usuário");
    }
}

Inbox& User::getInbox(){
    return this->inbox;
}

void User::sendTweet(Tweet* tweet){
    this->inbox.storeInTimeline(tweet);
}

void User::sendMyTweets(Tweet* tweet){
    this->inbox.storeInMyTweets(tweet);
}

void User::unfollow(User* other){
    if(following.find(other->username) != following.end()){
        following.erase(other->username);
        other->followers.erase(this->username);
    }else{
        throw std::invalid_argument("Você não está seguindo esse usuário");
    }
}

void User::like(Tweet *tweet){
    tweet->like(username);
}

void User::unfollowAll(){
    for(auto it = this->following.begin(); it != this->following.end(); it++){
        it->second->followers.erase(this->username);
    }
    this->following.clear();
}

void User::rejectAll(){
    for(auto it = this->followers.begin(); it != this->followers.end(); it++){
        it->second->following.erase(this->username);
    }
    this->followers.clear();
}

std::string User::getUsername(){
    return this->username;
}

std::map<std::string, User*> User::getFollowers(){
    return this->followers;
}

std::map<std::string, User*> User::getFollowing(){
    return this->following;
}