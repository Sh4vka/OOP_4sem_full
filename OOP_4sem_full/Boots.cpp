#include "Boots.h"
#include <windows.h>

extern HDC hdc;

Boots::Boots(int init_x1, int init_y1, int init_x2, int init_y2)
    : Point(init_x1, init_y1), x2(init_x2), y2(init_y2) {}

Boots::~Boots() {}

void Boots::show_body() 
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point ABoots = Point(newx1, y1);
        Point BBoots = Point(newx1, y2);
        ABoots.show();
        BBoots.show();
        newx1++;
    }

    int newy1 = y1;
    while (newy1 <= y2) // высота сапога
    {
        Point ABoots = Point(x1, newy1);
        Point BBoots = Point(x2, newy1);
        ABoots.show();
        BBoots.show();
        newy1++;
    }
}

void Boots::show_kabluc()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x1; //новые переменые чтоб не портить значения
    int newy2 = y2;

    while (newy2 <= y2 + (y2 - y1) * 0.1) //высота каблука
    {
        Point APoint = Point(x1, newy2);
        Point BPoint = Point(x1 + (x2 - x1) * 0.33, newy2);
        Point CPoint = Point(x2, newy2);
        APoint.show();
        BPoint.show();
        CPoint.show();
        newy2++;
    }

    while (newx1 <= x1 + (x2 - x1) * 0.33) //длина каблука
    {
        Point APoint = Point(newx1, y2 + (y2 - y1) * 0.1);
        APoint.show();
        newx1++;
    }
}

void Boots::show_nose()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x2;
    int newx2 = x2 + (x2 - x1) * 1.3;
    int newy1 = y1 + (y2 - y1) * 0.85;
    int newy2 = y2 + (y2 - y1) * 0.1; //новые переменые чтоб не портить значения

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, newy2);
        APoint.show();
        newx1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, newx1, newy1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, newy2);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, newy1 + 1, NULL);
    LineTo(hdc, newx2, newy2 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void Boots::show()
{
    show_body();
    show_kabluc();
    show_nose();
}

void Boots::hide_body()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point APoint = Point(newx1, y1);
        Point BPoint = Point(newx1, y2);
        APoint.hide();
        BPoint.hide();
        newx1++;
    }

    int newy1 = y1;
    while (newy1 <= y2) // высота сапога
    {
        Point APoint = Point(x1, newy1);
        Point BPoint = Point(x2, newy1);
        APoint.hide();
        BPoint.hide();
        newy1++;
    }
}

void Boots::hide_kabluc()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x1; //новые переменые чтоб не портить значения
    int newy2 = y2;

    while (newy2 <= y2 + (y2 - y1) * 0.1) //высота каблука
    {
        Point APoint = Point(x1, newy2);
        Point BPoint = Point(x1 + (x2 - x1) * 0.33, newy2);
        Point CPoint = Point(x2, newy2);
        APoint.hide();
        BPoint.hide();
        CPoint.hide();
        newy2++;
    }

    while (newx1 <= x1 + (x2 - x1) * 0.33) //длина каблука
    {
        Point APoint = Point(newx1, y2 + (y2 - y1) * 0.1);
        APoint.hide();
        newx1++;
    }
}

void Boots::hide_nose()
{
    int x2 = x1 + 70;
    int y2 = y1 + 160;
    int newx1 = x2;
    int newx2 = x2 + (x2 - x1) * 1.3;
    int newy1 = y1 + (y2 - y1) * 0.85;
    int newy2 = y2 + (y2 - y1) * 0.1; //новые переменые чтоб не портить значения

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, newy2);
        APoint.hide();
        newx1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    // Рисуем белыми линиями вместо чёрных
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, newx1, newy1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, newy2);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, newy1 + 1, NULL);
    LineTo(hdc, newx2, newy2 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void Boots::hide()
{
    hide_body();
    hide_kabluc();
    hide_nose();
}
