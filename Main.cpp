#include <iostream>

#include "Windows.h"
#include "Rect.h"

#define PI 3.1415926535F

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    Models::Geometry::Rect a (0, 2, 2, 2, PI / 4);
    Models::Geometry::Rect b (0, 0, 2, 2, 0);

    bool isColliding = a.Intersects(b);

    return 0;
}

