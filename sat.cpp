#include "sat.h"
using namespace std;


sat::sat(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(3);
	 lethal = true;
	}

void sat::manage(int i)
	{
	 if(i>getx()){setVx(2);setVy(3);};
	 if(i<getx()){setVx(-2);setVy(3);};
	 if(i==getx()){setVx(0); setVy(6);};
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
