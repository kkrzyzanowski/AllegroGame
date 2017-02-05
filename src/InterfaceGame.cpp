#include "InterfaceGame.h"

InterfaceGame::InterfaceGame(ALLEGRO_DISPLAY* d, ALLEGRO_FONT* f)
:disp(d), font(f)
{
    apple_size = 32;
    redraw_in_game = false;
    all_checked = false;
    initialize_random =false;
    value_apples = 0;
}

InterfaceGame::~InterfaceGame()
{
    //dtor
}
int InterfaceGame::random(int param)
{
    if(!initialize_random)
    {
        srand(time(NULL));
        initialize_random = true;
    }
    int random = rand()% param;
    return random;
}
void InterfaceGame::pushApple()
{
apples.push_back(al_create_bitmap(apple_size, apple_size));//bitmapa
if(!apples[0])
        {
            al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 9", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
value_apples = apples.size() - 1;
}
bool InterfaceGame:: isChecked(int index)
{
    vector<int>::iterator iCheckedApples = find(checked_apples.begin(), checked_apples.end(), index);
    if(iCheckedApples!=checked_apples.end())
    {
        return true;
    }
    return false;
}
void InterfaceGame::refresh_map()
{
    al_clear_to_color(al_map_rgb(0,0,0));
            for(int i=0; i<=value_apples;i++)
            {
                if(!isChecked(i))
                {
                    drawApples(i);
                }
            }
}
void InterfaceGame:: checkApples()
{
            al_clear_to_color(al_map_rgb(0,0,0));
            for(int i=0; i<=value_apples;i++)
            {
                pos_x.push_back(random(WIDTH-apple_size)+1);
                pos_y.push_back(random(HEIGHT-apple_size)+1);
                drawApples(i);
            }
}
void InterfaceGame::drawApples(int index)
{
    al_set_target_bitmap(apples[index]);
    al_clear_to_color(al_map_rgb(100,100,100));
    al_set_target_bitmap(al_get_backbuffer(disp));
    al_draw_bitmap(apples[index], pos_x[index], pos_y[index], 0);
    al_flip_display();
}
void InterfaceGame::clear_positions()
{
    pos_x.clear();
    pos_y.clear();
}
void InterfaceGame::GameOver()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(0,100,200), WIDTH/2, HEIGHT/2-font->height,
                 ALLEGRO_ALIGN_CENTER, "GAME OVER");
    al_flip_display();

}
vector<int> InterfaceGame::getPos_x()
{
    return pos_x;
}
vector<int> InterfaceGame::getPos_y()
{
    return pos_y;
}
int InterfaceGame::getValue_apples()
{
    return value_apples;
}
vector<int> InterfaceGame::getCheckedApples()
{
    return checked_apples;
}
void InterfaceGame::nextRound()
{
    clear_positions();
    pushApple();
    checkApples();
    drawApples(value_apples);
}
