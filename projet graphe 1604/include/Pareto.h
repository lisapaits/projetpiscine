#ifndef PARETO_H
#define PARETO_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>



class Pareto
{
    public:
        Pareto();
        virtual ~Pareto();
        void comptageBinaire(int);

    protected:

    private:
       std::vector<std::vector<bool>> m_vecteur;
};

#endif // PARETO_H
