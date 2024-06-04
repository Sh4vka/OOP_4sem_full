#include "Ked.h"
#include "windows.h"

extern HDC hdc;

Ked::Ked(int init_x1, int init_y1, int init_x2, int init_y2, int init_distance)
    : Boots(init_x1, init_y1, init_x2, init_y2), distanse(init_distance) {}

Ked::~Ked() {}

void Ked::show_new_body()
{
    int ny1 = y1 + distanse;
    int x2 = x1 + 90;
    int y2 = ny1 + 160 - distanse;
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point ABoots = Point(newx1, ny1);
        Point BBoots = Point(newx1, y2);
        ABoots.show();
        BBoots.show();
        newx1++;
    }

    int newy1 = ny1;
    while (newy1 <= y2) // высота сапога
    {
        Point ABoots = Point(x1, newy1);
        Point BBoots = Point(x2, newy1);
        ABoots.show();
        BBoots.show();
        newy1++;
    }
}

void Ked::show_new_nose()
{
    int ny1 = y1 + distanse;
    int x2 = x1 + 90;
    int y2 = ny1 + 160 - distanse;
    int newx1 = x2;
    int newx2 = x2 + 60;

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, y2);
        APoint.show();
        newx1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    // Рисуем белыми линиями вместо чёрных
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, newx1, ny1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, y2);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, ny1 + 1, NULL);
    LineTo(hdc, newx2, y2 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void Ked::show()
{
    show_new_body();
    show_new_nose();
}

void Ked::hide_new_body()
{
    int ny1 = y1 + distanse;
    int x2 = x1 + 90;

    int y2 = ny1 + 160 - distanse;
    int newx1 = x1;
    while (newx1 <= x2) //длина сапога
    {
        Point ABoots = Point(newx1, ny1);
        Point BBoots = Point(newx1, y2);
        ABoots.hide();
        BBoots.hide();
        newx1++;
    }

    int newy1 = ny1;
    while (newy1 <= y2) // высота сапога
    {
        Point ABoots = Point(x1, newy1);
        Point BBoots = Point(x2, newy1);
        ABoots.hide();
        BBoots.hide();
        newy1++;
    }
}

void Ked::hide_new_nose()
{
    int ny1 = y1 + distanse;
    int x2 = x1 + 90;
    int y2 = ny1 + 160 - distanse;
    int newx1 = x2;
    int newx2 = x2 + 60;

    while (newx1 <= newx2) //для подошвы
    {
        Point APoint(newx1, y2);
        APoint.hide();
        newx1++;
    }

    newx1 = x2; //новые переменые чтоб не портить значения

    // Рисуем белыми линиями вместо чёрных
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, newx1, ny1, NULL); //назначаем начальные точки для LineTo()
    LineTo(hdc, newx2, y2);         // рисуем диагональ
    MoveToEx(hdc, newx1 + 1, ny1 + 1, NULL);
    LineTo(hdc, newx2, y2 + 1);

    // Освобождаем ресурсы пера
    DeleteObject(hPen);
}

void Ked::hide()
{
    hide_new_body();
    hide_new_nose();
}
