#include "Enseignant.h"  

// Un constructeur par défaut (sans paramètres)	
Enseignant::Enseignant()
{
    CNSS = -1;
}

// Un constructeur avec paramètres
Enseignant::Enseignant(int Id, string Nom, string Prenom, string Mail, int CNSS):Personne(Id, Nom, Prenom,Mail)
{
    this->CNSS = CNSS;
}

// Setter
void Enseignant::setCNSS(int CNSS)
{
    this->CNSS = CNSS;
}

//Getter
int Enseignant::getCNSS()
{
    return CNSS;
}

void Enseignant::initCNSS()
{
    cout << "CNSS : ";
    cin >> CNSS;
}

void Enseignant::printEnseignant() // Affichage d'un Enseignant
{
    printPersonne();
    cout << " | " << "CNSS : " << CNSS << endl;
}

ostream& operator << (ostream& os, Enseignant& ens)
{
    os << "Id : " << ens.Id << " | " << "Nom : " << ens.Nom << " | " << "Prenom : " << ens.Prenom 
    << " | " << "Mail : " << ens.Mail << " | " << "CNSS : " << ens.CNSS << endl;

    return os;
}

Enseignant::~Enseignant()
{
	
}