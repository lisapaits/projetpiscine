#include "Sommet.h"

Sommet::Sommet(int id,double x,double y):m_id{id},m_x{x},m_y{y}
{
    //ctor
}

Sommet::~Sommet()
{
    //dtor
}

double Sommet::GetX(){
return m_x;}
double Sommet::GetY(){
return m_y;}
