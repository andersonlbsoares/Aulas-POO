#ifndef TWEEET_H
#define TWEEET_H

#include <iostream>
#include <sstream>
#include <map>
#include <set>

class Tweet{
private:
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    Tweet* rt;
    bool deleted;
public:
    //constructor
    Tweet(int id, std::string username, std::string msg);
    int getId();
    std::string getSender();
    std::string getMsg();
    std::string toString(); 

    //like
    void like(std::string username);
    std::set<std::string> getLikes();

    //retweet
    void setRt(Tweet* tw);

    //remover
    void setDeleted();
    bool isDeleted();

};

#endif 