#include "med.h"
using namespace std;


med::med(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(1);
	 lethal = true;
	 }

void med::manage(int i)
	{
	 i = i;
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
