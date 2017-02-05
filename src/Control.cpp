#include "Control.h"

Control::Control()
{
    reset_keys();
}

Control::~Control()
{
    //dtor
}
void Control::reset_keys()
{
    for(int i=0;i<8;i++)
    {
        key[i]=false;
    }
    hold = false;
}
void Control::mouse_on()
{
    switch(ev.mouse.button)
    {
    case 1:
        key[MOUSE_BUTTON_1]=true;
        break;
    case 2:
        key[MOUSE_BUTTON_2]=true;
        break;
    case 3:
        key[MOUSE_BUTTON_3]=true;
        break;
    }
}
void Control::mouse_off()
{
    switch(ev.mouse.button)
    {
    case 1:
        key[MOUSE_BUTTON_1]=false;
        break;
    case 2:
        key[MOUSE_BUTTON_2]=false;
        break;
    case 3:
        key[MOUSE_BUTTON_3]=false;
        break;
    }

}
void Control::key_event(ALLEGRO_EVENT_QUEUE* cev)
{
     al_wait_for_event(cev, &ev);
     if(ev.type == ALLEGRO_EVENT_KEY_UP)
     {

            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP]=false;
                    hold = false;
                    break;
                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN]=false;
                    hold = false;
                    break;
                case ALLEGRO_KEY_ENTER:
                    key[KEY_ENTER]=false;
                    hold = false;
                    break;
            }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
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


}
/*void Control::mouseButtonActive()
{

}*/
void Control::search_mouse_event(ALLEGRO_EVENT_QUEUE *cev )
{
    al_wait_for_event(cev, &ev);
    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        mouse_on();
    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        mouse_off();
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        przerysowanie_w_grze=true;
    }
    if(przerysowanie && al_is_event_queue_empty(cev))
        {
            przerysowanie = false;
            if(!in_game)
            {
                al_flip_display();
            }
            if (opcja == 0 && key[KEY_ENTER])
            {
                in_game = true;
            }
        }
}
