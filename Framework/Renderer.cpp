#include "Renderer.h"
#include "Draw_Queue.h"

Renderer::Renderer()
{

}

Renderer* Renderer::Render()
{
    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    /* Move Left 1.5 Units And Into The Screen 6.0 */
    glLoadIdentity();
    glTranslatef( -1.5f, 0.0f, -6.0f );



    Draw_Queue::GetInstance()->DrawAll();
    SDL_RenderPresent(display_renderer);
    return this;
}

