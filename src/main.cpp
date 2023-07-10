#include<iostream>
#include<cstdlib>
#include<ctime>
#include<SDL.h>

#include"Case.hpp"
#include"Tableau.hpp"
#include"operators.hpp"

#define DIM 300

#define HEIGHT_SCREEN 800+DIM-1
#define WIDTH_SCREEN HEIGHT_SCREEN

void draw_tab(SDL_Renderer* pRenderer){

    int l(0);
    for(int i = 0; i<DIM; i++){

        SDL_Point pointA;
            pointA.x = 0;
            pointA.y = 800/DIM*i+l;

        SDL_Point pointB;
            pointB.x = WIDTH_SCREEN;
            pointB.y = 800/DIM*i+l;

        SDL_Point pointC;
            pointC.x = 800/DIM*i+l;
            pointC.y = 0;

        SDL_Point pointD;
            pointD.x = 800/DIM*i+l;
            pointD.y = WIDTH_SCREEN;

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(pRenderer, pointA.x, pointA.y, pointB.x, pointB.y);

        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(pRenderer, pointC.x, pointC.y, pointD.x, pointD.y);

        l++;
    }
}

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

int main(int argc, char *argv[]){

    Tableau tab;
    tab.random_perturbation();

    /*
    tab.perturbation(10,10);
    tab.perturbation(11,10);
    tab.perturbation(10,11);
    tab.perturbation(11,11);
    tab.perturbation(9,11);
    tab.perturbation(12,10);
    */

     /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* pWindow = nullptr;
    SDL_Renderer* pRenderer =nullptr;

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

    //draw_tab(pRenderer);

    SDL_Event events;
    bool isOpen{ true };
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

        draw(pRenderer, tab);
        tab.update();
        SDL_RenderPresent(pRenderer);
        SDL_Delay(100);
    }
    
    SDL_DestroyWindow(pWindow);
    SDL_DestroyRenderer(pRenderer);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}