 #ifndef UFO_H
#define UFO_H
#include "enemy.h"

using namespace std;

class ufo:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	ufo(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
