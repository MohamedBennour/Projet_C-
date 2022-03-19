#include "crudEnseignant.h"

Enseignant ens;

void ajoutEnseignant(vector<Enseignant> &tableauEnseignant)
{
    int nbEnseignant = tableauEnseignant.size();

    ens.initId();

    if (nbEnseignant == 0)
    {
        ens.intiNom();
        ens.initPrenom();
        ens.initMail();
        ens.initCNSS();
        tableauEnseignant.push_back(ens);
        cout << "-> Ajout effectue avec succes " << endl;
         enregistrerTableauEnseignant();
    }
    else if (enseignantExiste(tableauEnseignant, ens.getId()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        ens.intiNom();
        ens.initPrenom();
        ens.initMail();
        ens.initCNSS();
        tableauEnseignant.push_back(ens);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauEnseignant();
    }
}

bool enseignantExiste(vector<Enseignant> &tableauEnseignant, int Id)
{
    vector<Enseignant>::iterator it;

    for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
    {
        if ((*it).getId() == Id)
        {
            return true;
        }
    }
    return false;
}

void afficherTableauEnseignant(vector<Enseignant> tableauEnseignant)
{
    vector<Enseignant>::iterator it;

    for (it = tableauEnseignant.begin(); it != tableauEnseignant.end(); it++)
    {
        (*it).printEnseignant();
        cout << "\n";
    }
}

void enregistrerTableauEnseignant()
{
    fstream fout("Enseignant.txt", ios::app);
    fout.open("Enseignant.txt");
    fout << ens.getId() << " " << ens.getNom() << " " << ens.getPrenom() << " " << ens.getMail()
         << " " << ens.getCNSS() << endl;
    fout.close();
}

void lireTableauEnseignant(vector<Enseignant> &tableauEnseignant)
{
    ifstream fin;
    fin.open("Enseignant.txt");
    tableauEnseignant.clear();
    if (!fin)
    {
        cout << "Error in opening file ! " << endl;
    }

    while (fin >> ens.Id >> ens.Nom >> ens.Prenom >> ens.Mail >> ens.CNSS)
    {
        tableauEnseignant.push_back(ens);
    }

    fin.close();
}

void supprimerEnseignant(vector<Enseignant> &tableauEnseignant)
{
    vector<Enseignant>::iterator it;
    int Id;

    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;

    if (enseignantExiste(tableauEnseignant, Id) == false)
    {
        cout << "-> Enseignant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                tableauEnseignant.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;
                enregistrerTableauEnseignant();
            }
        }

        fstream fout("Enseignant.txt", ios::out);
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            fout << (*it).getId() << " " << (*it).getNom() << " " << (*it).getPrenom() << " " << (*it).getMail() << " " << (*it).getCNSS() << endl;
        }
        fout.close();
    }
}

void modifierEnseignant(vector<Enseignant> &tableauEnseignant)
{
    int Id;
    vector<Enseignant>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;
    if (enseignantExiste(tableauEnseignant, Id) == false)
    {
        cout << "-> Enseignant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                (*it).intiNom();
                (*it).initPrenom();
                (*it).initMail();
                (*it).initCNSS();
            }
        }

        fstream fout("Enseignant.txt", ios::out);
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            fout << (*it).getId() << " " << (*it).getNom() << " " << (*it).getPrenom() << " " << (*it).getMail() << " " << (*it).getCNSS() << endl;
        }
        fout.close();

        cout << "-> Modification effectue avec succes " << endl;
    }
}

void chercherEnseignant(vector<Enseignant> tableauEnseignant)
{
    int Id;
    vector<Enseignant>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;
    if (enseignantExiste(tableauEnseignant, Id) == false)
    {
        cout << "-> Enseignant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEnseignant.begin(); it < tableauEnseignant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                cout << (*it);
            }
        }
    }   
}