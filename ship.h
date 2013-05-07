#ifndef SHIP_H
#define SHIP_H
#include "general.h"

using namespace std;
/**
 The Player's Ship Object
 \brief Player Ship
 @author Michael Goulis
  */
class pship:public general
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	pship(QPixmap *pm, int ny, int nx);
 	/**Used In mainwindow.h for Player Keypresses**/
 	void move(int mx);
 	/**Used to make changes in the handletimer function**/
 	void manage();
};

#endif
