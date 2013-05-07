 #ifndef MED_H
#define MED_H
#include "enemy.h"

using namespace std;
/**
 Meteor Enemy That Moves In A Basic Downward Trajectory
 \brief Meteor Enemy
 @author Michael Goulis
  */
class med:public enemy
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	med(QPixmap *pm, int ny, int nx);
 	/**Manages Movement int the handletimer function**/
 	void manage(int i);
};

#endif
