#ifndef GRAPH_H
#define GRAPH_H

#include <QtWidgets>
#include"game.h"

class Graph : public QWidget
{
    Q_OBJECT
    Game& game;
    void paintEvent(QPaintEvent *event);
public:
    explicit Graph(Game& game,QWidget *parent = 0);
    ~Graph();


signals:

public slots:
    void update_graph(){update();}
};

#endif // GRAPH_H
