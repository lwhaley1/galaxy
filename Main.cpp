#include <iostream>

#include "SDL.h"
#include "Window.h"

int main(int, char**) {
    
    UI::Window window ("OOP Window", 1280, 720);
    window.ShowAndWait();

    return 0;
}
