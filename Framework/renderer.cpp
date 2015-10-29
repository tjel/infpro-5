#include "renderer.h"
#include "drawround.h"


Renderer::Renderer()
{

}

Renderer* Renderer::Render()
{
    DrawRound::GetInstance()->DrawAll();
    return this;
}

