#include "ufo.h"
using namespace std;


ufo::ufo(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(1);
	}

void ufo::manage(int i)
	{
	 if(i<50)
	    {setVx(-2);}
	 if(i>=50)
	    {setVx(2);}
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
