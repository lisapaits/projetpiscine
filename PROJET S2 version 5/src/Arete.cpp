#include "Arete.h"
/// int m_premSommet, m_deuxSommet; double m_poids1,m_poids2;
Arete::Arete(int id,int premSommet, int deuxSommet):m_id{id},m_premSommet{premSommet},m_deuxSommet{deuxSommet}
{
    //ctor
}

Arete::~Arete()
{
    //dtor
}
void Arete::ajouterPoids(double P1,double P2){
    m_poids1=P1;
    m_poids2=P2;
}
int Arete::GetSommet1()
{
    return m_premSommet;
}
int Arete::GetSommet2()
{
    return m_deuxSommet;
}
int Arete::GetId()
{
    return m_id;
}

double Arete::GetPoids1()
{
    return m_poids1;
}
double Arete::GetPoids2()
{
    return m_poids2;
}
