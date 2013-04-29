 #include "mainwindow.h"
 #include <QImage>
 
 
  
/**MyWidget Is A Class That Generates all Windows, Buttons, and Scenes To Be Shown*/
 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 { 
 /**Area To Set Up The Game Area*/
 scene = new QGraphicsScene();
 view = new QGraphicsView( scene);
 i=-1;
 
 /**Initial Setup*/
 lives = 2; score = 0; bonghits = 0; lboom = 0; lpoop = 0;
 qfl = new QFormLayout;
 sp = new QPixmap("assets/ship.png"); 
 mt = new QPixmap("assets/med.png"); uf = new QPixmap("assets/UFO.png");
 c1 = new QPixmap("assets/citygreen.png"); c2 = new QPixmap("assets/cityred.png");
 center = new city(c1, 700, 0);
 player = new pship(sp, 620, 400);
 
 QBrush BBlack(Qt::black);
 scene->setSceneRect(0,0,800,800);
 view->fitInView(0, 0, 800, 800);
 scene->setBackgroundBrush(QImage("assets/stars.png"));
 
 
 //QGraphicsPixmapItem item( QPixmap::fromImage(image));
 scene->addItem(player); 
 scene->addItem(center); 
 qfl->addRow(view);
 
 setFocus();
 setLayout(qfl); /**Establish Final Layout*/
 
 timer = new QTimer(this);
 timer->setInterval(10);
 connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}


void MyWidget::keyPressEvent( QKeyEvent *e ) {

switch ( e->key() ) {
		case Qt::Key_Left : player->setVx(-6);
				    break;

		case Qt::Key_Right :player->setVx(6);
				    break;
		
		case Qt::Key_Space :
				    break;
		    }
}

void MyWidget::keyReleaseEvent( QKeyEvent *z ) {

switch ( z->key() ) {
		case Qt::Key_Left : player->setVx(0);
				    break;

		case Qt::Key_Right :player->setVx(0);
				    break;

		    }
}



void MyWidget::live() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();
    //This is how we get our view displayed.
    //qfl->update();
    this->show();
}

void MyWidget::handleTimer()
	{
	 while(lpoop<3)
	 	{
	 	 if(bonghits<10)
	 	 	{
	 	 	 med *temp = new med(mt, 0, (40+(rand()%720)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<20&&bonghits>=10)
	 	 	{
	 	 	 ufo *temp = new ufo(uf, 0, (200+(rand()%400)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 bonghits = bonghits+1;
	 	 lpoop = lpoop +1;
	 	}
	 i++;
	 player->manage();
	 vector<int> hold;
	 int j = 0;
	 vector<enemy*>::iterator it =egroup.begin();
	 for(;it!=egroup.end();it++)
	 	{
	 	 (*it)->manage(i);
	 	 if((*it)->collidesWithItem(center))
	 	 	{
	 	 	 center->setPixmap(*c2);
	 	 	 scene->removeItem(*it);
	 	 	 //egroup.erase(egroup.begin()+j);
	 	 	}
	 	 j++;
	 	}
	 if(i>=100)
	   {i=-1;}
	}


