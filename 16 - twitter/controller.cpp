#include "controller.h"

Controller::Controller(){
    this->nextTweetId = 0;
    this->users = std::map<std::string, User*>();
    this->tweets = std::map<int, Tweet*>();
}

void Controller::addUser(std::string username){ //adiciona um usuário caso não exista
    if(users.find(username) == users.end()){
        users[username] = new User(username);
    }else{
        throw std::invalid_argument("Nome de usuario ja existe");        
    }
}

std::string Controller::toString(){ //retorna todos os usuários e seus respectivos tweets
    std::stringstream ss;
    for(auto it = users.begin(); it != users.end(); it++){
        ss << it->second->toString() << std::endl;
    }
    return ss.str();
}

Tweet* Controller::createTweet(std::string sender, std::string msg){ //cria um tweet, mas não o envia
    if(users.find(sender) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }
    Tweet* tweet = new Tweet(nextTweetId, sender, msg);
    tweets[nextTweetId] = tweet;
    nextTweetId++;
    return tweet;
}

User* Controller::getUser(std::string username){ //retorna um usuário
    if(users.find(username) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }
    return users[username];
}

void Controller::sendTweet(std::string username, std::string msg){ //envia um tweet
    Tweet* tweet = createTweet(username, msg);
    User* user = users[username]; 
    user->sendMyTweets(tweet);
    

    for(auto &it : users){
        if(it.first != username){
            it.second->sendTweet(tweet);
        }
    }
}

void Controller::sendRt(std::string username, int idTw, std::string msg){ //cria um retweet
    if(users.find(username) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }
    if(tweets.find(idTw) == tweets.end()){
        throw std::invalid_argument("Tweet nao existe");
    }
    Tweet* tweet = tweets[idTw];
    User* user = users[username]; 
    Tweet* tweet_rt = new Tweet(nextTweetId, username, msg);
    tweet_rt->setRt(tweet);
    nextTweetId++;
    //invoca o sendTweet da classe controller
    user->sendMyTweets(tweet_rt);
    for(auto &it : users){
        if(it.first != username){
            it.second->sendTweet(tweet_rt);
        }
    }
}

void Controller::rmUser(std::string username){ //remove um usuário e todos os seus tweets 
    if(users.find(username) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }else{
        for(auto &it : users){
            if(it.first != username){
                Inbox& inbox = users[it.first]->getInbox();
                inbox.rmMsgsFrom(username);
            }
        }
        users[username]->unfollowAll();
        users[username]->rejectAll();
        users.erase(username);
    }
}

std::string Controller::getTimeline(std::string username){
    if(users.find(username) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }
    User* user = users[username];
    Inbox& inbox = user->getInbox();
    std::map<int, Tweet*> timeline = inbox.getTimeline();
    
    std::stringstream ss;
    for(auto it = timeline.begin(); it != timeline.end(); it++){
        ss << it->second->toString() << std::endl;
    }
    return ss.str();
}

std::string Controller::getMytweets(std::string username){
    if(users.find(username) == users.end()){
        throw std::invalid_argument("Usuario nao existe");
    }
    User* user = users[username];
    //chama o getTimeline do inbox
    Inbox& inbox = user->getInbox();
    std::map<int, Tweet*> myTweets = inbox.getMyTweets();
    
    std::stringstream ss;
    for(auto it = myTweets.begin(); it != myTweets.end(); it++){
        ss << it->second->toString() << std::endl;
    }
    return ss.str();
}

Tweet* Controller::getTweet(int idTw){
    if(tweets.find(idTw) == tweets.end()){
        throw std::invalid_argument("Tweet nao existe");
    }
    return tweets[idTw];
}