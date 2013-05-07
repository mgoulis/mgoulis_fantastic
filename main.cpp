#include <iostream>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "mainwindow.h"
using namespace std;

/** @mainpage CSCI 102 PA6
@author Michael Goulis
@section purpose Purpose/Overview
Create A 2D Space Shooter Where The Player Must Defend Their Ship And Home Farm

@section requirements Requirements
record the players high score to a file;	
create diffentent distince levels with changing background; 	
create 2 objects that track player movement



*/

int main(int argc, char *argv[])
{
 QApplication app(argc, argv);
 MyWidget widget;
 widget.setGeometry(0,0,658,570);
 widget.live();
 return app.exec();
}


