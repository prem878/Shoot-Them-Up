#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
const char* title="Batman";

int main(){
    if(SDL_Init(SDL_INIT_VIDEO!=0)) {
        printf("SDL_INIT_VIDEO Error: %s\n",SDL_GetError());    
        return -1;
    }


    SDL_Window *main_window=SDL_CreateWindow(title,
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            800,
            600,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
            );

    if(!main_window){
        printf("SDL_INIT_VIDEO Error: %s\n",SDL_GetError());  
        return -1;
    }

    SDL_Renderer *main_render=SDL_CreateRenderer(
            main_window,
            -1,
            SDL_RENDERER_ACCELERATED
            );

    if(main_window==NULL){
        printf("SDL_Renderer Error: %s\n",SDL_GetError());
        return -1;
    }

    bool main_running=true;
    SDL_Event event;
    while(main_running){
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                main_running = false;
            }
        }
    }
        
    SDL_DestroyWindow(main_window);
    SDL_Quit();
    return 0;

}
