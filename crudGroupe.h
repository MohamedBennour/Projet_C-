#ifndef CRUD_GROUPE_H
#define CRUD_GROUPE_H
#include "Groupe.h"

void ajoutGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant);
void initListeModules(vector<GroupeModule> tableauGroupeModule, Groupe &g);
void initListeEtudiants(vector<Etudiant> tableauEtudiant, Groupe &g);
bool groupeExiste(vector<Groupe> tableauGroupe, string IdGRP);
void afficherTableauGroupe(vector<Groupe> tableauGroupe);
void lireTableauGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant);
void supprimerGroupe(vector<Groupe> &tableauGroupe);
void modifierGroupe(vector<Groupe> &tableauGroupe, vector<GroupeModule> tableauGroupeModule, vector<Etudiant> tableauEtudiant);
void chercherGroupe(vector<Groupe> tableauGroupe);

#endif