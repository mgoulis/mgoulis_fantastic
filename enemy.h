 #ifndef ENEMY_H
#define ENEMY_H
#include "general.h"

using namespace std;

class enemy:public general
{
 
 public:
 	enemy(QPixmap *pm, int ny, int nx);
 	virtual void manage(int i)
 		{
 		 i = i;
		 sety(gety()+getVy());
		 setPos(getx(),gety());
		};
	bool lethal;
};

#endif
