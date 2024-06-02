#include "NewBoots.h";
#include "windows.h"

extern HDC hdc;

NewBoots::NewBoots(int init_x1, int init_y1, int init_x2, int init_y2)
    : Boots(init_x1, init_y1, init_x2, init_y2) {}

NewBoots::~NewBoots() {}

void NewBoots::show_new_nose()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x2;
    int newx2 = (x2 + (x2 - x1) * 1.3 - 50);
    int newy1 = y1 + (y2 - y1) * 0.85;
    int newy2 = y2 + (y2 - y1) * 0.1; //новые переменые чтоб не портить значения

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, newy2);
        APoint.show();
        newx1++;
    }

    int nnewy1 = newy1 +20;
    while (nnewy1 <= newy2)
    {
        Point APoint(newx2, nnewy1);
        APoint.show();
        nnewy1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, newx1, newy1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, newy2 - 20);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, newy1 + 1, NULL);
    LineTo(hdc, newx2, newy2 - 20 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void NewBoots::show()
{
    show_body();
    show_kabluc();
    show_new_nose();
}

void NewBoots::hide_new_nose()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x2;
    int newx2 = (x2 + (x2 - x1) * 1.3 - 50);
    int newy1 = y1 + (y2 - y1) * 0.85;
    int newy2 = y2 + (y2 - y1) * 0.1; //новые переменые чтоб не портить значения

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, newy2);
        APoint.hide();
        newx1++;
    }

    int nnewy1 = newy1 + 20;
    while (nnewy1 <= newy2)
    {
        Point APoint(newx2, nnewy1);
        APoint.hide();
        nnewy1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    // Рисуем белыми линиями вместо чёрных
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, newx1, newy1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, newy2 - 20);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, newy1 + 1, NULL);
    LineTo(hdc, newx2, newy2 - 20 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void NewBoots::hide()
{
    hide_body();
    hide_kabluc();
    hide_new_nose();
}
