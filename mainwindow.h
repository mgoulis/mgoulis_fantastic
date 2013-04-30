#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include "city.h"
#include "med.h"
#include <QFormLayout>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QLabel>
#include <QTimer>
#include <QLineEdit>
#include <QTextEdit>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "QObject"
#include "ship.h"
#include "ufo.h"
#include "bullet.h"
#include "poo.h"
#include "spy.h"
#include "pdp.h"
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
     void gamestart();
     void pauz();
 
 protected:
     void keyPressEvent( QKeyEvent *e );   
     void keyReleaseEvent( QKeyEvent * );   
 
 private:
    //Overall Form Structure
    QFormLayout *qfl;
    QPixmap *uf, *sp, *c1, *c2, *mt, *stt, *btt, *pink, *invade, *poop;
    QGridLayout * qgl, *qg2;
    QGraphicsTextItem *l, *s;
    int i, lives, score, bonghits, lboom, lpoop, weightwatchers, ggallin;
    bool holding;
    QGraphicsSimpleTextItem * Score, *V;
    QPushButton * quit, *newg, *pause;
    QLineEdit *nom;
    QLabel *nomlab;
    void cleararea();
    
    	/**Gameplay*/
    vector<enemy*> egroup;
    vector<bullet*> bgroup;
    vector<QGraphicsSimpleTextItem*> xgroup;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QBrush BBlack;
    city * center;
    pship * player;
};

#endif
