#include "Menu.h"

void Menu ()
{
    int choix;
    vector<Etudiant> tableauEtudiant;
    vector<Enseignant> tableauEnseignant;
    vector<Matiere> tableauMatiere;
    vector<GroupeModule> tableauGroupeModule;
    vector<Groupe> tableauGroupe;
    vector<Note> tableauNote;
    lireTableauEtudiant(tableauEtudiant);
    lireTableauEnseignant(tableauEnseignant);
    lireTableauMatiere(tableauMatiere);
    lireTableauNote(tableauNote);
    lireTableauGroupeModule(tableauGroupeModule);
    lireTableauGroupe(tableauGroupe, tableauGroupeModule, tableauEtudiant);

    menuPrincipale :
    cout << "\n**********************************************" << endl;
    cout << "******************  Bienvenu ******************" << endl;
    cout << "\n**********************************************" << endl;
    cout << "* Veuillez choisir une option :               *" << endl;
    cout << "*     1- Gestion des etudiants                *" << endl;
    cout << "*     2- Gestion des enseignats               *" << endl;
    cout << "*     3- Gestion des matieres                 *" << endl;
    cout << "*     4- Gestion des groupes module           *" << endl;
    cout << "*     5- Gestion des groupes                  *" << endl;
    cout << "*     6- Gestion des notes                    *" << endl;
    cout << "*     7- Afficher PV                          *" << endl;
    cout << "*     8- Quitter                              *" << endl;
    cout << "* >> Tapez votre choix :                      *" << endl;
    cout << "--> ";
    cin >> choix;
    switch (choix)
    {
    case 1:
    menuGestionEtudiant :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des etudiants                  *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter etudiant                     *" << endl;
        cout << "*     2- Chercher un etudiant                 *" << endl;
        cout << "*     3- Supprimer etudiant                   *" << endl;
        cout << "*     4- Modifier etudiant                    *" << endl;
        cout << "*     5- Afficher liste des etudiants         *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            ajoutEtudiant(tableauEtudiant);
            goto menuGestionEtudiant;
            break;
        case 2:
            chercherEtudiant(tableauEtudiant);
            goto menuGestionEtudiant;
            break;
        case 3:
            supprimerEtudiant(tableauEtudiant);
            goto menuGestionEtudiant;
            break;
        case 4:
            modifierEtudiant(tableauEtudiant);
            goto menuGestionEtudiant;
            break;
        case 5:
            afficherTableauEtudiant(tableauEtudiant);
            goto menuGestionEtudiant;
            break;
        case 6:
            goto menuPrincipale;
            break;
        default:
                cout << "\n**********************************************" << endl;
                cout << "Choix errone !" << endl;
                cout << "\n**********************************************" << endl;
                goto menuGestionEtudiant;
            break;
        }
        break;
    case 2:
    menuGestionEnseignat :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des enseignats                 *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter enseignat                    *" << endl;
        cout << "*     2- Chercher un enseignat                *" << endl;
        cout << "*     3- Supprimer enseignat                  *" << endl;
        cout << "*     4- Modifier enseignat                   *" << endl;
        cout << "*     5- Afficher liste des enseignats        *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix; 
        switch (choix)
        {
        case 1:
            ajoutEnseignant(tableauEnseignant);
            goto menuGestionEnseignat;
            break;
        case 2:
            chercherEnseignant(tableauEnseignant);
            goto menuGestionEnseignat;
            break;
        case 3:
            supprimerEnseignant(tableauEnseignant);
            goto menuGestionEnseignat;
            break;
        case 4:
            modifierEnseignant(tableauEnseignant);
            goto menuGestionEnseignat;
            break;
        case 5:
            afficherTableauEnseignant(tableauEnseignant);
            goto menuGestionEnseignat;
            break;
        case 6:
            goto menuPrincipale;
            break;
        default:
                cout << "\n**********************************************" << endl;
                cout << "Choix errone !" << endl;
                cout << "\n**********************************************" << endl;
                goto menuGestionEnseignat;
            break;
        }
        break;
    case 3:
    menuGestionMatiere :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des matieres                   *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter matiere                      *" << endl;
        cout << "*     2- Chercher une matiere                 *" << endl;
        cout << "*     3- Supprimer matiere                    *" << endl;
        cout << "*     4- Modifier matiere                     *" << endl;
        cout << "*     5- Afficher liste des matieres          *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix; 
        switch (choix)
        {
        case 1:
            ajoutMatiere(tableauMatiere , tableauEnseignant);
            goto menuGestionMatiere;
            break;
        case 2:
            chercherMatiere(tableauMatiere);
            goto menuGestionMatiere;
            break;
        case 3:
            supprimerMatiere(tableauMatiere);
            goto menuGestionMatiere;
            break;
        case 4:
            modifierMatiere(tableauMatiere, tableauEnseignant);
            goto menuGestionMatiere;
            break;
        case 5:
            afficherTableauMatiere(tableauMatiere);
            goto menuGestionMatiere;
            break;
        case 6:
           goto menuPrincipale;
           break; 
        default:
            cout << "\n**********************************************" << endl;
            cout << "Choix errone !" << endl;
            cout << "\n**********************************************" << endl;
            goto menuGestionEnseignat;
            break;
        }
        break;
    case 4:
    menuGestionGroupeModule :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des groupes module              *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter groupe module                *" << endl;
        cout << "*     2- Chercher un groupe module            *" << endl;
        cout << "*     3- Supprimer groupe module              *" << endl;
        cout << "*     4- Modifier groupe module               *" << endl;
        cout << "*     5- Afficher liste des groupes module    *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix; 
        switch (choix)
        {
        case 1:
            ajoutGroupeModule(tableauGroupeModule, tableauMatiere);
            goto menuGestionGroupeModule;
            break;
        case 2:
            chercherGroupeModule(tableauGroupeModule);
            goto menuGestionGroupeModule;
            break;
        case 3:
            supprimerGroupeModule(tableauGroupeModule);
            goto menuGestionGroupeModule;
            break;
        case 4:
            modifierGroupeModule(tableauGroupeModule, tableauMatiere);
            goto menuGestionGroupeModule;
            break;
        case 5:
            afficherTableauGroupeModule(tableauGroupeModule);
            goto menuGestionGroupeModule;
            break;
        case 6: 
            goto menuPrincipale;
            break;
        default:
            cout << "\n**********************************************" << endl;
            cout << "Choix errone !" << endl;
            cout << "\n**********************************************" << endl;
            goto menuGestionGroupeModule;
            break;
        }
        break;
    case 5:
    menuGestionGroupe :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des groupes                    *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter groupe                       *" << endl;
        cout << "*     2- Chercher groupe                      *" << endl;
        cout << "*     3- Supprimer groupe                     *" << endl;
        cout << "*     4- Modifier groupe                      *" << endl;
        cout << "*     5- Afficher liste des groupes           *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            ajoutGroupe(tableauGroupe, tableauGroupeModule, tableauEtudiant);
            goto menuGestionGroupe;
            break;
        case 2:
            chercherGroupe(tableauGroupe);
            goto menuGestionGroupe;
            break;
        case 3:
            supprimerGroupe(tableauGroupe);
            goto menuGestionGroupe;
            break;
        case 4:
            modifierGroupe(tableauGroupe, tableauGroupeModule, tableauEtudiant);
            goto menuGestionGroupe;
            break;
        case 5:
            afficherTableauGroupe(tableauGroupe);
            goto menuGestionGroupe;
            break;
        case 6:
            goto menuPrincipale;
            break;
        default:
            cout << "\n**********************************************" << endl;
            cout << "Choix errone !" << endl;
            cout << "\n**********************************************" << endl;
            goto menuGestionGroupe;
            break;
        }
        break;
    case 6:
    menuGestionNote :
        cout << "\n**********************************************" << endl;
        cout << "* Menu gestion des notes                      *" << endl;
        cout << "\n**********************************************" << endl;
        cout << "*     1- Ajouter note                         *" << endl;
        cout << "*     2- Chercher note                        *" << endl;
        cout << "*     3- Supprimer note                       *" << endl;
        cout << "*     4- Modifier note                        *" << endl;
        cout << "*     5- Afficher liste des notes             *" << endl;
        cout << "*     6- Retour menu principale               *" << endl;
        cout << "* >> Tapez votre choix :                      *" << endl;
        cout << "--> ";
        cin >> choix;
        switch (choix)
        {
        case 1:
            ajoutNote(tableauNote, tableauMatiere, tableauEtudiant);
            goto menuGestionNote;
            break;
        case 2:
            chercherNote(tableauNote);
            goto menuGestionNote;
            break;
        case 3:
            supprimerNote(tableauNote);
            goto menuGestionNote;
            break;
        case 4:
            modifierNote(tableauNote, tableauMatiere, tableauEtudiant);
            goto menuGestionNote;
            break;
        case 5:
            afficherTableauNote(tableauNote);
            goto menuGestionNote;
            break;
        case 6: 
            goto menuPrincipale;
            break;
        default:
            cout << "\n**********************************************" << endl;
            cout << "Choix errone !" << endl;
            cout << "\n**********************************************" << endl;
            goto menuGestionNote;
            break;
        }
        break;
    case 7:
        affichagePV(tableauGroupe[0], tableauNote);
        goto menuPrincipale;
        break;
    case 8:
        cout << "\n**********************************************" << endl;
        cout << "****************  Au revoir :) ****************";
        cout << "\n**********************************************" << endl;
        break;
    default:
        cout << "\n**********************************************" << endl;
        cout << "Choix errone !" << endl;
        cout << "\n**********************************************" << endl;
        goto menuPrincipale;
        break;
    }

}