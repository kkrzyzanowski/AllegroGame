#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>


class Control
{

public:

        Control();
        void klawisz_wycisniety();
        void klawisz_wcisniety();
        void close();

private:

        bool key[8]={false, false, false, false, false, false, false, false};
        enum MYKEYS // klawisze i przyciski
        {
            KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER, MOUSE_BUTTON_1,
            MOUSE_BUTTON_2, MOUSE_BUTTON_3
        };
        bool przytrzymany;
        static ALLEGRO_EVENT ev;

};

void Control::klawisz_wycisniety()
{
    switch(ev.keyboard.keycode)
   {
   case ALLEGRO_KEY_UP:
    key[KEY_UP]=false;
    przytrzymany = false;
    break;
   case ALLEGRO_KEY_DOWN:
    key[KEY_DOWN]=false;
    przytrzymany = false;
    break;
     case ALLEGRO_KEY_ENTER:
    key[KEY_ENTER]=false;
    break;
    }
}
void Control::klawisz_wcisniety()
    {
        switch(ev.keyboard.keycode)
        {
            case ALLEGRO_KEY_UP:
                key[KEY_UP]=true;
                break;
            case ALLEGRO_KEY_DOWN:
            key[KEY_DOWN]=true;
                break;
            case ALLEGRO_KEY_ENTER:
                key[KEY_ENTER]=true;
                break;
        }
}
Control::Control()
{
    przytrzymany = false;
}

void Control::close()
{

    int temp_loop;
    bool start= false;
    while(!exit)
    {
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            exit = true;
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if(!start)
            {
                menu(0);
                start = true;
            }
            przerysowanie = true;
            temp_loop=wybor();
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            klawisz_wcisniety();
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            klawisz_wycisniety();
        }

        if(przerysowanie && al_is_event_queue_empty(event_queue))
        {
            przerysowanie = false;
            if(!in_game)
            {
                menu(temp_loop); // tutaj obiekt menu
                al_flip_display();
            }
            if (opcja == 0 && key[KEY_ENTER])
            {
                in_game = true;
                GamePlay gamePlay;
            }
        }

    }
}
