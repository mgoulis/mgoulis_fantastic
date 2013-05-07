#ifndef BULLET_H
#define BULLET_H
#include "general.h"

using namespace std;
/**
 Bullet Is An Object That, When It Hits An Enemy, Kills Itself And The Enemy
 \brief Class That Sets Up Bullet Behavior
 @author Michael Goulis
  */
class bullet:public general
{
 
 public:
 	/** Constructor For Bullet **/
 	bullet(QPixmap *pm, int ny, int nx);
 	/** Creates A Positive Vertical Movement **/
 	int manage();
 	/** Manages How Long The Bullet Will Last Before Destroying Itself **/
 	int lifespan;
};

#endif
