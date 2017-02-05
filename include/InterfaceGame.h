#ifndef INTERFACEGAME_H
#define INTERFACEGAME_H
#include <vector>
#include <algorithm>
#include <allegro5/allegro_native_dialog.h>
#include "Initializer.h"
using namespace std;
class InterfaceGame
{
    public:
        std:: vector <ALLEGRO_BITMAP*> apples;
         vector<int> pos_x;
       vector<int> pos_y;
       vector<int> checked_apples;
        void pushApple();
        void checkApples();
        void drawApples(int index);
        int random(int param);
        void nextRound();
        InterfaceGame(ALLEGRO_DISPLAY* d, ALLEGRO_FONT* f);
        virtual ~InterfaceGame();
        vector<int> getPos_x();
        vector<int> getPos_y();
        vector<int> getCheckedApples();
        void clear_positions();
        int getValue_apples();
        bool isChecked(int index);
        void refresh_map();
        void GameOver();
        int apple_size;

    protected:

    private:




        bool redraw_in_game;
        bool all_checked;
        bool initialize_random;
        int value_apples;
        ALLEGRO_DISPLAY* disp;
        ALLEGRO_FONT* font;


};

#endif // INTERFACEGAME_H
