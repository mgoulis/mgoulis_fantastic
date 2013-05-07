 #ifndef UFO_H
#define UFO_H
#include "enemy.h"

using namespace std;
/**
 Enemy That Moves Downward In A Wavelike Pattern against the timer; UFO enemy
 \brief UFO Enemy
 @author Michael Goulis
  */
class ufo:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	ufo(QPixmap *pm, int ny, int nx);
 	/**Manages Handletimer's movement against variable i**/
 	void manage(int i);
};

#endif
