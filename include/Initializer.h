#ifndef INITIALIZER_H
#define INITIALIZER_H
#include<allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

const int WIDTH = 800;
const int HEIGHT = 600;
const int FPS = 60;

class Initializer
{


    public:


        Initializer();
        virtual ~Initializer();
        void initialization();
        ALLEGRO_DISPLAY* getAllegro_Display();
        ALLEGRO_EVENT_QUEUE* getAllegro_Event_Queue();
        ALLEGRO_FONT* getFont();
    protected:
        ALLEGRO_TIMER *timer = NULL;
        ALLEGRO_FONT *font;
        ALLEGRO_DISPLAY *display = NULL;
        ALLEGRO_EVENT_QUEUE *event_queue;


    private:
};

#endif // INITIALIZER_H
