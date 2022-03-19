#include "crudGroupe.h"

Groupe g;

void ajoutGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant)
{
    int nbrGroupe = tableauGroupe.size();
    g.initIdGRP();

    if (nbrGroupe == 0)
    {
        g.initNiveau();
        g.initDiplome();
        g.initSpecialite();
        g.initNum_G();
        initListeModules(tableauGroupeModule, g);
        initListeEtudiants(tableauEtudiant, g);
        tableauGroupe.push_back(g);
        cout << "-> Ajout effectue avec succes " << endl;
    }
    else if (groupeExiste(tableauGroupe, g.getIdGRP()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        g.initNiveau();
        g.initDiplome();
        g.initSpecialite();
        g.initNum_G();
        initListeModules(tableauGroupeModule, g);
        initListeEtudiants(tableauEtudiant, g);
        tableauGroupe.push_back(g);
        cout << "-> Ajout effectue avec succes " << endl;
    }   
}

void initListeModules(vector<GroupeModule> tableauGroupeModule, Groupe &g)
{
    vector<GroupeModule> ListeModules;
    vector<GroupeModule>::iterator it;
    string choix, IdGM;

    addGroupeModule:
    cout << "Ajouter une module pour ce groupe ? [o/n] ->  ";
    cin >> choix;

    if ((choix.compare("o") == 0) || (choix.compare("O") == 0))
    {
        cout << "IdGM : ";
        cin >> IdGM;

        for(it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++) 
        {
            if (((*it).getIdGm().compare(IdGM)) == 0)
            {
                ListeModules.push_back((*it));
            }
        }
        g.setListeModules(ListeModules);
        goto addGroupeModule;
    }
    else if (((choix.compare("n") == 0) || (choix.compare("N") == 0)))
    {
        cout << "";
    }
    else
    {   
        cout << "Tapez 'o' pour ajouter une module 'n' sinon :) ";
        goto addGroupeModule;
    } 
}

void initListeEtudiants(vector<Etudiant> tableauEtudiant, Groupe &g)
{
    vector<Etudiant> ListeEtudiants;
    vector<Etudiant>::iterator it;
    string choix; 
    int Id;

    addEtudiant:
    cout << "Ajouter un etudiant pour ce groupe ? [o/n] ->  ";
    cin >> choix;

    if ((choix.compare("o") == 0) || (choix.compare("O") == 0))
    {
        cout << "Id : ";
        cin >> Id;

        for(it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++) 
        {
            if ((*it).getId() == Id)
            {
                ListeEtudiants.push_back((*it));
            }
        }
        g.setListeEtudiants(ListeEtudiants);
        goto addEtudiant;
    }
    else if (((choix.compare("n") == 0) || (choix.compare("N") == 0)))
    {
        cout << "";
    }
    else
    {   
        cout << "Tapez 'o' pour ajouter un etudiant 'n' sinon :) ";
        goto addEtudiant;
    } 
}

bool groupeExiste(vector<Groupe> tableauGroupe, string IdGRP)
{
    vector<Groupe>::iterator it;

    for(it = tableauGroupe.begin(); it < tableauGroupe.end(); it++) 
    {
        if (((*it).getIdGRP().compare(IdGRP)) == 0)
        {
            return true;
        }
    }
    return false;
}

void afficherTableauGroupe(vector<Groupe> tableauGroupe)
{
    vector<Groupe>::iterator it;

    for(it = tableauGroupe.begin(); it != tableauGroupe.end(); it++) 
    {
        cout << (*it);
        cout << "\n";
    }  
}

void lireTableauGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant)
{
    Groupe g("GRP1", "Premiere", "ING", "IRM", 1);
    g.setListeModules(tableauGroupeModule);
    g.setListeEtudiants(tableauEtudiant);
    tableauGroupe.push_back(g);
}

void modifierGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant)
{
    vector<Groupe>::iterator it;
    string IdGRP;

    cout << "\n**********************************************" << endl;
    cout << "IdGRP : ";
    cin >> IdGRP;

    if (groupeExiste(tableauGroupe , IdGRP) == false)
    {
        cout << "-> Groupe " << IdGRP << " inexistant ";
    }
    else
    {
        for(it = tableauGroupe.begin(); it < tableauGroupe.end(); it++)
        {
            if (((*it).getIdGRP().compare(IdGRP)) == 0)
            {
                (*it).initNiveau();
                (*it).initDiplome();
                (*it).initSpecialite();
                (*it).initNum_G();
                initListeModules(tableauGroupeModule, (*it));
                initListeEtudiants(tableauEtudiant, (*it));   
            }
        }
    }
}

void supprimerGroupe(vector<Groupe> &tableauGroupe)
{
    vector<Groupe>::iterator it;
    string IdGRP;

    cout << "\n**********************************************" << endl;
    cout << "IdGRP : ";
    cin >> IdGRP;

    if (groupeExiste(tableauGroupe , IdGRP) == false)
    {
        cout << "-> Groupe " << IdGRP << " inexistant ";
    }
    else
    {
        for(it = tableauGroupe.begin(); it < tableauGroupe.end(); it++)
        {
            if (((*it).getIdGRP().compare(IdGRP)) == 0)
            {
                tableauGroupe.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;   
            }
        }
    }
}

void chercherGroupe(vector<Groupe> tableauGroupe)
{
    vector<Groupe>::iterator it;
    string IdGRP;

    cout << "\n**********************************************" << endl;
    cout << "IdGRP : ";
    cin >> IdGRP;

    if (groupeExiste(tableauGroupe , IdGRP) == false)
    {
        cout << "-> Groupe " << IdGRP << " inexistant ";
    }
    else
    {
        for(it = tableauGroupe.begin(); it < tableauGroupe.end(); it++)
        {
            cout << (*it);
        }
    }
}
