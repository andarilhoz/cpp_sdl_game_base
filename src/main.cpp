#include <iostream>
#include <SDL.h>

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to initialize the SDL2 library\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 426, 0);

    if(!window){
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface){
        std::cout << "Failed to get the surface from the window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    std::cout <<  SDL_GetBasePath() << "\n";
    SDL_Surface *image = SDL_LoadBMP("C:/Users/magno/Projects/cpp_sdl_game_base/robot.bmp");

    if(!image){
        std::cout << "Failed to load image\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return -1;
    }

    bool keep_window_open = true;
    while(keep_window_open){
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0){
            switch (e.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;

            }
        }
        SDL_BlitSurface(image, nullptr, window_surface, nullptr);
        SDL_UpdateWindowSurface(window);
    }
    return 0;
}
