#include "crudGroupeModule.h"

GroupeModule gm;

void ajoutGroupeModule(vector<GroupeModule> &tableauGroupeModule, vector<Matiere> tableauMatiere)
{
    int nbGroupeModule = tableauGroupeModule.size();

    gm.initIdGM();

    if (nbGroupeModule == 0)
    {
        gm.initNomGM();
        gm.initCoefGM();
        initListeMat(tableauMatiere, gm);
        tableauGroupeModule.push_back(gm);
        enregistrerTableauGroupeModule();
        cout << "-> Ajout effectue avec succes " << endl;
    }
    else if (groupeModuleExiste(tableauGroupeModule, gm.getIdGm()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        gm.initNomGM();
        gm.initCoefGM();
        initListeMat(tableauMatiere, gm);
        tableauGroupeModule.push_back(gm);
        enregistrerTableauGroupeModule();
        cout << "-> Ajout effectue avec succes " << endl;
    }
}

void initListeMat(vector<Matiere> tableauMatiere, GroupeModule &gm)
{
    vector<Matiere> ListeMat;
    vector<Matiere>::iterator it;
    string choix, IdMat;

addMatiere:
    cout << "Ajouter une matiere pour ce module ? [o/n] ->  ";
    cin >> choix;

    if ((choix.compare("o") == 0) || (choix.compare("O") == 0))
    {
        cout << "IdMat : ";
        cin >> IdMat;
        fstream fout("listeMat.txt", ios::app);

        for (it = tableauMatiere.begin(); it < tableauMatiere.end(); it++)
        {
            if (((*it).getIdMat().compare(IdMat)) == 0)
            {
                ListeMat.push_back((*it));
                fout << gm.getIdGm() << " " << (*it).getIdMat() << " " << (*it).getNomMat() << " " << 
                (*it).getCoef() << " " << (*it).getEns().getId() << " " << (*it).getEns().getNom() << " " << 
                (*it).getEns().getPrenom() << " " << (*it).getEns().getMail() << " " << (*it).getEns().getCNSS() << endl;
            }
        }
        fout.close();
        gm.setListeMat(ListeMat);
        goto addMatiere;
    }
    else if (((choix.compare("n") == 0) || (choix.compare("N") == 0)))
    {
        cout << "";
    }
    else
    {
        cout << "Tapez 'o' pour ajouter une matiere 'n' sinon :) ";
        goto addMatiere;
    }
}

bool groupeModuleExiste(vector<GroupeModule> tableauGroupeModule, string IdGM)
{
    vector<GroupeModule>::iterator it;

    for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
    {
        if (((*it).getIdGm().compare(IdGM)) == 0)
        {
            return true;
        }
    }
    return false;
}

void lireTableauGroupeModule(vector<GroupeModule> &tableauGroupeModule)
{
    int Id, CNSS;
    string Nom, Prenom, Mail, IdMat, NomMat, IdGM, NomGM;
    double Coef, CoefGM;
    ifstream fich, fich1;
    fich.open("GroupeModule.txt");
    tableauGroupeModule.clear();

    if ((!fich) || (!fich1))
    {
        cout << "Error in opening file ! " << endl;
        exit(1);
    }

    while (fich >> IdGM >> NomGM >> CoefGM)
    {
        GroupeModule gm1(IdGM, NomGM, CoefGM);
        fich1.open("listeMat.txt");

        while (fich1 >> IdGM >> IdMat >> NomMat >> Coef >> Id >> Nom >> Prenom >> Mail >> CNSS)
        {
            if (gm1.IdGM.compare(IdGM) == 0)
            {
                Enseignant e(Id, Nom, Prenom, Mail, CNSS);
                Matiere m(IdMat, NomMat, Coef, e);
                gm1.ListeMat.push_back(m);
            }
        }
        fich1.close();

        tableauGroupeModule.push_back(gm1);
    }
}

void afficherTableauGroupeModule(vector<GroupeModule> tableauGroupeModule)
{
    vector<GroupeModule>::iterator it;

    for (it = tableauGroupeModule.begin(); it != tableauGroupeModule.end(); it++)
    {
        cout << (*it) << endl;
        cout << "\n";
    }
}

void enregistrerTableauGroupeModule()
{
    fstream fout("GroupeModule.txt", ios::app);
    fstream fich1("listeMat.txt", ios::app);
    vector<Matiere>::iterator it;

    fout << gm.getIdGm() << " " << gm.getNomGM() << " " << gm.getCoefGM() << endl;

    for (it = gm.getListeMat().begin(); it < gm.getListeMat().end(); it++)
    {   
        fich1 << gm.getIdGm() << " " << (*it).getIdMat() << " " << (*it).getNomMat() << " " << 
        (*it).getCoef() << " " << (*it).getEns().getId() << " " << (*it).getEns().getNom() << " " << 
        (*it).getEns().getPrenom() << " " << (*it).getEns().getMail() << " " << (*it).getEns().getCNSS() << endl;
    }

    fich1.close();
}

void modifierGroupeModule(vector<GroupeModule> &tableauGroupeModule, vector<Matiere> tableauMatiere)
{
    string IdGM;
    vector<GroupeModule>::iterator it;
    vector<Matiere>::iterator it1;
    cout << "\n**********************************************" << endl;
    cout << "IdGM : ";
    cin >> IdGM;
    if (groupeModuleExiste(tableauGroupeModule, IdGM) == false)
    {
        cout << "-> Groupe Module " << IdGM << " inexistant ";
    }
    else
    {
        for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
        {
            if (((*it).getIdGm().compare(IdGM)) == 0)
            {
                (*it).initNomGM();
                (*it).initCoefGM();
              initListeMat(tableauMatiere, (*it));
            }
        }

        fstream fich1("GroupeModule.txt", ios::out);
        fstream fich2("listeMat.txt", ios::out);
        for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
        {
            fich1 << (*it).getIdGm() << " " << (*it).getNomGM() << " " << (*it).getCoefGM() << endl; 
            for (it1 = (*it).getListeMat().begin(); it1 < (*it).getListeMat().end(); it1++)
            {
                fich2 << (*it).getIdGm() << " " << (*it1).getIdMat() << " " << (*it1).getNomMat() << " " << 
                (*it1).getCoef() << " " << (*it1).getEns().getId() << " " << (*it1).getEns().getNom() << " " << 
                (*it1).getEns().getPrenom() << " " << (*it1).getEns().getMail() << " " << (*it1).getEns().getCNSS() << endl;
            }
        }
        fich1.close();
        fich2.close();
        cout << "-> Modification effectue avec succes " << endl;
    }
}

void supprimerGroupeModule(vector<GroupeModule> &tableauGroupeModule)
{
    vector<GroupeModule>::iterator it;
    vector<Matiere>::iterator it1;
    string IdGM;

    cout << "\n**********************************************" << endl;
    cout << "IdGM : ";
    cin.ignore();
    getline(cin, IdGM);

    if (groupeModuleExiste(tableauGroupeModule, IdGM) == false)
    {
        cout << "-> Groupe Module " << IdGM << " inexistant ";
    }
    else
    {
        for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
        {
            if (((*it).getIdGm().compare(IdGM)) == 0)
            {
                tableauGroupeModule.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;
            }
        }
        fstream fich1("GroupeModule.txt", ios::out);
        fstream fich2("listeMat.txt", ios::out);
        for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
        {
            fich1 << (*it).getIdGm() << " " << (*it).getNomGM() << " " << (*it).getCoefGM() << endl; 
            for (it1 = (*it).getListeMat().begin(); it1 < (*it).getListeMat().end(); it1++)
            {
                fich2 << (*it).getIdGm() << " " << (*it1).getIdMat() << " " << (*it1).getNomMat() << " " << 
                (*it1).getCoef() << " " << (*it1).getEns().getId() << " " << (*it1).getEns().getNom() << " " << 
                (*it1).getEns().getPrenom() << " " << (*it1).getEns().getMail() << " " << (*it1).getEns().getCNSS() << endl;
            }
        }
        fich1.close();
        fich2.close();
    }
}

void chercherGroupeModule(vector<GroupeModule> tableauGroupeModule)
{
    string IdGM;
    vector<GroupeModule>::iterator it;
    cout << "\n**********************************************" << endl;
    cout << "IdGM : ";
    cin >> IdGM;
    if (groupeModuleExiste(tableauGroupeModule, IdGM) == false)
    {
        cout << "-> Groupe Module " << IdGM << " inexistant ";
    }
    else
    {
        for (it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
        {
            if (((*it).getIdGm().compare(IdGM)) == 0)
            {
                cout << (*it);
            }
        }
    }  
}