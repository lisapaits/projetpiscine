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
        m_sommets.insert({id,new Sommet{id,x,y}});


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
        /// ajouter la position x y et le num des sommets
        std::cout<<id_arets<<"    "<<id_sommet_1<<"     "<<id_sommet_2<<std::endl;
        m_aretes.insert({id_arets,new Arete{id_arets,id_sommet_1,id_sommet_2}});
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
        (m_aretes.find(id_2))->second->ajouterPoids(cout1,cout2);
    }
}
void Graphe::affichage(BITMAP *buffer)
{
    int couleur;
    int blanc;
    int x1,x2;
    int y1,y2;
    int P1;
    int P2;
    couleur=makecol(0,255,0);
    blanc=makecol(255,255,255);
    for(int i=0;i<=m_ordre;i++)
    {
        P1=(m_aretes.find(i))->second->GetSommet1();
        P2=(m_aretes.find(i))->second->GetSommet2();

        x1=(m_sommets.find(P1))->second->GetX();//x de sommet
        y1=(m_sommets.find(P1))->second->GetY();//y de sommet
        circlefill(buffer,x1,y1,7,blanc);
        circlefill(buffer,x1,y1,5,couleur);

        x2=(m_sommets.find(P2))->second->GetX();//x de sommet
        y2=(m_sommets.find(P2))->second->GetY();//y de sommet
        circlefill(buffer,x2,y2,7,blanc);
        circlefill(buffer,x2,y2,5,couleur);

        line(buffer, x1, y1, x2, y2, couleur);
    }

}

void Graphe::Kruskal()///mettre test en parametre donc changer les m_arrets en getter
{
    std::vector< std::pair <int,double> > vect;
    for(int i=0;i<=m_ordre;i++)
    {
        std::pair<int,double> tmp;

        tmp.first=i;
        tmp.second=(m_aretes.find(i))->second->GetPoids1();
        vect.push_back(tmp);

    }
    for(int i=0;i<m_ordre;i++)
    {
        std::pair<int,double>  a;

        if((vect[i].second)>(vect[i+1].second))
        {
            a=vect[i];
            vect[i]=vect[i+1];
            vect[i+1]=a;
        }
    }

    bool test_1=false;
    bool test_2=false;
    std::vector<int> marque;
    for(int j=0;j<vect.size();j++)
    {
        int k;
        k=vect[j].first;
        for(int i=0;i<marque.size();i++)
        {
            if((m_aretes.find(k))->second->GetSommet1()==marque[i])
            {
                test_1=true;
            }
            if((m_aretes.find(k))->second->GetSommet2()==marque[i])
            {
                test_2=true;
            }
        }
        if(test_1==false)
        {
            marque[marque.size()]=(m_aretes.find(k))->second->GetSommet1();
        }
        if(test_2==false)
        {
            marque[marque.size()]=(m_aretes.find(k))->second->GetSommet2();
        }
        if((test_1==false)||(test_2==false))
        {

        }
        //marque[marque.size()]=;
    }
}
