#include "tablemodel.h"

TableModel::TableModel(Game &game, QObject *parent):game(game),QAbstractTableModel(parent){
    v=game.get_guessed_words();
    connect(&game,SIGNAL(guessed()),this,SLOT(update()));
    connect(&game,SIGNAL(not_guessed()),this,SLOT(update()));
    connect(&game,SIGNAL(game_reseted()),this,SLOT(update()));

}
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Word");
            }
        }
    }
    return QVariant();
}
QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        if(index.column()==0)
            return QString((v[index.row()].get_name().c_str()));
    }
    return QVariant();
}
void TableModel::setVectorData(std::vector<Word> v2){
    v.clear();
    v=v2;

    beginResetModel();
    endResetModel();
}

void TableModel::update(){
    v.clear();
    v=game.get_guessed_words();
    beginResetModel();
    endResetModel();
}
TableModel::~TableModel()
{
    ;
}

