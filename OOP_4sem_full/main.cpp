#include <iostream>
#include "windows.h"
#include "Location.h"
#include "Point.h"
#include "Boots.h"
#include "Rock.h"
#include "NewBoots.h"
#include "Road.h"

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

int main()
{
    system("color f0");

    HWND hwnd = getConsoleWindow();
    hdc = GetWindowDC(hwnd);

    //координаты сапога
    int x1 = 230;
    int y1 = 230;
    int x2 = x1 + 70;
    int y2 = y1 + 160;

    //координаты камня
    int x1_rock = 700;
    int y1_rock = 390;
    int x2_rock = 750;
    int y2_rock = 410;

    //координаты дороги
    int x1_road = 0;
    int y1_road = 300;
    int x2_road = 1000;
    int y2_road = 420;

    if (hwnd != NULL)
    {
        hdc = GetWindowDC(hwnd);
        if (hdc != 0)
        {
            Boots ABoots = Boots(x1, y1, x2, y2);
            ABoots.show();
            Rock ARock = Rock(x1_rock, y1_rock, x2_rock, y2_rock);
            ARock.show();
            Road ARoad = Road(x1_road, y1_road, x2_road, y2_road, x1, x2);
            ARoad.show();
            ARoad.hide(x1, x2);
            while (true)
            {
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 + i;
                        y1 = y1 - i;
                        x2 = x2 + i;
                        y2 = y2 - i;

                        ABoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);

                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 + i;
                        y1 = y1 + i;
                        x2 = x2 + i;
                        y2 = y2 + i;

                        ABoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }

                    ARoad.show();
                    ARoad.hide(x1, x2);

                    if (x1 + 70 + (x1 + 70 - x1) * 1.3 >= x1_rock)
                    {
                        ABoots.hide();
                        break;
                    }
                }

                if (GetAsyncKeyState(VK_LEFT))
                {
                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 - i;
                        y1 = y1 - i;
                        x2 = x2 - i;
                        y2 = y2 - i;

                        ABoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);

                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 - i;
                        y1 = y1 + i;
                        x2 = x2 - i;
                        y2 = y2 + i;

                        ABoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);
                }
            }

            NewBoots ANewBoots = NewBoots(x1, y1, x2, y2);
            ANewBoots.show();
            while (true)
            {
                ARock.show();
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 + i;
                        y1 = y1 - i;
                        x2 = x2 + i;
                        y2 = y2 - i;

                        ANewBoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);

                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 + i;
                        y1 = y1 + i;
                        x2 = x2 + i;
                        y2 = y2 + i;

                        ANewBoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);
                }

                if (GetAsyncKeyState(VK_LEFT))
                {
                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 - i;
                        y1 = y1 - i;
                        x2 = x2 - i;
                        y2 = y2 - i;

                        ANewBoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);

                    for (int i = 0; i <= 30; i += 10)
                    {
                        x1 = x1 - i;
                        y1 = y1 + i;
                        x2 = x2 - i;
                        y2 = y2 + i;

                        ANewBoots.move_to(x1, y1);  // Перемещаем сапоги
                        Sleep(2);
                    }
                    ARoad.show();
                    ARoad.hide(x1, x2);
                }
            }
        }
        ReleaseDC(hwnd, hdc);
    }
    return 0;
}