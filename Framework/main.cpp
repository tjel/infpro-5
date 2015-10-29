#include <iostream>
#include "shape.h"
#include "renderer.h"

#include "drawround.h"


using namespace std;

int main()
{
    Shape* sh1;
    sh1 = new Shape("Manualny");

    sh1->AddToRound();

    Shape* sh2;
    sh2 = new Shape("Dynamiczny");

    DrawRound::GetInstance()->AddToRound(sh2);

    Renderer r;
    r.Render();
    return 0;
}

