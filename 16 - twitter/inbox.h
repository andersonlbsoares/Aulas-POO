#ifndef INBOX_H
#define INBOX_H

#include <iostream>
#include <map>
#include "tweet.h"
class Inbox{
private:
    std::map<int, Tweet*> timeline;
    std::map<int, Tweet*> myTweets;
public:
    //twittar
    void storeInTimeline(Tweet* tweet);
    std::map<int, Tweet*> getTimeline();
    std::string toString();

    //like
    Tweet* getTweet(int idTw);

    //unfollow
    void rmMsgsFrom(std::string username);

    //remover
    void storeInMyTweets(Tweet* tweet);
    std::map<int, Tweet*> getMyTweets();
};

#endif