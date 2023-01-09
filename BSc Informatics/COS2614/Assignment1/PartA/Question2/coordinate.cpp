#include "coordinate.h"
#include <string>
#include <QChar>
#include <QTextStream>
#include <QString>
using namespace std;

Coordinate::Coordinate(int deg, int min, int sec, QChar direc):degrees(deg), minutes(min), seconds(sec), direction(direc)
{
    //body
}

QString Coordinate::toString(){
    QString result = QString::number(degrees) + QChar(0260) + " " + QString::number(minutes) + "' " + QString::number(seconds) + "'' " + direction ;
    return result;
}

double Coordinate::toDecimal(){
    QChar s('S');
    QChar w('W');
    double result =  degrees + (minutes/60.0) + (seconds/3600.0);
    //if south or west convert to negative
    if(direction == s || direction == w){
        result *= -1;
    }
    return result;
}
