#ifndef SAT_H
#define SAT_H
#include "enemy.h"

using namespace std;

class sat:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	sat(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
