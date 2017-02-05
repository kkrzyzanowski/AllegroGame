#include "timeCount.h"

timeCount::timeCount()
{
    //ctor
}

timeCount::~timeCount()
{
    //dtor
}
bool timeCount::isDiffEnough(long timeStart, long timePast, double period)
{
    double dt = difftime(timeStart, timePast);
    if(dt>period)
        return true;
    else
        return false;
}
