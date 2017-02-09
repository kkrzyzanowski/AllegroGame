#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <vector>
#include <thread>
#include <stdlib.h>
#include "Control.h"
#include "Interface.h"
#include "InterfaceGame.h"
#include "timeCount.h"
#include "Player.h"
using namespace std;
class GamePlay: public Control, public Interface
{
    public:
        GamePlay();
        virtual ~GamePlay();
        int random(int param);
        void menu_loop();
        void find_apple(int index);
        int choice(int option);
        void menu_action();
        void game();
        void initialize_variables();
        void search_apples();
        void addFoundApple(int index);
        bool isChecked(int index);
        void reset_stage();
        void timeChecked();
        void back_to_menu();
        ALLEGRO_EVENT_QUEUE *geq;

    private:
        vector<int> checked_apples;
        int checked;
        bool all_checked;
        bool mouse_checked;
        bool exit; // definitywny
        bool found_apple_stage;
        InterfaceGame* initGame;
        bool start_game;
        time_t timer;
        time_t loop_timer;
        bool exit_game; // z gry do menu
        Player player;

};
#endif // GAMEPLAY_H
