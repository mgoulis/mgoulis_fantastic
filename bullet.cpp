#include "bullet.h"
using namespace std;


bullet::bullet(QPixmap *pm, int ny, int nx):general(pm,ny,nx)
	{
	 setVy(-3);
	}
	
int bullet::manage()
	{
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	 lifespan++;
	 return lifespan;
	}
