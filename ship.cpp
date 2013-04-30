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
	 sety(gety()+getVy());
	 if(getx()<-50)
	 	{temp = 825;}
	 if(getx()>850)
	 	{temp = -25;}
	 setx(temp);
	 setPos(getx(),gety());
	}
	
/*
	 if(getx()<501&&getx()>-1)
	 	{
	 	 setx(getVx() + getx());
	 	 setPos(getx(),gety());
	 	}

*/

