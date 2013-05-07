#include "pdp.h"
using namespace std;


pdp::pdp(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(3);
	}

void pdp::manage(int i)
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
