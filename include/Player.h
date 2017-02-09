#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;
class Player
{
    public:
        Player();
        virtual ~Player();
        int getPoints();
        void addPoints();
        string getName();
        void setName(string n);
        void clearPoints();

    protected:

    private:
        int points;
        string name;
};

#endif // PLAYER_H
