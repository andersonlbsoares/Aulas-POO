#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>

#include "tweet.h"
#include "inbox.h"
#include "user.h"

class Controller{
private:
    int nextTweetId;
    std::map<std::string, User*> users;
    std::map<int, Tweet*> tweets;
public:
    //constructor
    Controller();
    void addUser(std::string username);
    std::string toString();

    //twittar
    Tweet* createTweet(std::string sender, std::string msg);
    User* getUser(std::string username);
    void sendTweet(std::string username, std::string msg);

    //retweet
    void sendRt(std::string username, int idTw, std::string msg);

    //remover
    void rmUser(std::string username);

    std::string getTimeline(std::string username);
    std::string getMytweets(std::string username);
    Tweet* getTweet(int idTw);
};

#endif