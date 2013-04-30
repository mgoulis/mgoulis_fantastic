#ifndef POO_H
#define POO_H
#include "enemy.h"

using namespace std;

class poo:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	poo(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
