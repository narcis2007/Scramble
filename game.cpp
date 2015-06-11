#include "game.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
Game::Game(Repository& repository,QWidget *parent) :repository(repository), QWidget(parent)
{
    sum=0;
    miss=0;
    v=repository.get_all();
    srand(time(NULL));
    currentWord=v[rand()%v.size()];
}

Word Game::get_scrambled_word(){
    return currentWord.scrable();
}

Game::~Game()
{

}

