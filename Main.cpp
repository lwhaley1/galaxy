#include <iostream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
#include "KeyEvent.h"

int SharedMain()
{
    UI::Window window ("OOP Window", 1280, 720);
    window.ShowAndWait();

    return 0;
}

#ifdef _WIN32

#include "Windows.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    return SharedMain();
}

#endif

#ifdef unix

int main(int, char**) {
    
    return SharedMain();
}

#endif
