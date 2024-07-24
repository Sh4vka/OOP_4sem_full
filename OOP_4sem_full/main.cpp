#include <iostream>
#include <windows.h>
#include "Location.h"
#include "Point.h"
#include "Boots.h"
#include "Rock.h"
#include "NewBoots.h"
#include "Road.h"
#include "Interface.h"
#include "Ked.h"

#define KEY_DOWN(vk) ((GetAsyncKeyState(vk) & 0x8000) ? 1 : 0)
#define VK_A 0x41
#define VK_D 0x44

using namespace std;

HDC hdc;

HWND getConsoleWindow() {
    wchar_t str[128];
    wchar_t title[] = L"console window";

    GetConsoleTitle(str, sizeof(str) / sizeof(str[0]));
    SetConsoleTitle(title);
    Sleep(100);

    HWND hwnd = FindWindow(NULL, title);

    SetConsoleTitle(str);

    return hwnd;
}

enum State { BootsNormal, BreakBoots, KedNormal, BreakKed };
enum Event { MoveRightBoot, MoveLeftBoot, MoveRightKed, MoveLeftKed, CollisionWithRockBoot, CollisionWithRockKed, NoEvent };

State getNextState(State currentState, Event event) {
    // Таблица переходов
    State transitionTable[4][7] = {
        // MoveRightBoot  MoveLeftBoot   MoveRightKed   MoveLeftKed    CollisionWithRockBoot CollisionWithRockKed NoEvent
        { BootsNormal,    BootsNormal,    BootsNormal,     BootsNormal,     BreakBoots,       KedNormal,           BootsNormal }, // для состояния BootsNormal
        { BreakBoots,     BreakBoots,     BreakBoots,    BreakBoots,    BreakBoots,       BreakBoots,           BreakBoots }, // для состояния BreakBoots
        { KedNormal,      KedNormal,      KedNormal,       KedNormal,       KedNormal,         BreakKed,            KedNormal }, // для состояния KedNormal
        { BreakKed,       BreakKed,       BreakKed,        BreakKed,        BreakKed,          BreakKed,            BreakKed }  // для состояния BreakKed
    };

    return transitionTable[currentState][event];
}

Event getEvent(Interface* boots, Interface* ked, Interface* rock) {
    if (KEY_DOWN(VK_RIGHT)) return MoveRightBoot;
    if (KEY_DOWN(VK_LEFT)) return MoveLeftBoot;
    if (KEY_DOWN(VK_D)) return MoveRightKed;
    if (KEY_DOWN(VK_A)) return MoveLeftKed;
    if (boots->GetX() + 160 >= rock->GetX() && boots->GetY() + 160 >= rock->GetY() &&
        boots->GetX() <= rock->GetX() && boots->GetY() <= rock->GetY() + 20)
        return CollisionWithRockBoot;
    if (ked->GetX() + 160 >= rock->GetX() && ked->GetY() + 160 >= rock->GetY())
        return CollisionWithRockKed;
    return NoEvent;
}

int main() {
    system("color f0");
    HWND hwnd = getConsoleWindow();
    hdc = GetWindowDC(hwnd);

    int x1 = 230, y1 = 230, x2 = x1 + 70, y2 = y1 + 160;
    int x1_rock = 700, y1_rock = 390, x2_rock = x1_rock + 50, y2_rock = y1_rock + 20;
    int x1_road = 0, y1_road = 300, x2_road = 1000, y2_road = 420;

    Interface* boots = new Boots(x1, y1, x2, y2);
    Interface* ked = new Ked(x1 - 200, y1, x2 - 170, y2, 120);
    Interface* rock = new Rock(x1_rock, y1_rock, x2_rock, y2_rock);
    Interface* road = new Road(x1_road, y1_road, x2_road, y2_road, x1, x2);
    NewBoots* newBoots = nullptr;
    NewKed* newKed = nullptr;
    State currentState = BootsNormal;

    if (hwnd != NULL) {
        hdc = GetWindowDC(hwnd);
        if (hdc != 0) {
            boots->show();
            ked->show();
            rock->show();
            road->show();

            while (true) {
                Event currentEvent = getEvent(boots, ked, rock);
                State newState = getNextState(currentState, currentEvent);

                if (currentEvent == MoveRightBoot && currentState != BreakBoots) {
                    boots->move_to(10, -20);
                    boots->move_to(10, 20);
                    Sleep(10);
                    rock->show();
                    road->show();
                    Sleep(10);
                }
                if (currentEvent == MoveLeftBoot && currentState != BreakBoots) {
                    boots->move_to(-10, -20);
                    boots->move_to(-10, 20);
                    Sleep(10);
                    rock->show();
                    road->show();
                    Sleep(10);
                }

                if (currentEvent == MoveRightKed && currentState != BreakKed) {
                    ked->move_to(10, -40);
                    Sleep(10);
                    ked->move_to(10, 40);
                    rock->show();
                    road->show();
                    Sleep(10);
                }
                if (currentEvent == MoveLeftKed && currentState != BreakKed) {
                    ked->move_to(-10, -40);
                    Sleep(10);
                    ked->move_to(-10, 40);
                    rock->show();
                    road->show();
                    Sleep(10);
                }

                if (newState == BreakBoots && currentState != BreakBoots) {
                    boots->hide();
                    newBoots = new NewBoots(boots->GetX(), boots->GetY(), boots->GetX() + 70, boots->GetY() + 160);
                    newBoots->show();
                }

                if (newState == BreakBoots) {
                    if (currentEvent == MoveRightBoot) {
                        newBoots->move_to(10, -20);
                        newBoots->move_to(10, 20);
                        Sleep(10);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    if (currentEvent == MoveLeftBoot) {
                        newBoots->move_to(-10, -20);
                        newBoots->move_to(-10, 20);
                        Sleep(10);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                }

                if (newState == BreakKed && currentState != BreakKed) {
                    ked->hide();
                    newKed = new NewKed(ked->GetX(), ked->GetY(), ked->GetX() + 70, ked->GetY() + 160, 120);
                    newKed->show();
                }

                if (newState == BreakKed) {
                    if (currentEvent == MoveRightKed) {
                        newKed->move_to(10, -40);
                        newKed->move_to(10, 40);
                        Sleep(10);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                    if (currentEvent == MoveLeftKed) {
                        newKed->move_to(-10, -40);
                        newKed->move_to(-10, 40);
                        Sleep(10);
                        rock->show();
                        road->show();
                        Sleep(10);
                    }
                }

                currentState = newState;
            }

            ReleaseDC(hwnd, hdc);
        }
    }

    delete boots;
    delete rock;
    delete road;
    if (newBoots)
        delete newBoots;
    if (newKed)
        delete newKed;

    return 0;
}
