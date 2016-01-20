#include "Draw_Queue.h"
#include <algorithm>

Draw_Queue* Draw_Queue::singleton = nullptr;

Draw_Queue::Draw_Queue()
{
}

Draw_Queue* Draw_Queue::Get()
{
    if(singleton == nullptr)
        singleton = new Draw_Queue();

    return singleton;
}

Draw_Queue* Draw_Queue::AddToQueue(Drawable_Object* obj)
{
    queue.push_back(obj);
    std::sort(queue.begin(), queue.end(), Drawable_Object::IsFirstPlaneFrom);
    return singleton;
}

Draw_Queue* Draw_Queue::DrawAll()
{
    for(unsigned int i = 0; i < queue.size(); i++)
        queue[i]->Draw();

    return singleton;
}

Draw_Queue* Draw_Queue::RemoveFromQueue(Drawable_Object* obj)
{
    std::vector<Drawable_Object*>::iterator it = find(queue.begin(), queue.end(), obj);
    if(it != queue.end())
    {
        queue.erase(it);
    }
    
    return singleton;
}
