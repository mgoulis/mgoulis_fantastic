#ifndef PDP_H
#define PDP_H
#include "enemy.h"

using namespace std;
/**
 PDP is the Pinkie Pie Pony Enemy that moves down in tight fast waveforms
 \brief My Little Pony (Pinkie Pie) Enemy
 @author Michael Goulis
  */
class pdp:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	pdp(QPixmap *pm, int ny, int nx);
 	/**Function used in handletimer against variable i**/
 	void manage(int i);
};

#endif
