#include "poo.h"
using namespace std;


poo::poo(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(4);
	 lethal = true;
	}

void poo::manage(int i)
	{
	 if(i>getx()){setVx(2);setVy(4);};
	 if(i<getx()){setVx(-2);setVy(4);};
	 if(i==getx()){setVx(0); setVy(11);};
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
