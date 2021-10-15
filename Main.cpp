#include <iostream>

#include "FontCache.h"
#include "SDL.h"
#include "Window.h"
#include "KeyEvent.h"
#include "Windows.h"
#include "DebugEventResponse.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
    UI::Window window ("Galaxy", 1280, 720);
    window.SetIcon("Assets/Images/icon.bmp");

    UI::Events::DebugEventResponse debug (window);
    window.AddKeyListener(UI::Events::KeyEvent::F1, debug);

    window.ShowAndWait();
    return 0;
}

