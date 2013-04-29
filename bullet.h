#ifndef BULLET_H
#define BULLET_H
#include "general.h"

using namespace std;

class bullet:public general
{
 
 public:
 	bullet(QPixmap *pm, int ny, int nx);
 	int manage();
 	int lifespan;
};

#endif
