#ifndef SHIP_H
#define SHIP_H
#include "general.h"

using namespace std;

class pship:public general
{
 
 public:
 	pship(QPixmap *pm, int ny, int nx);
 	void move(int mx);
 	void manage();
};

#endif
