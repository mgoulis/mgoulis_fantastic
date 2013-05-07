#ifndef SAT_H
#define SAT_H
#include "enemy.h"

using namespace std;
/**
 Creates A Satelite Enemy Which Draws Itself to The Player At Moderate Speeds
 \brief Satellite Enemy
 @author Michael Goulis
  */
class sat:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	sat(QPixmap *pm, int ny, int nx);
 	/**Tracks Player Movement With i and Approaches Player**/
 	void manage(int i);
};

#endif
