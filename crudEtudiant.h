#ifndef CRUD_ETUDIANT_H
#define CRUD_ETUDIANT_H
#include "Etudiant.h"
#include "verifierMail.h"

void ajoutEtudiant(vector<Etudiant> &tableauEtudiant);
bool etudiantExiste(vector<Etudiant> tableauEtudiant, int Id);
void afficherTableauEtudiant(vector<Etudiant> tableauEtudiant);
void enregistrerTableauEtudiant();
void supprimerEtudiant(vector<Etudiant> &tableauEtudiant);
void modifierEtudiant(vector<Etudiant> &tableauEtudiant);
void chercherEtudiant(vector<Etudiant> tableauEtudiant);

#endif