#ifndef ARETE_H
#define ARETE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Arete
{
    public:
        Arete(int,int,int);
        virtual ~Arete();

        void ajouterPoids(double ,double );
        int GetSommet1();
        int GetSommet2();
        double GetPoids1();
        double GetPoids2();
    protected:

    private:
        int m_premSommet, m_deuxSommet;
        int m_id;
        double m_poids1,m_poids2;

};

#endif // ARETE_H
