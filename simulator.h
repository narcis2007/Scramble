#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QtWidgets>
#include"graph.h"
#include"game.h"
#include"tablemodel.h"
#include"errorwindow.h"
class Simulator : public QWidget
{
    Q_OBJECT
    Game& game;
    Graph *graph;
    QVBoxLayout *layout;
    QHBoxLayout *inputLayout;
    QPushButton *guess;
    QLineEdit *text;
    QLabel *guessWord;
    ErrorWindow *error;
    QTableView *view;
    TableModel *model;
public:
    explicit Simulator(Game& game,QWidget *parent=0);
    ~Simulator();


public slots:
    void guesspushed();
    void guessed(){
        game.change_current_word();
        guessWord->setText(QString(game.get_scrambled_word().get_name().c_str()));

    }
    void reset_game(){
        game.change_current_word();
        guessWord->setText(QString(game.get_scrambled_word().get_name().c_str()));
    }
};

#endif // SIMULATOR_H
