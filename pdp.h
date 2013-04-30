#ifndef PDP_H
#define PDP_H
#include "enemy.h"

using namespace std;

class pdp:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	pdp(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
