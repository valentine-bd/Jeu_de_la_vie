#include<iostream>
#include<cstdlib>
#include<ctime>
#include<SDL2/SDL.h>

#include"Case.hpp"
#include"Tableau.hpp"
#include"operators.hpp"

void test(Tableau *tab){

    Tableau *copieTab(tab->getAdd());
    std::cout << *copieTab << std::endl;

    copieTab->update();
}

int main(int argc, char *argv[]){

    Tableau *tab = new Tableau();

    tab->perturbation(10,10);
    tab->perturbation(11,10);
    tab->perturbation(10,11);
    tab->perturbation(11,11);
    tab->perturbation(9,11);
    tab->perturbation(12,10);
    
    std::cout << tab << std::endl;
    std::cout << *tab << std::endl;

    test(tab);

    std::cout << *tab << std::endl;

    /*for(int k=0; k<10;  k++){
        *tab = tab->update();
        std::cout <<*tab<< std::endl;
    }*/

    delete tab;

     /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("test SDL2",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Delay(3000);

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();
    
    return 0;



    /*GtkApplication *app;
    int stat;

    app = gtk_application_new ("com.github.ToshioCP.pr2", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (app_activate), NULL);
    stat = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    return stat;*/

}