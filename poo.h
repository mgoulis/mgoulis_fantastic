#ifndef POO_H
#define POO_H
#include "enemy.h"

using namespace std;
/**
 Creates A Poop Enemy Which Draws Itself to The Player At High Speeds
 \brief Poop Enemy
 @author Michael Goulis
  */
class poo:public enemy //IT TAKES A NATION OF MILLIONS!!!
{
 
 public:
 	/**Constructor That Establishes Basic Qualities**/
 	poo(QPixmap *pm, int ny, int nx);
 	/**Tracks Player Movement With i and Approaches Player**/
 	void manage(int i);
};

#endif
