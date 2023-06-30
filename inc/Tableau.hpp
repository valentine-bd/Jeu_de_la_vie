#ifndef TABLEAU_HPP_DEFINED
#define TABLEAU_HPP_DEFINED

#include<iostream>
#include<gtk/gtk.h>

#include"Case.hpp"

class Tableau{

    public:
    Tableau();
    Tableau(Tableau const& aCopier);

    Tableau& perturbation(int x, int y);
    
    bool testVivant(Case const& a);
    bool testMort(Case const& a);
    Tableau update();
    int giveE(int x, int y);
    
    void afficher(std::ostream &flux);

    Tableau& operator=(Tableau const& a);

    private:
    Case tab[400];
};

#endif //TABLEAU_HPP_DEFINED