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
        {   //std::cout<<"a";
            m_vecteur.push_back(std::vector<bool>(tmp));
            //std::cout<<"b";
            for(int k=0;k<m_vecteur[cpt1].size();k++)
            {
                std::cout<<m_vecteur[cpt1][k];

            }
            std::cout<<std::endl;
            cpt1++;
        }
    }
}

void Pareto::afficher_pareto(BITMAP*buffer,int cst_x,int cst_y)
{   int j=0;
    int k=0;
    for(int i=0;i<m_graphe.size();i++ )
    {
        m_graphe[i].affichage(buffer,cst_x+(k*150),cst_y+(j*150));
        k++;
        if(k>5)
            {j++;
            k=0;
            }

    }
}

void Pareto::BoolToGraphe(Graphe rempli)
{
   for(int i=0;i<m_vecteur.size();i++)
   {    Graphe tmp;
        for(int j=0;j<m_vecteur[i].size();j++)
        {
            if(m_vecteur[i][j]==1)
            {
                for(int k=0;k<rempli.GetArete().size();k++)
                {
                    if(rempli.GetArete()[k].first==j)
                    {
                        int id_ar=rempli.GetArete()[k].second->GetId();
                        int som1=rempli.GetArete()[k].second->GetSommet1();
                        int som2=rempli.GetArete()[k].second->GetSommet2();
                        double poid1=rempli.GetArete()[k].second->GetPoids1();
                        double poid2=rempli.GetArete()[k].second->GetPoids2();

                        std::cout<<std::endl<<id_ar<<"  "<<som1<<"  "<<som2;
                        tmp.SetArete(id_ar ,som1,som2);
                        tmp.GetArete()[tmp.GetArete().size()-1].second->ajouterPoids(poid1,poid2);
                    }
                }
           }

        }
        tmp.SetOrdre(rempli.GetOrdre());
        tmp.SetSommet(rempli.GetSommet());
        m_graphe.push_back(tmp);

   }

}
