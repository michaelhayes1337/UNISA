#ifndef COORDINATE_H
#define COORDINATE_H
#include <string>
#include <QChar>
using namespace std;

class Coordinate
{
public:
    Coordinate(int deg, int min, int sec, QChar direction);
    QString toString();
    double toDecimal();
private:
    int degrees,minutes,seconds;
    QChar direction;
};

#endif // COORDINATE_H
