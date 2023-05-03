#ifndef TABLEAU_HPP_DEFINED
#define TABLEAU_HPP_DEFINED

#include<iostream>

#include"Case.hpp"

class Tableau{

    public:
    Tableau();
    Tableau(Tableau const& aCopier);

    Tableau& perturbation(int x, int y);
    Tableau& propagation(Case const& a);
    Tableau update();

    void afficher(std::ostream &flux);

    Tableau& operator=(Tableau const& a);

    private:
    Case tab[400];
};

#endif //TABLEAU_HPP_DEFINED