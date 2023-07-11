#include<iostream>
#include<cstdlib>
#include<SDL.h>

#include"Tableau.hpp"
#include"displayTab.hpp"

#define DIM 250

#define HEIGHT_SCREEN 800+DIM-1
#define WIDTH_SCREEN HEIGHT_SCREEN

void draw(SDL_Renderer* pRenderer, Tableau tab){

    int l2(0);
    for(int i = 0; i<DIM; i++){
        int l1(0);
        for(int j = 0; j<DIM; j++){

            SDL_Rect cell{i*800/DIM+l2, j*800/DIM+l1, 800/DIM, 800/DIM};

            if(tab.giveE(j,i)==1){
                SDL_SetRenderDrawColor(pRenderer, 0, 0, 255, 255);
                SDL_RenderFillRect(pRenderer, &cell);
            }
            else{
                SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
                SDL_RenderFillRect(pRenderer, &cell);
            }
            l1++;
        }
        l2++;
    }
}

int main_window(){

    Tableau tab;
    tab.random_perturbation();

    SDL_Window* pWindow = nullptr;
    SDL_Renderer* pRenderer =nullptr;
    SDL_Event events;

    pWindow = SDL_CreateWindow("test SDL2",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, HEIGHT_SCREEN, WIDTH_SCREEN, SDL_WINDOW_SHOWN);
    if( pWindow == nullptr )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur de création de la fenêtre: (%s)\n", SDL_GetError());
        SDL_Quit();

        return EXIT_FAILURE;
    }

    pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);       
    if (pRenderer == nullptr)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }

    SDL_SetWindowTitle(pWindow, "Hello World!");
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
    SDL_RenderClear(pRenderer);

    bool isOpen{ true };
    int gen(0);
    while (isOpen)
    {
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                    isOpen = false;
                    break;
            }
        }

        std::cout<<"Generation : "<<gen<<std::endl;
        //std::cout<<tab<<std::endl;

        draw(pRenderer, tab);
        tab.update();
        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);

        gen++;
    }
    
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);

    return EXIT_SUCCESS;
}