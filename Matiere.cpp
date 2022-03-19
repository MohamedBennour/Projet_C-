#include "Matiere.h"  

// Un constructeur par défaut (sans paramètres)	
Matiere::Matiere()
{
    Coef = -1;
}

// Un constructeur avec paramètres
Matiere::Matiere(string IdMat, string NomMat, double Coef, Enseignant Ens)
{
    this->IdMat = IdMat;
    this->NomMat = NomMat;
    this->Coef = Coef;
    this->Ens = Ens;
}

// Setter
void Matiere::setIdMat(string IdMat)
{
    this->IdMat = IdMat;
}

void Matiere::setNomMat(string NomMat)
{
    this->NomMat = NomMat;
}

void Matiere::setCoef(double Coef)
{
    this->Coef = Coef;
}

void Matiere::setEns(Enseignant Ens)
{
    this->Ens = Ens;
}

// Getter
string Matiere::getIdMat()
{
    return IdMat;
}

string Matiere::getNomMat()
{
    return NomMat;
}

double Matiere::getCoef()
{
    return Coef;
}

Enseignant Matiere::getEns()
{
    return Ens;
}

void Matiere::initIdMat()
{
    cout << "IdMat : ";
    cin >> IdMat;
}

void Matiere::initNomMat()
{
    cout << "NomMat : ";
    cin >> NomMat;
}

void Matiere::initCoef()
{
    cout << "Coef : ";
    cin >> Coef;
}

void Matiere::printMatiere() // Affichage d'une Matiere
{
    cout << "\n";
    cout << "IdMat : " << IdMat << " | " << "NomMat : " << NomMat << " | " 
    << "Coef : " << Coef << endl;
    Ens.printEnseignant();
}

ostream& operator << (ostream& os, Matiere& m)
{
    os << "IdMat : " << m.IdMat << " | " << "NomMat : " << m.NomMat << " | " 
    << "Coef : " << m.Coef << endl;
    cout << m.Ens;

    return os;
}


Matiere::~Matiere()
{
	
}