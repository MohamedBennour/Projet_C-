#include "GroupeModule.h"  

// Un constructeur par défaut (sans paramètres)	
GroupeModule::GroupeModule()
{
    CoefGM = -1;
}

// Un constructeur avec paramètres
GroupeModule::GroupeModule(string IdGM, string NomGM, double CoefGM)
{
    this->IdGM = IdGM;
    this->NomGM = NomGM;
    this->CoefGM = CoefGM;
}

// Setter
void GroupeModule::setIdGM(string IdGM)
{
    this->IdGM = IdGM;
}

void GroupeModule::setNomGM(string NomGM)
{
    this->NomGM = NomGM;
}

void GroupeModule::setCoefGM(double CoefGM)
{
    this->CoefGM = CoefGM;
}


void GroupeModule::setListeMat(vector<Matiere> ListeMat)
{
    this->ListeMat = ListeMat;
}

// Getter
string GroupeModule::getIdGm()
{
    return IdGM;
}

string GroupeModule::getNomGM()
{
    return NomGM;
}

double GroupeModule::getCoefGM()
{
    return CoefGM;
}

vector<Matiere> GroupeModule::getListeMat()
{
    return ListeMat;
}

void GroupeModule::initIdGM()
{
    cout << "IdGM : ";
    cin >> IdGM;
}

void GroupeModule::initNomGM()
{
    cout << "NomGM : ";
    cin >> NomGM;
}

void GroupeModule::initCoefGM()
{
    cout << "CoefGM : ";
    cin >> CoefGM;
}

void GroupeModule::printGroupeModule() //Affichage d'un Groupe Module
{
	cout << "\n";
    cout << "IdGM : " << IdGM << " | " << "NomGM : " << NomGM << " | " 
    << "CoefGM : " << CoefGM << endl;

    vector<Matiere>::iterator it;
    for(it = ListeMat.begin(); it < ListeMat.end(); it++) 
    {
        (*it).printMatiere();
    }
}

ostream& operator << (ostream& os,  GroupeModule& gm)
{
    os <<"\n" << "IdGM : " << gm.IdGM << " | " << "NomGM : " << gm.NomGM << " | " 
    << "CoefGM : " << gm.CoefGM << endl;
    cout << "\n";

    vector<Matiere>::iterator it;
    for(it = gm.ListeMat.begin(); it < gm.ListeMat.end(); it++) 
    {
        cout << (*it);
    }
    return os;
}

GroupeModule::~GroupeModule()
{

}