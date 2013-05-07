#ifndef GENERAL_H
#define GENERAL_H
#include <QWidget>
#include <QPixmap>
#include "QObject"
#include <iostream>
#include <QPainter>
#include <QGraphicsPixmapItem>

using namespace std;
/**
 General Is A Fuction That Is Used By All Enemies, The Player Ship, The Farm/City, And All Bullets  
 
 \brief Class That Defines General Behavior
 
 @author Michael Goulis
  */
class general:public QGraphicsPixmapItem
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	general(QPixmap *pm, int ny, int nx);
  	/**Sets The Velocity Of The Object In Direction X**/
 	void setVx(int mx);
 	/**Sets The Velocity Of The Object In Direction Y**/
 	void setVy(int mx);
 	/**Sets The Position Of The Object In X**/
 	void sety(int ny);
 	/**Sets The Position  Of The Object In Y**/
 	void setx(int nx);
 	/**Gets The Velocity Of The Object In Direction X**/
 	int getVx();
 	/**Sets The Velocity Of The Object In Direction Y**/
 	int getVy();
 	/**Gets The Position Of The Object In X**/
 	int getx();
 	/**Gets The Position Of The Object In Y**/
 	int gety();
    
 private:
 	int x;
 	int y;
 	int vX;
 	int vY;
 	QPixmap *pixMap;
};

#endif
