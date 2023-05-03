#ifndef CASE_HPP_DEFINED
#define CASE_HPP_DEFINED

#include<iostream>

class Case{

    public:
    Case();
    Case(int x, int y, int e=0);
    Case(Case const& aCopier);

    int getX()const;
    int getY()const;
    int getE()const;
    Case& changementEtat(int e);

    void afficher(std::ostream &flux)const;

    Case& operator=(Case const& a);

    private:
    int c_x;
    int c_y;
    int c_e;
};

#endif //CASE_HPP_DEFINED