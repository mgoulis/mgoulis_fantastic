 #include "mainwindow.h"
 #include <QImage>
 #include "sat.h"
 #include <sstream>
 
 
 
  
/**MyWidget Is A Class That Generates all Windows, Buttons, and Scenes To Be Shown*/
 MyWidget::MyWidget(QWidget *parent)
     : QWidget(parent)
 { 
 /**Area To Set Up The Game Area*/
 scene = new QGraphicsScene();
 view = new QGraphicsView( scene);
 i=-1;
 
 /**Initial Setup*/
 lives = 2; score = 0; bonghits = 0; lboom = 0; lpoop = 0; weightwatchers = 3; ggallin = 0;
 qfl = new QFormLayout;
 sp = new QPixmap("assets/ship.png"); 
 mt = new QPixmap("assets/med.png"); uf = new QPixmap("assets/UFO.png"); stt = new QPixmap("assets/sat.png");
 btt = new QPixmap("assets/green.png"); 
 c1 = new QPixmap("assets/citygreen.png"); c2 = new QPixmap("assets/cityred.png");
 center = new city(c1, 700, 0);
 player = new pship(sp, 620, 400);
 qgl = new QGridLayout;

 
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

//hey commands for movement and firing
switch ( e->key() ) {
		case Qt::Key_Left : player->setVx(-6);
				    break;

		case Qt::Key_Right :player->setVx(6);
				    break;
		
		case Qt::Key_Space :
				    bullet *temp = new bullet(btt, player->gety(),player->getx());
	 	 	 	    scene->addItem(temp);
	 	 	            bgroup.push_back(temp);
				    break;
		    }
}

//key commands to release movement
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
	 while(lpoop<weightwatchers)
	 	{
	 	 
	 	 if(bonghits<9)
	 	 	{
	 	 	 med *temp = new med(mt, 0, (40+(rand()%720)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<18&&bonghits>=9)
	 	 	{
	 	 	 ufo *temp = new ufo(uf, 0, (200+(rand()%400)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<27&&bonghits>=18)
	 	 	{
	 	 	 sat *temp = new sat(stt, 0, (250+(rand()%300)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 bonghits = bonghits+1;
	 	 lpoop = lpoop +1;
	 	}
	 i++;
	 player->manage();
	 vector<bullet*>::iterator ii =bgroup.begin();
	 for(;ii!=bgroup.end();ii++)
	 	{
	 	 (*ii)->manage();
	 	}
	 vector<enemy*>::iterator it =egroup.begin();
	 for(;it!=egroup.end();)
	 	{
	 	 (*it)->manage(i);
	 	 if((*it)->collidesWithItem(center))
	 	 	{
	 	 	 center->setPixmap(*c2);
	 	 	 scene->removeItem(*it);
	 	 	 delete * it;
	 	 	 it = egroup.erase(it);
	 	 	 lpoop--;
	 	 	 lives--;
	 	 	 if (lives==0)
	 	 	 	{cout<<score;exit(666);}
	 	 	}
	 	 else{++it;}
	 	}
	 bool idea;
	 vector<bullet*>::iterator yy =bgroup.begin();
	 for(;yy!=bgroup.end();)
	 	{
	 	 idea = false;
	 	 vector<enemy*>::iterator xx =egroup.begin();
		 for(;xx!=egroup.end();)
		 	{
		 	 if((*xx)->collidesWithItem(*yy))
		 	 	{
		 	 	 idea = true;
		 	 	 scene->removeItem(*xx);
		 	 	 scene->removeItem(*yy);
		 	 	 delete * xx;
		 	 	 delete * yy;
		 	 	 xx = egroup.erase(xx);
		 	 	 yy = bgroup.erase(yy);
		 	 	 lpoop--;
		 	 	 score+=500;
		 	 	 break;
		 	 	}
		 	 else{++xx;}
		 	}
		 if(idea == false){++yy;}
	 	}
	 if(i>=100)
	   {i=-1;}
	}


