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
/**
 Class That Manages Most Game Elements Including Display, Gameplay, And Output
 \brief Main Window Class And General Gameplay
 @author Michael Goulis
*/
 // Class Definition
 class MyWidget :public QWidget{
  Q_OBJECT
  
 public:
     /** Constructor For The Class**/
     MyWidget(QWidget *parent = 0);
     /** Initializes The Timer**/
     QTimer * timer;
     /** Returns If The Timer Is Running**/
     void live();
  
 public slots:
     /** Will Manage What Occurs While The Timer Is Running**/
     void handleTimer();
     /** Initializes The Start Of The Game When The Start Game Button Is Pressed**/
     void gamestart();
     /** Pauses The Game**/
     void pauz();
 
 protected:
     /** Executes Certain Actions When Certain Buttons Are Pressed**/
     void keyPressEvent( QKeyEvent *e ); 
     /** Makes Sure That Keypresses Don't Last Forever**/  
     void keyReleaseEvent( QKeyEvent * );   
 
 private:
    /** Basic Layout For Window Display**/
    QFormLayout *qfl;
    /** The Different Images Used To Display Visuals**/
    QPixmap *uf, *sp, *spp, *sppp, *c1, *c2, *mt, *stt, *btt, *pink, *invade, *poop, *sc1, *sc2;
    /** The Button Layout**/
    QGridLayout * qgl, *qg2;
    /** Int values used to track the timer and number of objects onscreen**/
    int i, lives, score, bonghits, lboom, lpoop, weightwatchers, ggallin, plife;
    /** Used to Ensure Segfaults dont happen with the pause button**/
    bool holding;
    /** The Various Text Items That Display To The Screen **/
    QGraphicsSimpleTextItem * Score, *V;
    /** The UI Buttons **/
    QPushButton * quit, *newg, *pause;
    /** The Name Box **/
    QLineEdit *nom;
    /** The Label For The Name Box**/
    QLabel *nomlab;
    /** Empties All Images Onscreen Except The Background**/
    void cleararea();
    /** Changes Image For Level 3**/
    void level2();
    /** Changes Image For Level 2**/
    void level3();
    /** Manages What Happens If The Player Is Hit By An Enemy**/
    void playerhit();
    /** Manages The Files For Setting A Highscore **/
    void highscore();
    /** The Vector That Holds Active Enemy **/
    vector<enemy*> egroup;
    /** The Vector That Holds Active Bullets **/
    vector<bullet*> bgroup;
    /** The Vector That Holds Onscreen Text **/
    vector<QGraphicsSimpleTextItem*> xgroup;
    /** The Game Scene **/
    QGraphicsScene *scene;
    /** The Game Vies **/
    QGraphicsView *view;
    /** The Player's Farm **/
    city * center;
    /** The Player's Spaceship **/
    pship * player;
};

#endif
