#include "mainwindow.h"
#include <Qt>
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setGeometry(50, 50, 850, 900);
    btnDoIt = new QPushButton("Evolve!", this);
    initialRepresentation = new GraphWidget(this);
    finalRepresentation = new GraphWidget(this);
    initialRepresentation->setGeometry(0, 0, 400, 400);
    finalRepresentation->setGeometry(400, 0, 400, 400);


    lblEdgeList = new QLabel("Edges List");
    lblGridSize = new QLabel("Grid size");
    lblSquareSize = new QLabel("Square size");
    leEdgeList = new QLineEdit;
    leGridSize = new QLineEdit;
    leSquareSize = new QLineEdit;

//    leEdgeList->setFixedWidth(100);
//    leGridSize->setFixedWidth(100);
//    leSquareSize->setFixedWidth(100);

    leEdgeList->setAlignment(Qt::AlignLeft);
    leGridSize->setAlignment(Qt::AlignLeft);
    leSquareSize->setAlignment(Qt::AlignLeft);

    QVBoxLayout *lInputBox = new QVBoxLayout;

    QHBoxLayout *layoutH = new QHBoxLayout;
    layoutH->addWidget(lblEdgeList);
    layoutH->addWidget( leEdgeList);
    lInputBox->addLayout(layoutH);

    layoutH = new QHBoxLayout;
    layoutH->addWidget(lblGridSize);
    layoutH->addWidget( leGridSize);
    lInputBox->addLayout(layoutH);

    layoutH = new QHBoxLayout;
    layoutH->addWidget(lblSquareSize);
    layoutH->addWidget( leSquareSize);
    lInputBox->addLayout(layoutH);

    QHBoxLayout *layoutRepresentation = new QHBoxLayout;
    layoutRepresentation->addWidget(initialRepresentation);
    layoutRepresentation->addWidget(finalRepresentation);

    QHBoxLayout *layoutInput = new QHBoxLayout;
    layoutInput->addLayout(lInputBox);
    layoutInput->addWidget(btnDoIt);

//    QGridLayout* layout = new QGridLayout;
//    layout->addWidget(initialRepresentation, 0, 0);
//    layout->addWidget(finalRepresentation, 0, 1);
//    layout->addLayout(lInputBox, 1, 0, Qt::AlignLeft);
//    layout->addWidget(btnDoIt, 1, 1, Qt::AlignHCenter);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(layoutRepresentation, 1);
    layout->addLayout(layoutInput, 1);
    setLayout(layout);
    qInfo() << initialRepresentation->size().width() << " " << initialRepresentation->size().height() << endl;
    finalRepresentation->setWaitForClick(1);
    connect(leEdgeList, SIGNAL(returnPressed()), this, SLOT(doIt()));
    connect(leGridSize, SIGNAL(returnPressed()), this, SLOT(doIt()));
    connect(leSquareSize, SIGNAL(returnPressed()), this, SLOT(doIt()));
    connect(btnDoIt, SIGNAL(released()), this, SLOT(doIt()));

}

void MainWindow::setGraph(QString edges, QString grid, QString square)  {
    initialRepresentation->setGraph(edges, grid, square);
//    initialRepresentation->setCoordinates(GraphWidget::genRandomPoints(adjList.size(), initialRepresentation->baseSize().width()));
    finalRepresentation->setGraph(edges, grid, square);
//    finalRepresentation->setCoordinates(GraphWidget::genRandomPoints(adjList.size(), finalRepresentation->baseSize().width()));
}


void MainWindow::setGraph(QVector<QVector<int> > adjList) {
    initialRepresentation->setGraph(adjList);
//    initialRepresentation->setCoordinates(GraphWidget::genRandomPoints(adjList.size(), initialRepresentation->baseSize().width()));
    finalRepresentation->setGraph(adjList);
//    finalRepresentation->setCoordinates(GraphWidget::genRandomPoints(adjList.size(), finalRepresentation->baseSize().width()));
}


void MainWindow::doIt() {
    qInfo() << "in doId, set graph" << endl;
    setGraph(leEdgeList->text(), leGridSize->text(), leSquareSize->text());
}
