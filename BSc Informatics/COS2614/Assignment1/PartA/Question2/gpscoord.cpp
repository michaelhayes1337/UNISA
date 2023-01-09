#include "gpscoord.h"
#include "coordinate.h"
#include <QChar>
#include <QString>
#include <QDebug>
#include <string>
#include <iostream>

//Initialisation and testing variables
static QChar north('N');
static QChar south('S');
static QChar east('E');
static QChar west('W');
Coordinate c1(0,0,0,north), c2(0,0,0,east);


GPSCoord::GPSCoord(): latitude(&c1),longitude(&c2){
    //body
}

GPSCoord::~GPSCoord()
{
    //remove pointers from heap
    delete latitude;
    delete longitude;
}

void GPSCoord::setCoord(int d, int m, int s, QChar dir){
    //identify if lateral or longitudinal then create new coordinate instance and change the value of the object lati/longi are pointing to
    if(dir == north || dir == south){
        Coordinate lati(d,m,s,dir);
        *latitude = lati;
    }else if(dir == east || dir == west){
        Coordinate longi(d,m,s,dir);
        *longitude = longi;
    }
}

GPSCoord::GPSCoord(const GPSCoord& g):latitude(g.latitude), longitude(g.longitude) {
    qDebug("Instance Copied");
}

GPSCoord& GPSCoord::operator=(const GPSCoord& g){
    qDebug("Setting GPSCoord 1 = to GPSCoord 2");
    if(this != &g){
        latitude = g.latitude;
        longitude = g.longitude;
    }
    return *this;
}

QString GPSCoord::toString(bool decimal=false){
    QString output = "";
    if(decimal){
        output += QString::number(latitude->toDecimal()) + "\t" + QString::number(longitude->toDecimal());
    }else{
        output += latitude->toString() + "\t" + longitude->toString();
    }
    return output;
}
