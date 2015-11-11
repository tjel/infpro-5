#include "Draw_Queue.h"

Draw_Queue* Draw_Queue::instance = nullptr;

Draw_Queue::Draw_Queue()
{

}

Draw_Queue* Draw_Queue::GetInstance()
{
    if(instance==nullptr)
        instance = new Draw_Queue();

    return instance;
}

Draw_Queue* Draw_Queue::AddToQueue(Drawable_Object *obj)
{
    queue.push_back(obj);

    return instance;
}

Draw_Queue* Draw_Queue::DrawAll()
{
    for(unsigned int i=0; i<queue.size(); i++)
        queue[i]->Draw();

    return instance;
}
