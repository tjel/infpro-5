#include <iostream>
#include "Shape.h"
#include "Renderer.h"
#include "Engine.h"
#include "Sprite_Object.h"
#include "Event.h"

#include "Draw_Queue.h"
#include "RM.h"

/* Grzegorz Malkiewicz
 * Uzyje pliku main do opis co jeszcze jest do zrobienia
 * a co zostalo juz zrobione :
 *
 * - Kolejka rysowania
 * Juz jest ale tylko w podstawowej formie, niema jeszcze zaimplementowaneg
 * zwalniania zasobow i usuwania ich z kolejki
 *
 * - Kolejka zdarzen
 * Szkielet Menadzera (obsluga klawiszy i pozycja myszy)
 *
 * - Parser do prostego jezyka skryptowego
 * Do zrobienia
 *
 * - Menadzer zasobow
 * Na razie sam szkielet
 *
 * - Parser plikow INI
 * Jest, chociaz nie radzi sobie jeszcze dobrze z blednie napisanymi plikami
 * konfiguracyjnymi (wiem, ze ini jest standardem windowsa, ale jest prosty
 * i calkiem uzyteczny i pozwala na prosta edycje poza programem)
 *
 * - Rysowanie ksztaltow (klasa Shape)
 * Jest i dziala, mozna dodawac do kolejki, rysuje ksztalt laczac w kolejnosci
 * dodane punkty liniami, na sam koniec laczy ostatni punkt z pierwszym(domyka
 * figure)
 */



using namespace std;
SDL_Rect rct;
SDL_Rect frame;
SDL_Rect land_rect;

Shape s(Point(1, 1), Point(799, 1), Point(400, 599), Point(10, 10));
Sprite_Object sprite("animation.png", rct);
Sprite_Object land("land.jpg",land_rect);

int D = 0;

void MoveLeft()
{
    sprite.SetFlip(SDL_RendererFlip::SDL_FLIP_HORIZONTAL);
    sprite.MoveLeft(4);
}

void MoveRight()
{
    sprite.SetFlip(SDL_RendererFlip::SDL_FLIP_NONE);
    sprite.MoveRight(4);
}

int main()
{
    rct.h=75;
    rct.w=65;
    rct.x=30;
    rct.y=520;
    land_rect.x=0;
    land_rect.y=0;
    land_rect.h=600;
    land_rect.w=800;

    sprite.SetPosition(rct);
    land.SetPosition(land_rect);
    Event Left;
    Event Right;
    Left.SetKeyCode(SDLK_a);
    Right.SetKeyCode(SDLK_d);
    Left.SetSlot(MoveLeft);
    Right.SetSlot(MoveRight);
    Left.AddToQueue();
    Right.AddToQueue();
    s.SetVisability(true);
    Shape pentagram;
    pentagram.AddPoint(Point(40, 560));
    pentagram.AddPoint(Point(400, 40));
    pentagram.AddPoint(Point(760, 560));
    pentagram.AddPoint(Point(120, 120));
    pentagram.AddPoint(Point(680, 120));

    SDL_Rect land_rect;
    land_rect.h=600;
    land_rect.w=800;
    land_rect.x=0;
    land_rect.y=0;

    std::vector<SDL_Rect> land_frame;

    land_frame.push_back(land_rect);

    std::vector<SDL_Rect> t;
    frame.x = 0;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 130;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 260;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 390;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 520;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 650;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 780;
    frame.y = 0;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 0;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 130;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 260;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    t.push_back(frame);
    frame.x = 390;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 520;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 650;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 780;
    frame.y = 150;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 0;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 130;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 260;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    t.push_back(frame);
    frame.x = 390;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 520;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 650;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 780;
    frame.y = 300;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    t.push_back(frame);
    frame.x = 0;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 130;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 260;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    t.push_back(frame);
    frame.x = 390;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 520;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);
    frame.x = 650;
    frame.y = 450;
    frame.w = 130;
    frame.h = 150;
    t.push_back(frame);



    sprite.AddAnimation("default",t);
    sprite.SetPlane(1);
    sprite.AddToQueue();
    SDL_Point f;

    f.x = 32;
    f.y = 38;

    sprite.SetCenter(f);


    //RM::Get()->SaveSpriteObject(sprite, "sprite.spr");
    //RM::Get()->SaveSpriteObject(&land, "land.spr");

    //sprite = RM::Get()->LoadSpriteObject("sprite.spr");
    land.SetPlane(0);

    land.AddToQueue();



    Event move_in_left();

    Engine::Get()->StartEngine();
    return 0;
}
