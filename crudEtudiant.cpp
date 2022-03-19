#include "crudEtudiant.h"

Etudiant e;

void ajoutEtudiant(vector<Etudiant> &tableauEtudiant)
{
    int nbEtudiant = tableauEtudiant.size();

    e.initId();

    if (nbEtudiant == 0)
    {
        e.intiNom();
        e.initPrenom();
        e.initMail();
        e.initNum_insc();
        tableauEtudiant.push_back(e);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauEtudiant();
    }
    else if (etudiantExiste(tableauEtudiant, e.getId()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        e.intiNom();
        e.initPrenom();
        e.initMail();
        e.initNum_insc();
        tableauEtudiant.push_back(e);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauEtudiant();
    }
}

bool etudiantExiste(vector<Etudiant> tableauEtudiant, int Id)
{
    vector<Etudiant>::iterator it;

    for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
    {
        if ((*it).getId() == Id)
        {
            return true;
        }
    }
    return false;
}

void afficherTableauEtudiant(vector<Etudiant> tableauEtudiant)
{
    vector<Etudiant>::iterator it;

    for (it = tableauEtudiant.begin(); it != tableauEtudiant.end(); it++)
    {
        (*it).printEtudiant();
        cout << "\n";
    }
}

void enregistrerTableauEtudiant()
{
    fstream fout("Etudiant.txt", ios::app);

    fout << e.getId() << " " << e.getNom() << " " << e.getPrenom() << " " << e.getMail() << " " << e.getNum_insc() << endl;
    fout.close();
}

void lireTableauEtudiant(vector<Etudiant> &tableauEtudiant)
{
    ifstream fin;
    fin.open("Etudiant.txt");
    tableauEtudiant.clear();

    if (!fin)
    {
        cout << "Error in opening file ! " << endl;
    }

    while (fin >> e.Id >> e.Nom >> e.Prenom >> e.Mail >> e.Num_insc)
    {
        tableauEtudiant.push_back(e);
    }

    fin.close();
}

void supprimerEtudiant(vector<Etudiant> &tableauEtudiant)
{
    vector<Etudiant>::iterator it;
    int Id;

    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;

    if (etudiantExiste(tableauEtudiant, Id) == false)
    {
        cout << "-> Etudiant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                tableauEtudiant.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;
            }
        }

        fstream fout("Etudiant.txt", ios::out);
        for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
        {
            fout << (*it).getId() << " " << (*it).getNom() << " " << (*it).getPrenom() << " " << (*it).getMail() << " " << (*it).getNum_insc() << endl;
        }
        fout.close();
    }
}

void modifierEtudiant(vector<Etudiant> &tableauEtudiant)
{
    int Id;
    vector<Etudiant>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;
    if (etudiantExiste(tableauEtudiant, Id) == false)
    {
        cout << "-> Etudiant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                (*it).intiNom();
                (*it).initPrenom();
                (*it).initMail();
                (*it).initNum_insc();
            }
        }

        fstream fout("Etudiant.txt", ios::out);
        for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
        {
            fout << (*it).getId() << " " << (*it).getNom() << " " << (*it).getPrenom() << " " << (*it).getMail() << " " << (*it).getNum_insc() << endl;
        }
        fout.close();

        cout << "-> Modification effectue avec succes " << endl;
    }
}

void chercherEtudiant(vector<Etudiant> tableauEtudiant)
{
    int Id;
    vector<Etudiant>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "Id : ";
    cin >> Id;
    if (etudiantExiste(tableauEtudiant, Id) == false)
    {
        cout << "-> Etudiant " << Id << " inexistant ";
    }
    else
    {
        for (it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++)
        {
            if ((*it).getId() == Id)
            {
                cout << (*it);
            }
        }
    }
}