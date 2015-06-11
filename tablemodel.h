#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include<QtWidgets>
#include"game.h"
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Game& game;
    std::vector<Word> v;
private slots:
    void update();
public:
    TableModel(Game& game,QObject* parent=0);
    int rowCount(const QModelIndex&) const
    {
        return v.size();
    }
    int columnCount(const QModelIndex&) const
    {
        return 1;
    }
    void setVectorData(std::vector<Word> v2);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    ~TableModel();
};

#endif // TABLEMODEL_H
