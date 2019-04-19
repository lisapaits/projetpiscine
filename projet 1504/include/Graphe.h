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



class Graphe
{
    public:
        Graphe();
        virtual ~Graphe();
        void affichage(BITMAP*);
        void remplir(std::string,std::string);
        void Kruskal();
    protected:

    private:
        int m_ordre;
        std::unordered_map<int,Sommet*> m_sommets;//stockée dans une map (clé=id du sommet, valeur= pointeur sur le sommet)
        std::unordered_map<int,Arete*> m_aretes;
};

#endif // GRAPHE_H
