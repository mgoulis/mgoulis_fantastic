#include "spy.h"
using namespace std;


spy::spy(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx)
	{
	 setVy(1);
	}

void spy::manage(int i)
	{
	 if(i<50)
	    {setVx(-5);}
	 if(i>=50)
	    {setVx(5);}
	 int temp = getVx()+getx();
	 setx(temp);
	 sety(gety()+getVy());
	 setPos(temp,gety());
	}
