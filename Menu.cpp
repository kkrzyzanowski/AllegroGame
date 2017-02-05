#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

class GamePlay: public Gra
{
public:
    {
        void main_game(); // gra glowna
    };
private:
    {
        bool przerysowanie_w_grze; // mozliwosc odswiezenia w grze
        int checked;
        bool all_checked;
        bool one_checked;


        std:: vector <unsigned int> pos_x;
        std:: vector <unsigned int> pos_y;
        unsigned int val_positions; // ilosc pozycji x i y

    };
};
void GamePlay::main_game()
{
    srand(time(NULL));
    while(!exit)
    {
    if(!przerysowanie_w_grze && !all_checked)
        {
            al_clear_to_color(al_map_rgb(0,0,0));
            for(int i=0; i<=val_positions;i++)
            {
                pos_x.push_back(losowe(WIDTH-apple_size));
                pos_y.push_back(losowe(HEIGHT-apple_size));
                draw_apples(i);
            }
            przerysowanie_w_grze = true;
        }
    al_wait_for_event(event_queue, &ev);
    if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        mouse_on();
    }

    else if(Gra().ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
        mouse_off();
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        przerysowanie_w_grze=true;
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
        exit = true;
        break;
    }
    if(przerysowanie_w_grze)
    {

        przerysowanie_w_grze=false;
        mouse_game_action();
    }
    }

}
int GamePlay::losowe(int param)
{
    int random = rand()% param + 32;
    return random;
}
void GamePlay::mouse_on()
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
void GamePlay::mouse_off()
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
void GamePlay::mouse_game_action()
{
    bool quit_loop = false;

    for(int h = 0; h<=val_positions; h++)
        {
            for(int i = pos_x[h]; i<pos_x[h]+apple_size;i++)
            {
                for(int j = pos_y[h]; j<pos_y[h]+apple_size;j++)
                {
                    if(ev.mouse.x==i && ev.mouse.y==j && key[MOUSE_BUTTON_1])
                    {
                        al_clear_to_color(al_map_rgb(0,0,0));
                        for(int k=0; k<=val_positions; k++)
                        {
                            if(k!=h && key[MOUSE_BUTTON_1])
                            {
                                    draw_apples(k);
                            }
                        }
                        one_checked = true;
                        if(checked==val_positions)
                            all_checked = true;

                        quit_loop=true;
                        break;
                    }
                }
            }
            if(quit_loop)
                break;
        }
        if(one_checked)
        {
             checked++;
             one_checked=false;
        }

        if(all_checked)
        {
            al_clear_to_color(al_map_rgb(0,0,0));
            al_flip_display();
            apples.push_back(al_create_bitmap(apple_size,apple_size));
            pos_x.clear();
            pos_y.clear();
            val_positions++;
            all_checked = false;
            checked = 0;
        }

}
void GamePlay::draw_apples(int index)
{
    al_set_target_bitmap(apples[index]);
    al_clear_to_color(al_map_rgb(100,100,100));
    al_set_target_bitmap(al_get_backbuffer(display));
    al_draw_bitmap(apples[index], pos_x[index], pos_y[index], 0);
    al_flip_display();
}
