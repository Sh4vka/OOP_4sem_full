#include <iostream>
#include "windows.h"

#include "Location.h"
#include "Point.h"
#include "Boots.h"
#include "Rock.h"
#include "NewBoots.h"
#include "Road.h"

#include "Interface.h"
#include "Ked.h" // Добавили заголовочный файл для класса Ked

#define KEY_DOWN(vk) ((GetAsyncKeyState(vk) & 0x8000) ? 1 : 0)

using namespace std;

HDC hdc;

HWND getConsoleWindow()
{
    wchar_t str[128];
    wchar_t title[] = L"console window";

    GetConsoleTitle(str, sizeof(str) / sizeof(str[0]));
    SetConsoleTitle(title);
    Sleep(100);

    HWND hwnd = FindWindow(NULL, title);

    SetConsoleTitle(str);

    return hwnd;
}

enum State { BootsNormal, BreakBoots };
enum Event { MoveRight, MoveLeft, CollisionWithRock, NoEvent };

State getNextState(State currentState, Event event) {
    // Таблица переходов
    State transitionTable[2][4] = {
        //  MoveRight   MoveLeft    CollisionWithRock     NoEvent
        { BootsNormal, BootsNormal, BreakBoots,         BootsNormal }, // для состояния BootsNormal
        { BreakBoots,  BreakBoots,  BreakBoots,         BreakBoots }   // для состояния BreakBoots
    };

    return transitionTable[currentState][event];
}

Event getEvent(Interface* boots, Interface* rock) {
    if (KEY_DOWN(VK_RIGHT)) return MoveRight;
    if (KEY_DOWN(VK_LEFT)) return MoveLeft;
    if (boots->GetX() + 160 >= rock->GetX() && boots->GetY() + 160 >= rock->GetY() &&
        boots->GetX() <= rock->GetX() && boots->GetY() <= rock->GetY() + 20)
        return CollisionWithRock;
    return NoEvent;
}

int main()
{
    // Начальные настройки консоли и объектов
    system("color f0");
    HWND hwnd = getConsoleWindow();
    hdc = GetWindowDC(hwnd);

    int x1 = 230, y1 = 230, x2 = x1 + 70, y2 = y1 + 160;
    int x1_rock = 700, y1_rock = 390, x2_rock = x1_rock + 50, y2_rock = y1_rock + 20;
    int x1_road = 0, y1_road = 300, x2_road = 1000, y2_road = 420;

    Interface* boots = new Boots(x1, y1, x2, y2);
    Interface* ked = new Ked(x1 - 170, y1, x2 - 170, y2, 120); // Создали объект кедов и установили начальные координаты
    Interface* rock = new Rock(x1_rock, y1_rock, x2_rock, y2_rock);
    Interface* road = new Road(x1_road, y1_road, x2_road, y2_road, x1, x2);
    NewBoots* newBoots = nullptr;
    State currentState = BootsNormal;

    if (hwnd != NULL) {
        hdc = GetWindowDC(hwnd);
        if (hdc != 0) {
            boots->show();
            ked->show(); // Показываем кеды
            rock->show();
            road->show();

            while (true) {
                Event currentEvent = getEvent(boots, rock);
                State newState = getNextState(currentState, currentEvent);

                switch (newState) {
                case BootsNormal:
                    if (currentEvent == MoveRight) {
                        boots->move_to(boots->GetX() + 10, boots->GetY() - 20);
                        boots->move_to(boots->GetX() + 10, boots->GetY() + 20);
                        Sleep(10);
                        ked->move_to(ked->GetX() + 10, ked->GetY() - 40); // Перемещаем кеды вправо
                        ked->move_to(ked->GetX() + 10, ked->GetY() + 40);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    if (currentEvent == MoveLeft) {
                        boots->move_to(boots->GetX() - 10, boots->GetY() - 20);
                        boots->move_to(boots->GetX() - 10, boots->GetY() + 20);
                        Sleep(10);
                        ked->move_to(ked->GetX() - 10, ked->GetY() - 40); // Перемещаем кеды влево
                        ked->move_to(ked->GetX() - 10, ked->GetY() + 40);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    break;
                case BreakBoots:
                    if (currentState != BreakBoots) {
                        boots->hide();
                        newBoots = new NewBoots(boots->GetX(), boots->GetY(), boots->GetX() + 70, boots->GetY() + 160);
                        newBoots->show();
                    }
                    if (currentEvent == MoveRight) {
                        newBoots->move_to(newBoots->GetX() + 10, newBoots->GetY() - 20);
                        newBoots->move_to(newBoots->GetX() + 10, newBoots->GetY() + 20);
                        Sleep(10);
                        ked->move_to(ked->GetX() + 10, ked->GetY() - 40); // Перемещаем кеды вправо
                        ked->move_to(ked->GetX() + 10, ked->GetY() + 40);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    if (currentEvent == MoveLeft) {
                        newBoots->move_to(newBoots->GetX() - 10, newBoots->GetY() - 20);
                        newBoots->move_to(newBoots->GetX() - 10, newBoots->GetY() + 20);
                        Sleep(10);
                        ked->move_to(ked->GetX() - 10, ked->GetY() - 40); // Перемещаем кеды влево
                        ked->move_to(ked->GetX() - 10, ked->GetY() + 40);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    break;
                }

                currentState = newState;
            }

            ReleaseDC(hwnd, hdc);
        }
    }

    delete boots;
    delete rock;
    delete road;
    delete ked;
    if (newBoots) 
        delete newBoots;

    return 0;
}