#include "Etudiant.h"  

// Un constructeur par défaut (sans paramètres)	
Etudiant::Etudiant()
{
    Num_insc = -1;
}

// Un constructeur avec paramètres
Etudiant::Etudiant(int Id, string Nom, string Prenom, string Mail, int Num_insc):Personne(Id, Nom, Prenom,Mail)
{
    this->Num_insc = Num_insc;
}

// Setter
void Etudiant::setNum_insc(int Num_insc)
{
    this->Num_insc = Num_insc;

}

// Getter
int Etudiant::getNum_insc()
{
    return Num_insc;
}

void Etudiant::initNum_insc()
{
    cout << "Num_insc : ";
    cin >> Num_insc;
}

void Etudiant::printEtudiant() // Affichage d'un Etudiant
{
    printPersonne();
    cout << " | " << "Num_insc : " << Num_insc << endl;
}

ostream& operator << (ostream& os, Etudiant& e)
{
    os << "Id : " << e.Id << " | " << "Nom : " << e.Nom << " | " << "Prenom : " << e.Prenom 
    << " | " << "Mail : " << e.Mail << " | " << "Num_insc : " << e.Num_insc << endl;

    return os;
}

Etudiant::~Etudiant()
{
	
}