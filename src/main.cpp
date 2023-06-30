#include<iostream>
#include<cstdlib>
#include<ctime>
#include<gtk/gtk.h>

#include"Case.hpp"
#include"Tableau.hpp"
#include"operators.hpp"
#include"mainWindow.hpp"

int main(int argc, char *argv[]){
    /*
    srand((unsigned int)time(0));
    Tableau tab;
    tab.perturbation(10,10);
    tab.perturbation(11,10);
    tab.perturbation(10,11);
    tab.perturbation(11,11);
    tab.perturbation(9,11);
    //tab.perturbation(11,9);
    tab.perturbation(12,10);
    std::cout << tab << std::endl;

    for(int k=0; k<10;  k++){
        tab = tab.update();
        std::cout <<tab<< std::endl;
    }
    */

    GtkApplication *app;
    int stat;

    app = gtk_application_new ("com.github.ToshioCP.pr2", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (app_activate), NULL);
    stat = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);
    return stat;
}