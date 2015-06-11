#include "simulator.h"
#include<QtWidgets>
Simulator::Simulator(Game &game,QWidget *parent)
    : game(game),QWidget(parent)
{
    layout=new QVBoxLayout();


    inputLayout=new QHBoxLayout();


    guessWord=new QLabel(game.get_scrambled_word().get_name().c_str());
    layout->addWidget(guessWord);

    text=new QLineEdit();
    inputLayout->addWidget(text);

    guess=new QPushButton("Guess");
    inputLayout->addWidget(guess);
    connect(guess,SIGNAL(clicked()),this,SLOT(guesspushed()));

    layout->addLayout(inputLayout);

    graph=new Graph(game);
    layout->addWidget(graph);

    view=new QTableView();
    model=new TableModel(game);
    view->setModel(model);
    layout->addWidget(view);

    setLayout(layout);

    error=0;

    connect(&game,SIGNAL(guessed()),this,SLOT(guessed()));
    connect(&game,SIGNAL(game_reseted()),this,SLOT(reset_game()));

}
void Simulator::guesspushed(){
    if(text->text().toStdString().size()!=game.get_current_word().get_name().size())
    {   if(error==0)
            error=new ErrorWindow("lenghts do not match");
        error->show();
    }
    else{
        game.check(text->text().toStdString());
    }
}

Simulator::~Simulator()
{
    delete graph,guessWord,error,view,model;
    delete layout,guess,text,inputLayout,game;
}
