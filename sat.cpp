#include "sat.h"
using namespace std;


sat::sat(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(2);
	}

void sat::manage(int i)
	{
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}