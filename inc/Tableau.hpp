#ifndef TABLEAU_HPP_DEFINED
#define TABLEAU_HPP_DEFINED

#include<iostream>

#include"Case.hpp"

#define DIM 100

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
    Tableau* getAdd();

    private:
    Case tab[DIM*DIM];
};

#endif //TABLEAU_HPP_DEFINED