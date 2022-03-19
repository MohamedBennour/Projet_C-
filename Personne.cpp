#include "Personne.h" 

// Un constructeur par défaut (sans paramètres)
Personne::Personne()
{
    Id = -1;

}

// Un constructeur avec paramètres
Personne::Personne(int Id, string Nom, string Prenom, string Mail)
{
    this->Id = Id;
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Mail = Mail;
}


// Setter
void Personne::setId(int Id)
{
    this->Id = Id;
}

void Personne::setNom(string Nom)
{
    this->Nom = Nom;
}

void Personne::setPrenom(string Prenom)
{
    this->Prenom = Prenom;
}

void Personne::setMail(string Mail)
{
    this->Mail = Mail;
}

// Getter
int Personne::getId()
{
    return Id;
}

string Personne::getNom()
{
    return Nom;
}

string Personne::getPrenom()
{
    return Prenom;
}

string Personne::getMail()
{
    return Mail;
}

void Personne::initId()
{
    cout << "\n*******************" << endl;
    cout << "Id : ";
    cin >> Id;
}

void Personne::intiNom()
{
    cout << "Nom : ";
    cin.ignore();
    getline(cin, Nom);
}

void Personne::initPrenom()
{
    cout << "Prenom : ";
    getline(cin, Prenom);
}

void Personne::initMail()
{
    string Mail;

    mail :
    cout << "Mail : ";
    getline(cin, Mail); 

    if (is_valid(Mail))
    {
        this->Mail = Mail;
    }
    else
    {
        cout << Mail << " : Echec (adresse mail invalid) -> Essayer de nouveau" << endl;
        goto mail;
    }
}

void Personne::printPersonne() // Affichage d'un Personne
{
    cout << "\n";
    cout << "Id : " << Id << " | " << "Nom : " << Nom << " | " << "Prenom : " << Prenom 
    << " | " << "Mail : " << Mail;
}

ostream& operator << (ostream& os, Personne &p)
{
    os << "Id : " << p.Id << " | " << "Nom : " << p.Nom << " | " << "Prenom : " << p.Prenom 
    << " | " << "Mail : " << p.Mail;

    return os;
}

Personne::~Personne()
{
	
}