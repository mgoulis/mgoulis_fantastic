#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <QFormLayout>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QLineEdit>
#include <QTextEdit>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include "QObject"
#include "ship.h"
#include "ufo.h"
#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 5000

 
 // Class Definition
 class MyWidget :public QWidget{
  Q_OBJECT
  
 public:
     MyWidget(QWidget *parent = 0);
     QTimer * timer;
     void live();
  
 public slots:
     void handleTimer();
 
 protected:
     void keyPressEvent( QKeyEvent *e );   
     void keyReleaseEvent( QKeyEvent * );   
 
 private:
    //Overall Form Structure
    QFormLayout *qfl;
    QPixmap * uf;
    QPixmap * sp;
    int i;
    int* lives;
    int* score;
    
    	/**Gameplay*/
    QGraphicsScene *scene;
    QGraphicsView *view;
    QBrush BBlack;
    pship * player;
    ufo * UFO1, *UFO2, *UFO3, *UFO4, *UFO5, *UFO6;
    
    
};

#endif
