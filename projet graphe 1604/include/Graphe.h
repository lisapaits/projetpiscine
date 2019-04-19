#ifndef GRAPHE_H
#define GRAPHE_H
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <allegro.h>


#include "Sommet.h"
#include "Arete.h"
#include "Pareto.h"


class Graphe
{
    public:
        Graphe();
        virtual ~Graphe();
        void affichage(BITMAP*,int,int);
        void remplir(std::string,std::string);
        void Kruskal(Graphe,int);
        std::vector<std::pair<int,Arete*>> GetArete();
        std::vector<std::pair<int,Sommet*>> GetSommet();
        double somme_poids1();
        double somme_poids2();
        int GetOrdre();
    protected:

    private:
        int m_ordre;

        std::vector<std::pair<int,Sommet*>> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::vector<std::pair<int,Arete*>> m_aretes;
        double m_somme_poids1;
        double m_somme_poids2;
};

#endif // GRAPHE_H
