 #ifndef MED_H
#define MED_H
#include "enemy.h"

using namespace std;

class med:public enemy
{
 
 public:
 	med(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
