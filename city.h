#ifndef CITY_H
#define CITY_H
#include "general.h"

using namespace std;
/**
  Farm/City At The Bottom Of The Screen That Will End The Game If It Is Hit Twice
  \brief Class That Sets Up City/Farm
 @author Michael Goulis
  */

class city:public general
{
 
 public:
 	/**Constructor That Establishes Position**/
 	city(QPixmap *pm, int ny, int nx);
};

#endif
