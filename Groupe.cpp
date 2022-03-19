#include "Groupe.h"

// Un constructeur par défaut (sans paramètres)	
Groupe::Groupe()
{
    Num_G = -1;
}
// Un constructeur avec paramètres
Groupe::Groupe(string IdGRP, string Niveau, string Diplome, string Specialite, int Num_G)
{
    this->IdGRP = IdGRP;
    this->Niveau = Niveau;
    this->Diplome = Diplome;
    this->Specialite = Specialite;
    this->Num_G = Num_G;
}

//Setter
void Groupe::setIdGRP(string IdGRP)
{
    this->IdGRP = IdGRP;
}

void Groupe::setNiveau(string Niveau)
{
    this->Niveau = Niveau;
}

void Groupe::setDiplome(string Diplome)
{
    this->Diplome = Diplome;
}

void Groupe::setSpecialite(string Specialite)
{
    this->Specialite = Specialite;
}

void Groupe::setNum_G(int Num_G)
{
    this->Num_G = Num_G;
}

void Groupe::setListeModules(vector<GroupeModule> ListeModules)
{
    this->ListeModules = ListeModules;
}

void Groupe::setListeEtudiants(vector<Etudiant> ListeEtudiants)
{
    this->ListeEtudiants = ListeEtudiants;
}


//Getter
string Groupe::getIdGRP()
{
    return IdGRP;
}

string Groupe::getNiveau()
{
    return Niveau;
}

string Groupe::getDiplome()
{
    return Diplome;
}

string Groupe::getSpecialite()
{
    return Specialite;
}

int Groupe::getNum_G()
{
    return Num_G;
}

vector<GroupeModule> Groupe::getListeModules()
{
    return ListeModules;
}

vector<Etudiant> Groupe::getListeEtudiants()
{
    return ListeEtudiants;
}

void Groupe::initIdGRP()
{
    cout << "IdGRP : ";
    cin >> IdGRP;
}

void Groupe::initNiveau()
{
    cout << "Niveau : ";
    cin >> Niveau;
}

void Groupe::initDiplome()
{
    cout << "Diplome : ";
    cin >> Diplome;
}

void Groupe::initSpecialite()
{
    cout << "Specialite : ";
    cin >> Specialite;
}

void Groupe::initNum_G()
{
    cout << "Num_G : ";
    cin >> Num_G;
}

void Groupe::printGroupe() //Affichage d'un Groupe 
{
    cout << "\n";
    cout << "IdGRP : " << IdGRP << " | " << "Niveau : " << Niveau << " | " << "Diplome : " << Diplome 
    << " | " << "Specialite : " << Specialite << " | " << "Num_G : " << Num_G << endl;

    vector<GroupeModule>::iterator it;
    for (it = ListeModules.begin(); it < ListeModules.end(); it++)
    {   
        cout << "\n";
        (*it).printGroupeModule();
    }

    vector<Etudiant>::iterator i;
    for (i = ListeEtudiants.begin(); i < ListeEtudiants.end(); i++)
    {
        cout << "\n";
        (*i).printEtudiant();
    }  
}

ostream& operator << (ostream& os,  Groupe& g)
{
    os << "IdGRP : " << g.IdGRP << " | " << "Niveau : " << g.Niveau << " | " << "Diplome : " << g.Diplome 
    << " | " << "Specialite : " << g.Specialite << " | " << "Num_G : " << g.Num_G << endl;

    vector<GroupeModule>::iterator it;
    for (it = g.ListeModules.begin(); it < g.ListeModules.end(); it++)
    {   
        cout << (*it);
    }
    cout << "\n";
    vector<Etudiant>::iterator it1;
    for (it1 = g.ListeEtudiants.begin(); it1 < g.ListeEtudiants.end(); it1++)
    {
        cout << (*it1);
    }  
    return os;
}

Groupe::~Groupe()
{

}