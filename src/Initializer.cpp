#include "Initializer.h"
Initializer::Initializer()
{

}

Initializer::~Initializer()
{

}
 void Initializer::initialization()
{
        if(!al_init()) //allegro
        {
            al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 1", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
        if(!al_install_keyboard())//klawiatura
        {
            al_show_native_message_box(al_get_current_display(),
            "Blad", "Timer failed", "Error 6", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
        if(!al_install_mouse())//mysz
        {
            al_show_native_message_box(al_get_current_display(),
            "Blad", "Timer failed", "Error 6", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
         timer=al_create_timer(1.0/FPS);
        //timer
        if(!timer)
        {
            al_show_native_message_box(al_get_current_display(),
            "Blad", "Timer failed", "Error 4", NULL, ALLEGRO_MESSAGEBOX_ERROR);

        }


       //zdarzenia
       event_queue=al_create_event_queue();
        if(!event_queue)
        {

            al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 3", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
        al_init_font_addon();
        al_init_ttf_addon();

        font = al_load_ttf_font("SimplySquare_0.ttf",50,0);
        if(!font)//czcionka

        {
            al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 3", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
        fontTwo = al_load_ttf_font("BenchNine-Regular.otf", 40, 0);
        if(!fontTwo)//Twocionka

        {
            al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 3", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        }
         //okno
          display = al_create_display(WIDTH,HEIGHT);
        if(!display)
        {
                al_show_native_message_box(al_get_current_display(),
                                "Blad", "Inicjalizacja failed",
                                "Error 2", NULL, ALLEGRO_MESSAGEBOX_ERROR);
          }

        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_mouse_event_source());
        al_clear_to_color(al_map_rgb(0,0,0));
        al_flip_display();
        al_start_timer(timer);

}
ALLEGRO_DISPLAY* Initializer::getAllegro_Display()
{
    return display;
}
ALLEGRO_EVENT_QUEUE* Initializer::getAllegro_Event_Queue()
{
    return event_queue;
}
ALLEGRO_FONT* Initializer::getFont()
{
    return font;
}
ALLEGRO_FONT* Initializer::getFontTwo()
{
    return fontTwo;
}
