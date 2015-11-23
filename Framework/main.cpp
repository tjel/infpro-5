#include <iostream>
#include "Shape.h"
#include "Renderer.h"
#include "Engine.h"

#include "Draw_Queue.h"

/* Grzegorz Malkiewicz
 * Uzyje pliku main do opis co jeszcze jest do zrobienia
 * a co zostalo juz zrobione :
 *
 * - Kolejka rysowania
 * Juz jest ale tylko w podstawowej formie, niema jeszcze zaimplementowaneg
 * zwalniania zasobow i usuwania ich z kolejki
 *
 * - Kolejka zdarzen
 * Do zrobienia
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

//W tym momencie program rysuje figure - pentagram oraz pojedynczy punkt
//na tem moment program niema obslugi zdarzen, wiec okna nie mozna
//zamknac, nalezy zabic proces

using namespace std;

int main()
{
    Shape pentagram;
    pentagram.AddPoint(Point(40,560));
    pentagram.AddPoint(Point(400,40));
    pentagram.AddPoint(Point(760,560));
    pentagram.AddPoint(Point(120,120));
    pentagram.AddPoint(Point(680,120));

    pentagram.AddToQueue();

    Shape point(Point(400,200));

    point.AddToQueue();

    Engine::GetEngine()->StartEngine();
    return 0;
}

