#ifndef CONTROL_H
#define CONTROL_H
#include "Initializer.h"
#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>


class Control
{

public:

        Control();
        void key_event(ALLEGRO_EVENT_QUEUE* cev);
        void close();
        void mouse_on();
        void mouse_off();
        void search_mouse_event(ALLEGRO_EVENT_QUEUE* cev);
        void reset_keys();
        virtual ~Control();

protected:

        enum MYKEYS // klawisze i przyciski
        {
            KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER, MOUSE_BUTTON_1,
            MOUSE_BUTTON_2, MOUSE_BUTTON_3
        };
        bool hold;



        bool przerysowanie;
        bool in_game;
        bool przerysowanie_w_grze; // nie powinny nalezec do kontroli
        bool exit;
        int opcja;
        bool key[8];
        ALLEGRO_EVENT ev;

};

#endif // CONTROL_H
