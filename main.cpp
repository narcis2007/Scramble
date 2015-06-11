#include "simulator.h"
#include <QApplication>
#include"game.h"
#include"repository.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository("data.txt","saved_data.txt");
    Game game(repository);
    Simulator w(game);
    w.show();

    return a.exec();
}
