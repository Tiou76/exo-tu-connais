#include <SDL2/SDL.h>
#include <iostream>
#include <time.h>



#ifdef __WIN32__
int WinMain(int argv, char** args)
#else
int main(int argv, char** args)
#endif
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    srand(time(NULL));

    bool isRunning = true;
    SDL_Event event;

    int r_x { 400 };
    int r_y { 300 };

    SDL_Rect r { r_x, r_y, 50, 50 };

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;
               break;
                case SDL_KEYDOWN:

                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        {
                            isRunning = false;
                        }

                    if (event.key.keysym.sym == SDLK_UP)
                        {
                            r_y -= 10;
                        }

                    if (event.key.keysym.sym == SDLK_DOWN)
                        {
                            r_y += 10;
                        }

                    if (event.key.keysym.sym == SDLK_RIGHT)
                        {
                            r_x += 10;
                        }

                    if (event.key.keysym.sym == SDLK_LEFT)
                        {
                            r_x -= 10;
                        }

                break;

                default:
               break;
            }

            r = { r_x, r_y, 50, 50 };
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 90, 65, 105, 255);
        SDL_RenderFillRect(renderer, &r);
        SDL_RenderPresent(renderer);

        SDL_Delay(50);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}