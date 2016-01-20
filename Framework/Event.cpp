#include "Event.h"
#include "Events_Queue.h"

Event::Event()
{

}

std::function<void()> Event::GetSlot()
{
    return slot;
}

SDL_Keycode Event::GetKeyCode()
{
    return key_code;
}

void Event::SetKeyCode(SDL_Keycode _key_code)
{
    key_code = _key_code;
}

void Event::SetSlot(std::function<void()> _slot)
{
    slot = _slot;
}

void Event::AddToQueue()
{
    Events_Queue::Get()->AddToQueue(this);
}


