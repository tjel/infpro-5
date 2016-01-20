#ifndef EVENTS_QUEUE_H
#define EVENTS_QUEUE_H

#include <vector>
#include "../Event.h"

class Events_Queue
{
public:
    static Events_Queue* Get();

    void Execute();
    void AddToQueue(Event* _event);
private:
    static Events_Queue* singleton;
    Events_Queue();

    std::vector<Event*> events;
};

#endif // EVENTS_QUEUE_H
