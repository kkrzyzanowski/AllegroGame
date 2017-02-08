#include "GamePlay.h"

GamePlay::GamePlay()
{

    Interface::run();
    initGame = new InterfaceGame(init.getAllegro_Display(), init.getFont());
    initialize_variables();
    menu_loop();

}

GamePlay::~GamePlay()
{
    //dtor
}

void GamePlay::menu_loop()
{
    start_game = false;
    while(!exit)
    {
        if(!start_game)
        {

            option_game = choice(option_game);
            menu(option_game);
            key_event(Interface::init.getAllegro_Event_Queue());
            menu_action();

        }
    }
}
void GamePlay::find_apple(int index)
{
    if(!initGame->isChecked(index))
        {
            for(int i = initGame->pos_x[index]; i<(initGame->pos_x[index])+initGame->apple_size;i++)
            {
                for(int j = initGame->pos_y[index]; j<(initGame->pos_y[index])+initGame->apple_size;j++)
                {

                    if(ev.mouse.x==i && ev.mouse.y==j && key[MOUSE_BUTTON_1])
                    {
                        mouse_checked = true;
                    }
                }
            }
        }

        if(checked>initGame->getValue_apples())
        {
            found_apple_stage = true;
        }
}
int GamePlay::choice(int option)
{
    if(key[KEY_UP] && !hold)
    {
    option--;
    if(option<0)
        option=0;
    hold = true;
    }
    if(key[KEY_DOWN] && !hold)
    {
        option++;
    if(option>2)
        option=2;
    hold = true;
    }
    return option;
}
void GamePlay::menu_action()
{
    if(key[KEY_ENTER])
    {
        switch(option_game)
        {
        case 0:
            start_game = true;
            Interface::instructionGame();
            timeCount::countTime(10.0);
            game();
            break;
        case 1:
            break;
        case 2:
            exit = true;
        }
    }
}
void GamePlay::timeChecked()
{
    time(&loop_timer);
    if(timeCount::isDiffEnough(loop_timer, timer, 5.0))
    {
        exit_game = true;
    }

}
void GamePlay::addFoundApple(int index)
{
    if(mouse_checked)
        {
            initGame->checked_apples.push_back(index);
             checked++;
            mouse_checked=false;
        }
}

void GamePlay::reset_stage()
{
    checked = 0;
    initGame->checked_apples.clear();
}

void GamePlay::search_apples() // szukamy jablek i po kolei je klikamy
{
//    mouseControl(search_mouse_event, init.getAllegro_Event_Queue());
//   mouseControl.join();
    time(&timer);
    int value_index = 0;
    while(checked<=initGame->getValue_apples())
    {
        search_mouse_event(Interface::init.getAllegro_Event_Queue());
        find_apple(value_index);
        addFoundApple(value_index);
        initGame->refresh_map();
        value_index++;
        if(value_index>initGame->getValue_apples())
            value_index = 0;
        timeChecked();
        if(exit_game)
            break;
    }
    reset_stage();
}
void GamePlay::game()
{
    while(!found_apple_stage && !exit_game)
    {
        initGame->nextRound();
        search_apples();
    }
    time(&timer);
    time(&loop_timer);
    while(!timeCount::isDiffEnough(loop_timer, timer, 10.0))
    {
        initGame->GameOver();
        time(&loop_timer);
    }
    back_to_menu();

}
void GamePlay::back_to_menu()
{
    reset_keys();
    initialize_variables();
    start_game = false;
}
void GamePlay::initialize_variables()
{
    found_apple_stage = false;
    exit = false;
    checked = 0;
    mouse_checked = false;
    exit_game = false;
    initGame->apples.clear();
}
