#include "ship.h"
using namespace std;


pship::pship(QPixmap *pm, int ny, int nx):general(pm,ny,nx)
	{
	 setVy(0);
	}


void pship::move(int mx)
	{
	 setVx(mx);
	}
	
void pship::manage()
	{
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
	
/*
	 if(getx()<501&&getx()>-1)
	 	{
	 	 setx(getVx() + getx());
	 	 setPos(getx(),gety());
	 	}

*/

