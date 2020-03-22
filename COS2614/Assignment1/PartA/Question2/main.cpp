#include <QCoreApplication>
#include "coordinate.h"
#include "gpscoord.h"
#include <iostream>
#include <QChar>
#include <QTextStream>
using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    //QT stream
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    //Initialisation variables
    int deg = 0;
    int min = 0;
    int sec = 0;
    QChar dir;
    //QT Variables
    QString cord1,cord2;
    QStringList list;
    //User Input
    cout << "Enter the first coordinate:" << endl;
    cord1 = cin.readLine();
    cout << "Enter the second coordinate:" << endl;
    cord2 = cin.readLine();
    //creating GPSCoord instance from user input
    GPSCoord gps = GPSCoord();
    list = cord1.split(" ");
    for(int i = 0 ; i < list.size(); i ++){
        switch (i) {
            case 0:
                deg = list.at(i).toInt();
                break;
            case 1:
                min = list.at(i).toInt();
                break;
            case 2:
                sec = list.at(i).toInt();
                break;
            case 3:
                dir = list.at(i)[0];
                break;
            default:
                break;
        }
    }
    gps.setCoord(deg,min,sec,dir);

    list = cord2.split(" ");
    for(int i = 0 ; i < list.size(); i ++){
        switch (i) {
            case 0:
                deg = list.at(i).toInt();
                break;
            case 1:
                min = list.at(i).toInt();
                break;
            case 2:
                sec = list.at(i).toInt();
                break;
            case 3:
                dir = list.at(i)[0];
                break;
            default:
                break;
        }
    }
    gps.setCoord(deg,min,sec,dir);
    //Output New GPSCoord Instance
    cout << "New GPSCoord Instance" << endl;
    cout << gps.toString(false) << endl;
    cout << gps.toString(true) << endl;
    //Create a copy of the existing instance
    GPSCoord copyGPS(gps);
    cout << "Copied GPSCoord Instance" << endl;
    cout << copyGPS.toString(false) << endl;
    //Create new default GPSCoord instance
    GPSCoord blank = GPSCoord();
    //Set the copied instance back to default values with =
    copyGPS = blank;
    cout << "Reset Copied GPSCoord Instance" << endl;
    cout << copyGPS.toString(false) << endl;
    gps.~GPSCoord();
    copyGPS.~GPSCoord();
    blank.~GPSCoord();
    return a.exec();
}
