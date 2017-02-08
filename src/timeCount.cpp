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
void timeCount::countTime(double period)
{
     time_t timer;
    time_t loop_timer;

    time(&timer);
    time(&loop_timer);
    while(!isDiffEnough(loop_timer, timer, period))
    {
        time(&loop_timer);
    }
}
