#include "Note.h"

// Un constructeur par défaut (sans paramètres)	
Note::Note()
{
    Nt = -1;
}

// Un constructeur avec paramètres
Note::Note(Matiere Mat, Etudiant Etu, double Nt, string Type)
{
    this->Mat = Mat;
    this->Etu = Etu;
    this->Nt = Nt;
    this->Type = Type;
}

//Setter
void Note::setMat(Matiere Mat)
{
    this->Mat = Mat;
}

void Note::setEtu(Etudiant Etu)
{
    this->Etu = Etu;
}

void Note::setNt(double Nt)
{   
    this->Nt = Nt;
}

void Note::setType(string Type)
{
    this->Type = Type;
}

//Getter
Matiere Note::getMat()
{
    return Mat;
}

Etudiant Note::getEtu()
{
    return Etu;
}

double Note::getNt()
{
    return Nt;
}

string Note::getType()
{
    return Type;
}

void Note::initNt()
{   
    do
    {
        cout << "Note : ";
        cin >> Nt;
    } while ((Nt < 0) || (Nt >20));
}

void Note::initType()
{
    cout << "Type : ";
    cin.ignore();
    getline(cin, Type);
}

void Note::printNote() //Affichage d'une Note
{
    cout << "\n";
    Mat.printMatiere();
    Etu.printEtudiant();
    cout << "\n";
    cout << "Note : " << Nt << " | " << "Type : " << Type << endl;
}

ostream& operator << (ostream& os,  Note& n)
{
    cout << "\n";
    cout << n.Mat << n.Etu << endl;
    os << "Note : " << n.Nt << " | " << "Type : " << n.Type << endl;
    return os;
}

Note::~Note()
{

}