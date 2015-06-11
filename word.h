#ifndef WORD_H
#define WORD_H

#include <QWidget>
#include<string>
#include<stdlib.h>
#include<time.h>
class Word
{
    std::string name;
    int points;
public:
    Word(const std::string& name="",int points=0):name(name),points(points){}
    ~Word();
    std::string get_name()const;
    int get_points()const{return points;};
    Word operator=(const Word& other){
           this->name=other.get_name();
        this->points=other.get_points();
            return *this;
    }
    Word scrable(){
        std::string scrabled=name;char t;
        srand(time(NULL));
        int n=rand()%name.size()+1;
        for(int i=1;i<=n;i++){
            int k1=rand()%name.size();
            int k2=rand()%name.size();
            t=scrabled[k1];
            scrabled[k1]=scrabled[k2];
            scrabled[k2]=t;
        }
        return Word(scrabled,points);
    }
};

#endif // WORD_H
