#ifndef SOMMET_H
#define SOMMET_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
class Sommet
{
    public:
        Sommet(int,double,double);
        virtual ~Sommet();
        double GetX();
        double GetY();

    protected:

    private:
        int m_id; // Identifiant
        double m_x, m_y; // Position

};

#endif // SOMMET_H
