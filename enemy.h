 #ifndef ENEMY_H
#define ENEMY_H
#include "general.h"

using namespace std;
/**
 This Is The Class That All Enemies Derrive From. It Establishes A Basic Movement Direction And Properties
 \brief Class That Defines General Enemy Behavior
 
 
 @author Michael Goulis
  */
class enemy:public general
{
 
 public:
 	/**Constructor That Creates Basic Behavior, namely movement**/
 	enemy(QPixmap *pm, int ny, int nx);
 	/**The Manage virtual function Dictates The Basic Scheme Of Movement With velocity on a timer**/
 	virtual void manage(int i)
 		{
 		 i = i;
		 sety(gety()+getVy());
		 setPos(getx(),gety());
		};
	/**Used to check movement pattern for certan objects**/
	bool lethal;
};

#endif
