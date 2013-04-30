#include <iostream>
#include <cstdlib>
#include <deque>
#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include "mainwindow.h"
using namespace std;

bool rootcheck(int);


int main(int argc, char *argv[])
{
 QApplication app(argc, argv);
 MyWidget widget;
 widget.setGeometry(0,0,658,570);
 widget.live();
 return app.exec();
}


