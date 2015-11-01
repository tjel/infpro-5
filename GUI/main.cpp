#include <include/MenagerResource.h>
#include <include/CRenderer.h>
int main(int argc, char *argv[])
{
        MenagerResource Load("Black.txt");
        //First clear the renderer
        SDL_RenderClear(CRenderer::GetRenerer()->mRender);
        //Draw the texture
        //Update the screen
        SDL_RenderPresent(CRenderer::GetRenerer()->mRender);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
}

