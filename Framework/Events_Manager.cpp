#include "Events_Manager.h"
#include "SDL2/SDL.h"

#include <iostream>

Events_Manager* Events_Manager::singleton = nullptr;

Events_Manager::Events_Manager()
{
}

Events_Manager* Events_Manager::Get()
{
    if(singleton == nullptr)
        singleton = new Events_Manager();

    return singleton;
}

void Events_Manager::RefreshKeys()
    {
    //przypisywanie aktualnej tablicy stanów do poprzedniej
    previous_keys_state = keys_pressed;
    SDL_PollEvent(&singleton->event);
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    SDL_GetMouseState(&singleton->mouse_x, &singleton->mouse_y);

    //uaktualnianie tablicy stanów
    for(std::map<SDL_Keycode,bool>::iterator it = keys_pressed.begin(); it != keys_pressed.end(); ++it)
    {
        keys_pressed[it->first] = state[SDL_GetScancodeFromKey(it->first)];
        keys_clicked[it->first] = (!keys_pressed[it->first] && previous_keys_state[it->first]);
    }
}

bool Events_Manager::IsClicked(SDL_Keycode key_code)
{
    if(keys_pressed.find(key_code) == keys_pressed.end())
        keys_pressed[key_code] = false;
    return keys_clicked[key_code];
}

bool Events_Manager::IsPressed(SDL_Keycode key_code)
{
    return keys_pressed[key_code];
}
