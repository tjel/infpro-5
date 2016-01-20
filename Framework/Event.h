#ifndef EVENT_H
#define EVENT_H

#include <functional>
#include <SDL2/SDL.h>

class Event
{
public:
    Event(std::function<void()> _slot, SDL_Keycode _key_code);
    Event();

    void SetSlot(std::function<void()> _slot);
    void SetKeyCode(SDL_Keycode _key_code);

    SDL_Keycode GetKeyCode();
    std::function<void()> GetSlot();

    void AddToQueue();
private:
    SDL_Keycode key_code;
    std::function<void()> slot;
};

#endif // EVENT_H
