 #include "mainwindow.h"
 #include "QMessageBox"
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
 
 /**Initial Setup*/
 qfl = new QFormLayout;
 lives = 2; score = 0; bonghits = 0; lboom = 0; lpoop = 0; weightwatchers = 3; ggallin = 0; i=-1;
 holding = true;
 
 //QPixmap files
 sp = new QPixmap("assets/ship.png"); 
 mt = new QPixmap("assets/med.png"); 
 uf = new QPixmap("assets/UFO.png"); 
 stt = new QPixmap("assets/sat.png");
 btt = new QPixmap("assets/green.png"); 
 c1 = new QPixmap("assets/citygreen.png"); 
 c2 = new QPixmap("assets/cityred.png");
 pink = new QPixmap("assets/pdp.png");
 invade = new QPixmap("assets/spy.png");
 poop = new QPixmap("assets/poop.png");
 
 scene->setBackgroundBrush(QImage("assets/stars.png"));
 
 nom = new QLineEdit;
 nomlab = new QLabel("Player Name");
 nomlab->setFont(QFont("New York", 10, QFont::Bold));
 center = new city(c1, 700, 0);
 player = new pship(sp, 620, 400);
 
 
 qgl = new QGridLayout;
 qg2 = new QGridLayout;
 
 quit = new QPushButton(tr("Quit"));
 connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
 
 newg = new QPushButton(tr("New Game"));
 connect(newg, SIGNAL(clicked()), this, SLOT(gamestart()));
 
 pause = new QPushButton(tr("Pause"));
 connect(pause, SIGNAL(clicked()), this, SLOT(pauz()));
 
 qgl->addWidget(quit, 0, 3); 
 qgl->addWidget(pause, 0, 2); 
 qgl->addWidget(newg, 0, 1);
 
 qg2->addWidget(nom,0,2);
 qg2->addWidget(nomlab,0,1); 
 
 scene->setSceneRect(0,0,800,800);
 view->fitInView(0, 0, 800, 800);
 
 //QGraphicsPixmapItem item( QPixmap::fromImage(image));
 qfl->addRow(view);
 qfl->addRow(qgl);
 qfl->addRow(qg2);
 
 setLayout(qfl); /**Establish Final Layout*/
 
 V = new QGraphicsSimpleTextItem("    MYSTERY\nSPECTACULAR\n  ADVENTURE");
 xgroup.push_back(V);
 QBrush White(Qt::green); V -> setBrush(White);
 V ->setFont(QFont("New York", 50, QFont::Bold));
 V ->setPos(130,232);
 scene->addItem(V);
 
 V = new QGraphicsSimpleTextItem("Use The Space Bar To Shoot\n   Use Arrow Keys To Move\n   Protect Your Home Farm");
 xgroup.push_back(V);
 QBrush CC(Qt::green); V -> setBrush(CC);
 V ->setFont(QFont("New York", 20, QFont::Bold));
 V ->setPos(180,566);
 scene->addItem(V);
 
 timer = new QTimer(this);
 timer->setInterval(11);
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
				    bullet *temp = new bullet(btt, player->gety(),player->getx()+22.5);
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
    
    //This is how we get our view displayed.
    this->show();
}

void MyWidget::handleTimer()
	{
	 while(lpoop<weightwatchers)
	 	{
	 	 
	 	 if(bonghits<10)
	 	 	{
	 	 	 med *temp = new med(mt, 0, (40+(rand()%720)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<25&&bonghits>=10)
	 	 	{
	 	 	 ufo *temp = new ufo(uf, 0, (200+(rand()%400)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<40&&bonghits>=25)
	 	 	{
	 	 	 sat *temp = new sat(stt, 0, (250+(rand()%300)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<60&&bonghits>=40)
	 	 	{
	 	 	 weightwatchers =4;
	 	 	 spy *temp = new spy(invade, 0,  (200+(rand()%400)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits<77&&bonghits>=60)
	 	 	{
	 	 	 weightwatchers =4;
	 	 	 pdp *temp = new pdp(pink, 0,  (200+(rand()%400)));
	 	 	 scene->addItem(temp);
	 	 	 egroup.push_back(temp);
	 	 	}
	 	 if(bonghits>=77)
	 	 	{
	 	 	 poo *temp = new poo(poop, 0, (40+(rand()%720)));
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
	 	 	 if (lives<=0)
	 	 	 	{
	 	 	 	 cleararea();
	 	 	 	 holding = true;
	 	 	 	 stringstream ss;
    	 			 ss<<score;
				 string text = ss.str();
				 const char * c = text.c_str();
			 
				 Score = new QGraphicsSimpleTextItem(c);
				 xgroup.push_back(Score);
			 	 QBrush White(Qt::cyan); Score -> setBrush(White);
			 	 Score ->setFont(QFont("New York", 50, QFont::Bold));
			 	 Score ->setPos(250,400);
			 	 scene->addItem(Score);
	 	 	 	 return;
	 	 	 	}
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
	 
	if(!xgroup.empty())
		{
	 	 for(vector<QGraphicsSimpleTextItem*>::iterator yyz =xgroup.begin();yyz!=xgroup.end();)
	 	 	{
	 	 	scene->removeItem(*yyz);
	 	 	delete * yyz;
	 	 	yyz = xgroup.erase(yyz);
	 	 	//if(!xgroup.empty()){++yyz;}
	 	 	}
	 	 
		}
	 stringstream ss;
    	 ss<<score;
    	 string text = ss.str();
    	 const char * c = text.c_str();
	 
		 Score = new QGraphicsSimpleTextItem(c);
		 xgroup.push_back(Score);
	 	 QBrush White(Qt::cyan); Score -> setBrush(White);
	 	 Score ->setFont(QFont("New York", 25, QFont::Bold));
	 	 Score ->setPos(350,50);
	 	 scene->addItem(Score);
	}
	
void MyWidget::gamestart()
	{
	 if(nom->text()=="")
	 	{return;}
	 lives = 2; score = 0; bonghits = 0; lboom = 0; lpoop = 0; weightwatchers = 3; ggallin = 0; i=-1;
	 if (holding == false)
	 	{cleararea();}
 	 if(!xgroup.empty())
		{
 	 	for(vector<QGraphicsSimpleTextItem*>::iterator yyz =xgroup.begin();yyz!=xgroup.end();)
	 	 	{
	 	 	scene->removeItem(*yyz);
	 	 	delete * yyz;
	 	 	yyz = xgroup.erase(yyz);
	 	 	}
		}
	 holding = false;
	 center = new city(c1, 700, 0);
 	 player = new pship(sp, 620, 400);
 	 scene->addItem(player); 
 	 scene->addItem(center);
	 setFocus();
	 if(!timer->isActive())
	 	{timer->start();}
	}
	
void MyWidget::pauz()
	{
	 if(timer->isActive())
	 	{
	 	 timer->stop();
	 	}
	 else{timer->start();}
	}
	
void MyWidget::cleararea()
	{
	 timer->stop();
 	 scene->removeItem(player);
 	 delete  player;
 	 scene->removeItem(center);
 	 delete  center;
 	 holding = false;
	 if(!xgroup.empty())
		{
	 	 for(vector<QGraphicsSimpleTextItem*>::iterator yyz =xgroup.begin();yyz!=xgroup.end();)
	 	 	{
	 	 	scene->removeItem(*yyz);
	 	 	delete * yyz;
	 	 	yyz = xgroup.erase(yyz);
	 	 	}
		}
	 vector<enemy*>::iterator it =egroup.begin();
	 while(!egroup.empty())
	 	{
	 	 scene->removeItem(*it);
	 	 delete * it;
	 	 it = egroup.erase(it);
	 	}
	 vector<bullet*>::iterator jj =bgroup.begin();
	 while(!bgroup.empty())
	 	{
	 	 scene->removeItem(*jj);
	 	 delete * jj;
	 	 jj = bgroup.erase(jj);
	 	}


	}


