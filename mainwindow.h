#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>

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
#include "city.h"
#include "med.h"
#include "ship.h"
#include "ufo.h"
#include "bullet.h"
#include "poo.h"
#include "spy.h"
#include "pdp.h"
#include <fstream>
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
    QPixmap *uf, *sp, *spp, *sppp, *c1, *c2, *mt, *stt, *btt, *pink, *invade, *poop, *sc1, *sc2;
    QGridLayout * qgl, *qg2;
    QGraphicsTextItem *l, *s;
    int i, lives, score, bonghits, lboom, lpoop, weightwatchers, ggallin, plife;
    bool holding;
    QGraphicsSimpleTextItem * Score, *V;
    QPushButton * quit, *newg, *pause;
    QLineEdit *nom;
    QLabel *nomlab;
    void cleararea();
    void level2();
    void level3();
    void playerhit();
    void clearscroll();
    void highscore();
    
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
