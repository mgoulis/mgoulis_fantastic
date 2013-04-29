#ifndef GENERAL_H
#define GENERAL_H
#include <QWidget>
#include <QPixmap>
#include "QObject"
#include <iostream>
#include <QPainter>
#include <QGraphicsPixmapItem>

using namespace std;

class general:public QGraphicsPixmapItem
{
 
 public:
 	general(QPixmap *pm, int ny, int nx);
 	void setVx(int mx);
 	void setVy(int mx);
 	void sety(int ny);
 	void setx(int nx);
 	int getVx();
 	int getVy();
 	int getx();
 	int gety();
    
 private:
 	int x;
 	int y;
 	int vX;
 	int vY;
 	QPixmap *pixMap;
};

#endif
