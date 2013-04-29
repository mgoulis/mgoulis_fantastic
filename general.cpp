#include "general.h"
using namespace std;


general::general(QPixmap *pm, int ny, int nx)
{
 pixMap = pm;
 setPixmap(*pixMap);
 x=nx;
 y=ny;
 vX = 0;
 vY = 4;
 setPos(x,y);
}

void general::setVx(int mx){vX = mx;}

void general::setVy(int mx){vY = mx;}

void general::setx(int nx){x = nx;}

void general::sety(int ny){y = ny;}

int general::getx(){return x;}

int general::gety(){return y;}

int general::getVx(){return vX;}

int general::getVy(){return vY;}


