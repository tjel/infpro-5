#ifndef EVENTS_MANAGER_H
#define EVENTS_MANAGER_H
#include <SDL2/SDL.h>
#include <map>

/* Menadzer zdarzen
 * prosty menadzer jako singleton, pozwalajacy sprawdzac zdarzenia w roznych czesci programu
 * metoda RefreshKey powinna byc wywolana poczatku glownej petli, sprawdzi stan wszystkich klawiszy
 * ktore byly wywolane przynajmniej raz w programie, ten stan moze byc odczytany pozniej gdziekolwiek
 * IsClicked sprawdza czy klawisz zostal "klikniety" tzn.nacisniety a pozniej zwolniony
 * IsPressed sprawdza czy klawisz jest wcisniety
 * Dodatkowo mouse_x i mouse_y przetrzymuja pozycje myszy.
 */

class Events_Manager
{
public:
    static Events_Manager* Get();
    int mouse_x;
    int mouse_y;

    //Metoda aktualizujaca stan klawiszy, powinna byc wywolywana na poczatku glownej petli
    void RefreshKeys();

    bool IsClicked(SDL_Keycode key_code);
    bool IsPressed(SDL_Keycode key_code);

private:
    Events_Manager();
    static Events_Manager* singleton;
    std::map<SDL_Keycode, bool> previous_keys_state;
    std::map<SDL_Keycode, bool> keys_pressed;
    std::map<SDL_Keycode, bool> keys_clicked;

    SDL_Event event;
};

#endif // EVENTS_MANAGER_H
