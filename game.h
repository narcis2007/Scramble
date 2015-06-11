#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include<vector>
#include"word.h"
#include"repository.h"
class Game : public QWidget
{
    Q_OBJECT
    std::vector<Word> v,guessedWords;
    Word currentWord;
    int sum;
    int miss;
    Repository& repository;
public:
    explicit Game(Repository& repository,QWidget *parent = 0);
    ~Game();
    Word get_scrambled_word();
    void check(const std::string& input){
           if(input==currentWord.get_name())
           {
               sum=sum+currentWord.get_points();
               guessedWords.push_back(currentWord);
               miss=0;
               emit guessed();
           }
           else {
               sum--;
               miss++;
               if(miss>3){

                   reset_game();
                   emit game_reseted();
               }
               emit not_guessed();
           }

     }
    int get_sum(){
        return sum;
    }
    void reset_game(){
        repository.save_game(guessedWords,sum);
        guessedWords.clear();
        sum=0;
        change_current_word();
    }

    Word get_current_word(){
        return currentWord;
    }
    void change_current_word(){
        srand(time(NULL));
        currentWord=v[rand()%v.size()];
    }
    std::vector<Word> get_guessed_words(){
        return guessedWords;
    }

signals:
    void guessed();
    void not_guessed();
    void game_reseted();
public slots:
};

#endif // GAME_H
