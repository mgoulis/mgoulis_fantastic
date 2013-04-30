#include "poo.h"
using namespace std;


poo::poo(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(2);
	}

void poo::manage(int i)
	{
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
