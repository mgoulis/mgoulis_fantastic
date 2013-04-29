#include "med.h"
using namespace std;


med::med(QPixmap *pm, int ny, int nx):enemy(pm,ny,nx){}

void med::manage(int i)
	{
	 sety(gety()+getVy());
	 setPos(getx(),gety());
	}
