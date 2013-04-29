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
 lives = new int(1);
 score = new int(0);
 qfl = new QFormLayout;
 sp = new QPixmap("assets/ship.png"); 
 uf = new QPixmap("assets/UFO.png");
 player = new pship(sp, 450, 150);
 UFO1 = new ufo(uf,-300, 150); UFO2 = new ufo(uf,-600, 150); UFO3 = new ufo(uf,-800, 130); UFO4 = new ufo(uf,-900, 150); UFO5 = new ufo(uf,-1000, 150); UFO6 = new ufo(uf,-1050, 150);
 
 QBrush BBlack(Qt::black);
 scene->setSceneRect(0,0,300,500);
 scene->setBackgroundBrush(BBlack);
 
 
 //QGraphicsPixmapItem item( QPixmap::fromImage(image));
 
 scene->addItem(player); 
 scene->addItem(UFO1); scene->addItem(UFO2); scene->addItem(UFO3); scene->addItem(UFO4); scene->addItem(UFO5); scene->addItem(UFO6);
 qfl ->addRow(view);
 
 setFocus();
 setLayout(qfl); /**Establish Final Layout*/
 
 timer = new QTimer(this);
 timer->setInterval(10);
 connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}


void MyWidget::keyPressEvent( QKeyEvent *e ) {

switch ( e->key() ) {
		case Qt::Key_Left : player->setVx(-2);
				    break;

		case Qt::Key_Right :player->setVx(2);
				    break;

		//case Qt::Key_Up :{cout<<"U ";break;};

		//case Qt::Key_Down:{cout<<"D ";break;};;
		
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

		//case Qt::Key_Up :{cout<<"U ";break;};

		//case Qt::Key_Down:{cout<<"D ";break;};;
		    }
}



void MyWidget::live() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();
    //This is how we get our view displayed.
    qfl->update();
    this->show();
}

void MyWidget::handleTimer()
	{
	 i++;
	 player->manage();
	 UFO1->manage(i); UFO2->manage(i); UFO3->manage(i); UFO4->manage(i); UFO5->manage(i); UFO6->manage(i);
	 if(i>=50)
	   {i=-1;}
	}


