#include "graph.h"

Graph::Graph(Game& game,QWidget *parent) :game(game), QWidget(parent)
{
    setMinimumSize(300,500);
    connect(&game,SIGNAL(guessed()),this,SLOT(update_graph()));
    connect(&game,SIGNAL(not_guessed()),this,SLOT(update_graph()));
}
void Graph::paintEvent(QPaintEvent *event){
       QPainter painter(this);
       int w=width();
       int h=height();
       int baselineY=h-10;
       int barWidth=120;
       painter.drawLine(0,baselineY,w,baselineY);
       painter.drawRect(w/2, baselineY - game.get_sum()*20 , barWidth/2 , game.get_sum()*20);
       painter.drawText(w/2,baselineY-20-game.get_sum()*20,QString("Scor: ")+QString::number(game.get_sum()));
}
Graph::~Graph()
{

}

