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
void Interface::instructionGame()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_text(init.getFontTwo(), al_map_rgb(30,240,30), WIDTH/2, 2*(HEIGHT/10),
                 ALLEGRO_ALIGN_CENTER, "WITAJ W GRZE CATCH APPLES!");
    string text = "Twoim zadaniem jest zebranie jak najwiekszej ilosci jablek. Na kazdy etap masz 5 sekund. W czasie ich trwania musisz zebrac jak najwiecej jablek. Z kazda sekunda liczba jablek bedzie coraz wieksza.";
    setAllegroText(WIDTH/10, WIDTH-(WIDTH/10), init.getFontTwo()->height*2/3, text);
    al_flip_display();
}
void Interface::setAllegroText(int startPoint, int endPoint, int spaceLine, string text)
{
    int lengthText = al_get_text_width(init.getFontTwo(), text.c_str());
    int lineText= endPoint - startPoint;
    int valueLine = ceil(lengthText*1.0/lineText*1.0);
    int valueSings = text.length();
    int valueSingsLine = round(valueSings*1.0/valueLine*1.0);
    divideText(text, valueSingsLine, 0);
    vector<string>:: iterator iGameText = partsText.begin();
    int temp = 3*(HEIGHT/10);
    for(iGameText; iGameText!=partsText.end();iGameText++)
    {
         al_draw_text(init.getFontTwo(), al_map_rgb(40,240,40), WIDTH/2, temp,
                 ALLEGRO_ALIGN_CENTER, iGameText->c_str());
                temp = temp+spaceLine;
    }

}
void Interface::divideText(string text, int signs, int index)
{

    string line;
    bool end_text = false;
    if(text.length()>signs)
        line.append(text.substr(0, signs));
    else
    {
        line.append(text.substr(0, text.length()));
        end_text = true;
    }

    size_t numberOfSign = (size_t)line.rfind(" ");
    if(numberOfSign!=signs-1 && !end_text)
    {
        string thisLine = line.substr(0, numberOfSign);
        string partNextLine = line.substr(numberOfSign, signs);
        partsText.push_back(thisLine);
        line.clear();
        line = partNextLine + line.append(text.substr(signs, (int)text.size()));
    }
    else if(numberOfSign == signs-1)
    {
        partsText.push_back(line);
        line.clear();
        line = line.append(text.substr(signs, (int)text.size()));
    }
    else
    {
        partsText.push_back(line);
        line = line.append(text.substr(0, text.length()));
    }
    if(!end_text)
    {
      divideText(line, signs, index);
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

