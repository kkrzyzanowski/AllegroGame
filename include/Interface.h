#ifndef INTERFACE_H
#define INTERFACE_H
#include "Initializer.h"
class Interface
{
    public:
        Interface();
        virtual ~Interface();
        void draw_apples(int index);
        void menu(int option);
        void run();
        Initializer init;
    protected:
        int option_game;
         ALLEGRO_EVENT_QUEUE *ieq;

    private:
        bool redraw;
        bool in_game;
        bool is_created;



};

#endif // INTERFACE_H
