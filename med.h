 #ifndef UFO_H
#define UFO_H
#include "general.h"

using namespace std;

class ufo:public general
{
 
 public:
 	ufo(QPixmap *pm, int ny, int nx);
 	void manage(int i);
};

#endif
