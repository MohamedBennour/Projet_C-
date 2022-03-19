#include "crudMatiere.h"

Matiere m;

void ajoutMatiere(vector<Matiere> &tableauMatiere, vector<Enseignant> tableauEnseignant)
{
    int nbMatiere = tableauMatiere.size();

    m.initIdMat();

    if (nbMatiere == 0)
    {
        m.initNomMat();
        m.initCoef();
        initEns(tableauEnseignant, m);
        tableauMatiere.push_back(m);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauMatiere();
    }
    else if (matiereExiste(tableauMatiere, m.getIdMat()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        m.initNomMat();
        m.initCoef();
        initEns(tableauEnseignant, m);
        tableauMatiere.push_back(m);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauMatiere();
    }
}

void initEns(vector<Enseignant> tableauEnseignant, Matiere &m)
{
    vector<Enseignant>::iterator it;
    int Id;

    cout << "Id : ";
    cin >> Id;

    if (!enseignantExiste(tableauEnseignant, Id))
    {
        cout << "-> Erreur enseignant inexistant ! " << endl;
    }
    else
    {
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                m.setEns((*it));
            }
        }
    }
}

bool matiereExiste(vector<Matiere> &tableauMatiere, string IdMat)
{
    vector<Matiere>::iterator it;
    for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
    {
        if (((*it).getIdMat().compare(IdMat)) == 0)
        {
            return true;
        }
    }
    return false;
}

void afficherTableauMatiere(vector<Matiere> tableauMatiere)
{
    vector<Matiere>::iterator it;

    for (it = tableauMatiere.begin(); it != tableauMatiere.end(); it++)
    {
        (*it).printMatiere();
        cout << "\n";
    }
}

void enregistrerTableauMatiere()
{
    fstream fout("Matiere.txt", ios::app);

    fout << m.getIdMat() << " " << m.getNomMat() << " " << m.getCoef() << " " << m.getEns().getId() << " " << m.getEns().getNom()
         << " " << m.getEns().getPrenom() << " " << m.getEns().getMail() << " " << m.getEns().getCNSS() << endl;
    fout.close();
}

void lireTableauMatiere(vector<Matiere> &tableauMatiere)
{
    int Id, CNSS;
    string Nom, Prenom, Mail;
    ifstream fin;
    fin.open("Matiere.txt");
    tableauMatiere.clear();
    if (!fin)
    {
        cout << "Error in opening file ! " << endl;
    }

    while (fin >> m.IdMat >> m.NomMat >> m.Coef >> Id >> Nom >> Prenom >> Mail >> CNSS)
    {
        Enseignant ens(Id, Nom, Prenom, Mail, CNSS);
        m.setEns(ens);
        tableauMatiere.push_back(m);
    }

    fin.close();
}

void supprimerMatiere(vector<Matiere> &tableauMatiere)
{
    vector<Matiere>::iterator it;
    string IdMat;

    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin.ignore();
    getline(cin, IdMat);

    if (matiereExiste(tableauMatiere, IdMat) == false)
    {
        cout << "-> Matiere " << IdMat << " inexistant ";
    }
    else
    {
        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            if (((*it).getIdMat().compare(IdMat)) == 0)
            {
                tableauMatiere.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;
            }
        }

        fstream fout("Matiere.txt", ios::out);
        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            fout << (*it).getIdMat() << " " << (*it).getNomMat() << " " << (*it).getCoef() << " " << (*it).getEns().getId() << " " << (*it).getEns().getNom()
            << " " << (*it).getEns().getPrenom() << " " << (*it).getEns().getMail() << " " << (*it).getEns().getCNSS() << endl;
        }
        fout.close();
    }
}

void modifierMatiere(vector<Matiere> &tableauMatiere, vector<Enseignant> tableauEnseignant)
{
    string IdMat;
    vector<Matiere>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;
    if (matiereExiste(tableauMatiere, IdMat) == false)
    {
        cout << "-> Matiere " << IdMat << " inexistant ";
    }
    else
    {
        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            if (((*it).getIdMat().compare(IdMat)) == 0)
            {
                (*it).initNomMat();
                (*it).initCoef();
                initEns(tableauEnseignant, (*it));
            }
        }

        fstream fout("Matiere.txt", ios::out);
        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            fout << (*it).getIdMat() << " " << (*it).getNomMat() << " " << (*it).getCoef() << " " << (*it).getEns().getId() << " " << (*it).getEns().getNom()
            << " " << (*it).getEns().getPrenom() << " " << (*it).getEns().getMail() << " " << (*it).getEns().getCNSS() << endl;
        }
        fout.close();

        cout << "-> Modification effectue avec succes " << endl;
    }
}

void chercherMatiere(vector<Matiere> tableauMatiere)
{
    string IdMat;
    vector<Matiere>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;
    if (matiereExiste(tableauMatiere, IdMat) == false)
    {
        cout << "-> Matiere " << IdMat << " inexistant ";
    }
    else
    {
        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            if (((*it).getIdMat().compare(IdMat)) == 0)
            {
                cout << (*it);
            }
        }
    }
}