#ifndef INTERFACE_H
#define INTERFACE_H
#include <vector>
#include <string>
#include <cmath>
#include "Initializer.h"
using namespace std;
class Interface
{
    public:
        Interface();
        virtual ~Interface();
        void draw_apples(int index);
        void menu(int option);
        void run();
        void instructionGame();
        Initializer init;
        void setAllegroText(int startPoint, int endPoint, int spaceLine, string text);
        void divideText(string text, int signs, int index);
    protected:
        int option_game;
         ALLEGRO_EVENT_QUEUE *ieq;

    private:
        bool redraw;
        bool in_game;
        bool is_created;
        vector<string> partsText;



};

#endif // INTERFACE_H
