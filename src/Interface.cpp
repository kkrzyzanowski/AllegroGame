#include "Interface.h"

Interface::Interface()
{

}

Interface::~Interface()
{
    //dtor
}

void Interface::menu(int option)
{
    int temp_postion = 100;
    int space = 100;
    switch(option)
    {

        {
            case 0:
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_text(init.getFont(),al_map_rgb(0,100,200), WIDTH/2, temp_postion,
                 ALLEGRO_ALIGN_CENTRE, "START");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion+space,
                 ALLEGRO_ALIGN_CENTRE, "REKORDY");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion+space*2,
                 ALLEGRO_ALIGN_CENTRE, "WYJSCIE");
                al_flip_display();

            break;
            case 1:
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion,
                 ALLEGRO_ALIGN_CENTRE, "START");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,200), WIDTH/2, temp_postion+space,
                 ALLEGRO_ALIGN_CENTRE, "REKORDY");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion+space*2,
                 ALLEGRO_ALIGN_CENTRE, "WYJSCIE");
                al_flip_display();
            break;
            case 2:
                al_clear_to_color(al_map_rgb(0,0,0));
                al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion,
                 ALLEGRO_ALIGN_CENTRE, "START");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,100), WIDTH/2, temp_postion+space,
                 ALLEGRO_ALIGN_CENTRE, "REKORDY");
                 al_draw_text(init.getFont(),al_map_rgb(0,100,200), WIDTH/2, temp_postion+space*2,
                 ALLEGRO_ALIGN_CENTRE, "WYJSCIE");
                al_flip_display();
            break;

        }
    }
}
void Interface::run()
{
        init.initialization();
        redraw = false;
        in_game = false;
        option_game = 0;
        menu(option_game);
        is_created = true;
}

