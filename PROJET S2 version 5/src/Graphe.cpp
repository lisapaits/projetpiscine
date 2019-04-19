#include "Graphe.h"


Graphe::Graphe()
{

}


Graphe::~Graphe()
{
    //dtor
}

void Graphe::remplir(std::string nomFichier, std::string num_poid){
    /// position des aretes
    std::ifstream ifs{nomFichier+".txt"};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );
    int ordre;
    ifs >> ordre;
    m_ordre=ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id;
    double x,y;
    //lecture des sommets
    for (int i=0; i<ordre; ++i){
        ifs>>id; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>x; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>y; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        /// ajouter la position x y et le num des sommets
        std::cout<<id<<"    "<<x<<"     "<<y<<std::endl;
        ///m_sommets.insert({id,new Sommet{id,x,y}});
        std::pair<int,Sommet*> tmp_som;
        tmp_som.first=id;
        tmp_som.second=new Sommet{id,x,y};
        m_sommets.push_back(tmp_som);


    }

    int nb_sommets;
    ifs >> nb_sommets;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id_arets;
    int id_sommet_1,id_sommet_2;
    //lecture des sommets
    for (int i=0; i<nb_sommets; ++i){
        ifs>>id_arets; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>id_sommet_1; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");
        ifs>>id_sommet_2; if(ifs.fail()) throw std::runtime_error("Probleme lecture données sommet");

        std::cout<<id_arets<<"    "<<id_sommet_1<<"     "<<id_sommet_2<<std::endl;

        std::pair<int,Arete*> tmp_ar;
        tmp_ar.first=id_arets;
        tmp_ar.second=new Arete{id_arets,id_sommet_1,id_sommet_2};
        m_aretes.push_back(tmp_ar);
    }

    /// ///////////////////////////////////
    std::string fichier_poid;
    fichier_poid=nomFichier + "_weights_" + num_poid;

    std::ifstream ifs_2{fichier_poid+".txt"};
    if (!ifs_2)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + fichier_poid );
    int ordre_2;
    int nb_poids;
    ifs_2 >> ordre_2;
    if ( ifs_2.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    ifs_2 >> nb_poids;
    if ( ifs_2.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");
    int id_2;
    double cout1;
    double cout2;
    for (int i=0; i<ordre_2; ++i){
        ifs_2>>id_2; if(ifs_2.fail()) throw std::runtime_error("Probleme lecture données couts");
        ifs_2>>cout1; if(ifs_2.fail()) throw std::runtime_error("Probleme lecture données couts");
        ifs_2>>cout2; if(ifs_2.fail()) throw std::runtime_error("Probleme lecture données couts");

        std::cout<<id_2<<"    "<<cout1<<"     "<<cout2<<std::endl;

        for(int j=0;j<m_aretes.size();j++)
        {
            if(m_aretes[j].first==id_2)
                m_aretes[j].second->ajouterPoids(cout1,cout2);
        }
    }
}
int Graphe::GetOrdre()
{
    return m_ordre;
}
void Graphe::affichage(BITMAP *buffer,int x_cst,int y_cst)
{
    int couleur;
    int blanc;
    int x1,x2;
    int y1,y2;
    int P1;
    int P2;
    couleur=makecol(0,255,0);
    blanc=makecol(255,255,255);
    for(int i=0;i<m_aretes.size();i++)
    {
        P1=(m_aretes[i]).second->GetSommet1();
        P2=(m_aretes[i]).second->GetSommet2();

        for(int j=0;j<m_sommets.size();j++)
        {
            if(m_sommets[j].first==P1)
            {
                x1=(m_sommets[j]).second->GetX();//x de sommet
                y1=(m_sommets[j]).second->GetY();//y de sommet
                circlefill(buffer,x1+x_cst,y1+y_cst,7,blanc);
                circlefill(buffer,x1+x_cst,y1+y_cst,5,couleur);

            }
        }
        for(int j=0;j<m_sommets.size();j++)
        {
            if(m_sommets[j].first==P2)
            {
                x2=(m_sommets[j]).second->GetX();//x de sommet
                y2=(m_sommets[j]).second->GetY();//y de sommet
                circlefill(buffer,x2+x_cst,y2+y_cst,7,blanc);
                circlefill(buffer,x2+x_cst,y2+y_cst,5,couleur);
            }
        }

        textprintf_ex(buffer, font, x1+10+x_cst, y1+10+y_cst, makecol(255, 100, 200),-1, "%d", P1);
        textprintf_ex(buffer, font, x2+10+x_cst, y2+10+y_cst, makecol(255, 100, 200),-1, "%d", P2);

        line(buffer, x1+x_cst, y1+y_cst, x2+x_cst, y2+y_cst, couleur);


    }

    textprintf_ex(buffer, font, 100+x_cst, 50+y_cst, makecol(255, 100, 200),-1, "(%d : %d)", somme_poids1(),somme_poids2());


}
std::vector<std::pair<int,Arete*>> Graphe::GetArete()///
{
    return m_aretes;
}

std::vector<std::pair<int,Sommet*>> Graphe::GetSommet()///
{
    return m_sommets;
}

int Graphe::somme_poids1()
{
    double res=0;
    for(int i=0;i<m_aretes.size();i++)
    {
        res=res+m_aretes[i].second->GetPoids1();
    }
    return res;
}

int Graphe::somme_poids2()
{
    double res=0;
    for(int i=0;i<m_aretes.size();i++)
    {
        res=res+m_aretes[i].second->GetPoids2();

    }
    return res;
}

bool compare_double(std::pair<int,double>&a,std::pair<int,double>&b)
{
    return (a.second<b.second);
}

void Graphe::Kruskal(Graphe graph,int P)
{
    std::vector< std::pair <int,double> > vect;
    for(int i=0;i<=graph.GetArete().size();i++)
    {

        std::pair<int,double> tmp;
        tmp.first=i;
        if(P==1)
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==i)
                {
                    tmp.second=graph.GetArete()[j].second->GetPoids1();
                }
            }
        }

        if(P==2)
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==i)
                {
                    tmp.second=graph.GetArete()[j].second->GetPoids2();
                }
            }
        }
        vect.push_back(tmp);

    }

    std::sort(vect.begin(), vect.end(),compare_double);
    //for (auto a : vect) {
        //std::cout<<a.second<<" ";
    //}

    std::vector<std::pair<bool,Arete*>> tab;

    for(int i=0;i<vect.size();i++)
    {
        for(int j=0;j<graph.GetArete().size();j++)
        {
            if(graph.GetArete()[j].first==vect[i].first)
            {
                std::pair<bool,Arete*> tmp;
                tmp.first=false;
                int id_ar=graph.GetArete()[j].second->GetId();
                int som1=graph.GetArete()[j].second->GetSommet1();
                int som2=graph.GetArete()[j].second->GetSommet2();
                double poid1=graph.GetArete()[j].second->GetPoids1();
                double poid2=graph.GetArete()[j].second->GetPoids2();
                tmp.second=new Arete{id_ar,som1,som2};
                tab.push_back(tmp);
                tab[tab.size()-1].second->ajouterPoids(poid1,poid2);
            }
        }
    }
    m_sommets=graph.GetSommet();
    m_ordre=m_sommets.size();
    tableau_connex(tab,m_ordre);


    /// a changer!!!!
    /*bool test_1=false;
    bool test_2=false;
    int cpt=0;
    std::vector<int> marque;
    marque.push_back(-1);
    for(int j=0;j<vect.size();j++)
    {
        int k;
        k=vect[j].first;
        test_1=false;
        test_2=false;
        for(int i=0;i<marque.size();i++)
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==k)
                {
                    if(graph.GetArete()[j].second->GetSommet1()==marque[i])
                    {
                        test_1=true;

                    }
                    if(graph.GetArete()[j].second->GetSommet2()==marque[i])
                    {
                        test_2=true;

                    }
                }
            }
        }
        if(test_1==false)
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==k)
                {
                    marque.push_back((graph.GetArete()[j]).second->GetSommet1());

                }
            }
        }
        if(test_2==false)
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==k)
                {
                    marque.push_back((graph.GetArete()[j]).second->GetSommet2());

                }
            }
        }
        if((test_1==false)||(test_2==false))
        {
            for(int j=0;j<graph.GetArete().size();j++)
            {
                if(graph.GetArete()[j].first==k)
                {
                    int id_ar=graph.GetArete()[j].second->GetId();
                    int som1=graph.GetArete()[j].second->GetSommet1();
                    int som2=graph.GetArete()[j].second->GetSommet2();
                    double poid1=graph.GetArete()[j].second->GetPoids1();
                    double poid2=graph.GetArete()[j].second->GetPoids2();
                    std::pair<int,Arete*> tmp_ar;
                    tmp_ar.first=id_ar;
                    tmp_ar.second=new Arete{id_ar,som1,som2};
                    m_aretes.push_back(tmp_ar);
                    m_aretes[m_aretes.size()-1].second->ajouterPoids(poid1,poid2);

                }
            }
        }
    }

    m_sommets=graph.GetSommet();
    m_ordre=m_sommets.size();
    //std::cout<<m_ordre;
    //std::cout<<m_sommets.find(0)->first;*/
}

void Graphe::SetArete(int id,int som1,int som2){

    std::pair<int,Arete*> tmp;
    tmp.first=id;
    tmp.second=new Arete{id,som1,som2};
    m_aretes.push_back(tmp);

}

void Graphe::SetSommet(std::vector<std::pair<int,Sommet*>> entre){
    m_sommets=entre;
}
void Graphe::tableau_connex(std::vector< std::pair <bool,Arete*>> vect,int ordre)
{
    int selec=0;
    std::vector<int> tableau;
    for(int i=0;i<ordre;i++)
    {
        tableau.push_back(i);
    }
    while(selec<=(ordre-1))
    {
        for(int i=0;i<vect.size();i++)
        {
            int modif=tableau[vect[i].second->GetSommet1()];
            int pred=tableau[vect[i].second->GetSommet2()];
            for(int j=0;j<tableau.size();j++)
            {
                if(tableau[j]==pred)
                {
                    tableau[j]=modif;
                    if(pred!=modif)
                        {
                            vect[i].first=true;
                        }
                }
            }
            if(vect[i].first==true)
            {
                selec++;
            }
        }
    }
    std::cout<<std::endl<<std::endl;
    for(int i=0;i<vect.size();i++)
    {
        if(vect[i].first==true)
        {
            int id=vect[i].second->GetId();
            int som1=vect[i].second->GetSommet1();
            int som2=vect[i].second->GetSommet2();
            double P1=vect[i].second->GetPoids1();
            double P2=vect[i].second->GetPoids2();
            SetArete(id,som1,som2);
            GetArete()[GetArete().size()-1].second->ajouterPoids(P1,P2);
            std::cout<<id<<std::endl;
            std::cout<<"poids 1 :"<<P1<<" poids 2 :"<<P2<<std::endl;
        }
    }

}

void Graphe::SetOrdre(int entre){
m_ordre = entre;
}
