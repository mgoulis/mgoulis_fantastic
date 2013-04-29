#include "ufo.h"
using namespace std;


ufo::ufo(QPixmap *pm, int ny, int nx):general(pm,ny,nx){}

void ufo::manage(int i)
	{
	 if(i<=25)
	    {setVx(-4);}
	 if(i>25)
	    {setVx(4);}
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
