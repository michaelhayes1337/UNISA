#ifndef GPSCOORD_H
#define GPSCOORD_H
#include "coordinate.h"
#include <QChar>
using namespace std;

class GPSCoord
{
    public:
        GPSCoord();
        ~GPSCoord();
        GPSCoord(const GPSCoord& g);
        GPSCoord& operator=(const GPSCoord& g);
        void setCoord(int d, int m, int s, QChar dir);
        QString toString(bool decimal);
    private:
        Coordinate* latitude;
        Coordinate* longitude;
};

#endif // GPSCOORD_H
