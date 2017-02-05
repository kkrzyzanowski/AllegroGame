#ifndef TIMECOUNT_H
#define TIMECOUNT_H
#include <time.h>
using namespace std;
class timeCount
{
    public:
        timeCount();
        static bool isDiffEnough(long timeStart, long timePast, double period);
        virtual ~timeCount();

    protected:
    private:
};

#endif // TIMECOUNT_H
