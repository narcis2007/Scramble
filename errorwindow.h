#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QtWidgets>
#include<string>

class ErrorWindow : public QWidget
{
    Q_OBJECT
    QLabel *error;
    QGridLayout *layout;
public:
    explicit ErrorWindow(const std::string&,QWidget *parent = 0);
    ~ErrorWindow();

signals:

public slots:
};

#endif // ERRORWINDOW_H
