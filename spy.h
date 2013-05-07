#ifndef SPY_H
#define SPY_H
#include "enemy.h"

using namespace std;
/**
 Enemy That Makes Long Wide Zig-Zag Movements; Space Invader Enemy
 \brief Space Invader Enemy
 @author Michael Goulis
  */
class spy:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	spy(QPixmap *pm, int ny, int nx);
 	/**Manages Movement Against Timing intiger i from Handletimer**/
 	void manage(int i);
};

#endif
