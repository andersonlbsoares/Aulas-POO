#ifndef USER_H
#define USER_H

#include "inbox.h"
#include "tweet.h"
#include <iostream>
#include <map>

class User{
private:
    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;
public:
    
    //constructor
    User(std::string username);
    std::string toString();

    //follow
    void follow(User* other);
    
    //twittar
    Inbox& getInbox();
    void sendTweet(Tweet* tweet);
    void sendMyTweets(Tweet* tweet);

    //unfollow
    void unfollow(User* other);

    //like
    void like(Tweet* tweet);

    //remover
    void unfollowAll();
    void rejectAll();

    //getters
    std::string getUsername();
    std::map<std::string, User*> getFollowers();
    std::map<std::string, User*> getFollowing();

};

#endif