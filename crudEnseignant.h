#ifndef CRUD_ENSEIGNANT_H
#define CRUD_ENSEIGNANT_H
#include "Enseignant.h"

void ajoutEnseignant(vector<Enseignant> &tableauEnseignant);
bool enseignantExiste(vector<Enseignant> &tableauEnseignant, int Id);
void afficherTableauEnseignant(vector<Enseignant> tableauEnseignant);
void enregistrerTableauEnseignant();
void supprimerEnseignant(vector<Enseignant> &tableauEnseignant);
void modifierEnseignant(vector<Enseignant> &tableauEnseignant);
void chercherEnseignant(vector<Enseignant> tableauEnseignant);

#endif