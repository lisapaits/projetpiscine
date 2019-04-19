#ifndef PARETO_H
#define PARETO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Graphe.h"

class Graphe;

class Pareto
{
    public:
        Pareto();
        virtual ~Pareto();
        void comptageBinaire(int);
        /// fct qui associe un m_vecteur a un graphe.
        void BoolToGraphe(Graphe);
        /// faire un BFS ou DFS de ce graphe.
        void afficher_pareto(BITMAP*,int,int);



    protected:

    private:
        std::vector<std::vector<bool>> m_vecteur;
        std::vector<Graphe> m_graphe;

};

#endif // PARETO_H
