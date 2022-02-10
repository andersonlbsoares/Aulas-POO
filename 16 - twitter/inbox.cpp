#include "inbox.h"
#include <sstream>

void Inbox::storeInTimeline(Tweet* tweet){ //adiciona um tweet na timeline
    this->timeline[tweet->getId()] = tweet;
}

std::map<int, Tweet*> Inbox::getTimeline(){
    return this->timeline;
}

std::string Inbox::toString(){ //retorna todos os tweets da timeline
    std::stringstream ss;
    ss<<"\n";
    for(auto it = this->myTweets.begin(); it != this->myTweets.end(); it++){
        if(it->second->isDeleted()==false){
            ss << it->second->toString() << std::endl;
        }
    }
    for(auto it = this->timeline.begin(); it != this->timeline.end(); it++){
        if(it->second->isDeleted()==false){
            ss << it->second->toString() << std::endl;
        }
    }
    return ss.str();
}

Tweet* Inbox::getTweet(int idTw){ //retorna um tweet especifico da timeline pelo id
    return this->timeline[idTw];
}

void Inbox::rmMsgsFrom(std::string username){ //remove todos os tweets de um usuário

    for(auto it = this->timeline.begin(); it != this->timeline.end(); it++){
        if(it->second->getSender() == username){
            it->second->setDeleted();
        }
    }
}

void Inbox::storeInMyTweets(Tweet* tweet){ //adiciona um tweet no map de tweets do usuário
    this->myTweets[tweet->getId()] = tweet;
}

std::map<int, Tweet*> Inbox::getMyTweets(){ //retorna todos os tweets do usuário
    return this->myTweets;
}