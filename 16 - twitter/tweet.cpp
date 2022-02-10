#include "tweet.h"

Tweet::Tweet(int id, std::string username, std::string msg){
    this->id = id;
    this->username = username;
    this->msg = msg;
    this->likes = std::set<std::string>();
    this->rt = NULL;
    this->deleted = false;
}

int Tweet::getId(){
    return this->id;
}

std::string Tweet::getSender(){
    return this->username;
}

std::string Tweet::getMsg(){
    return this->msg;
}

std::string Tweet::toString(){ //timeline
    std::stringstream ss;
    if(this->rt == NULL && deleted == false){

        ss << this->id << " | " << this->username << " | -> " << this->msg;

        for(auto it = this->likes.begin(); it != this->likes.end(); it++){
            if(it == this->likes.begin()) ss << "(";
            if(it != this->likes.begin()){
                ss << ", "<< *it;
            }else{
                ss << *it << ")";;
            }
        }
        return ss.str();
    }else if(deleted == false){
        ss << this->id << " | " << this->username << " | -> " << this->msg;

        for(auto it = this->likes.begin(); it != this->likes.end(); it++){
            if(it == this->likes.begin()) ss << "(";
            if(it != this->likes.begin()){
                ss << ", "<< *it;
            }else{
                ss << *it << ")";;
            }
        }
        ss <<"\n\t";
        if(rt->deleted!=false){
            ss << "Esse tweet foi deletado";
        }else{
            ss << this->rt->toString();
        }
        return ss.str();       
    }else{
        return "";
    } 
}

void Tweet::like(std::string username){
    this->likes.insert(username);
}

std::set<std::string> Tweet::getLikes(){
    return this->likes;
}

void Tweet::setRt(Tweet* tw){
    this->rt = tw;
}

void Tweet::setDeleted(){
    this->deleted = true;
}

bool Tweet::isDeleted(){
    return this->deleted;
}