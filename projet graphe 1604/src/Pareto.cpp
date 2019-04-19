#include "Pareto.h"

Pareto::Pareto()
{
    //ctor
}

Pareto::~Pareto()
{
    //dtor
}

void Pareto::comptageBinaire(int ordre)
{   int cpt1=0;
    ///a mettre dans fct pareto
    for(int i=0;i<32;i++)
    {   std::vector<bool> tmp;

        for(int pb=0;pb<5;pb++)//pb position bit
        {
            tmp.push_back(i>>pb&1);
            //std::cout<<(i>>pb&1);

        }
            //std::cout<<std::endl;
            ///regarde nb 1
            ///enregistre si = ordre-1
        int nb=0;
        for(int j=0;j<tmp.size();j++)
        {
            if(tmp[j]==1)
                nb++;
        }
        //std::cout<<"ordre"<<ordre<<std::endl;
        //std::cout<<nb<<std::endl;
        if (nb==ordre-1)
        {   std::cout<<"a";
            m_vecteur.push_back(std::vector<bool>(tmp));
            std::cout<<"b";
            //for(int k=0;k<m_vecteur[cpt1].size();k++)
            //{
                //std::cout<<m_vecteur[cpt1][k];
                //cpt1++;
           // }
        }
    }
}

