#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsAnchorLayout>
#include <QGraphicsLinearLayout>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QGridLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "graphwidget.h"
#include <QLineEdit>
class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton *btnDoIt;
    GraphWidget *initialRepresentation;
    GraphWidget *finalRepresentation;
    QLabel *lblEdgeList;
    QLabel *lblGridSize;
    QLabel *lblSquareSize;
    QLineEdit *leEdgeList;
    QLineEdit *leGridSize;
    QLineEdit *leSquareSize;

public:
    explicit MainWindow(QWidget *parent = 0);
    void setGraph(QVector<QVector<int>>);
    void setGraph(QString edges, QString grid, QString square);
private slots:
    void doIt();
signals:
public slots:
};

#endif // MAINWINDOW_H
