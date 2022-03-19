#ifndef CRUD_MATIERE_H
#define CRUD_MATIERE_H
#include "Matiere.h"
#include<string.h>
#include "crudEnseignant.h"

void ajoutMatiere(vector<Matiere> &tableauMatiere , vector<Enseignant> tableauEnseignant);
void initEns(vector<Enseignant> tableauEnseignant, Matiere &m);
bool matiereExiste(vector<Matiere> &tableauMatiere, string IdMat);
void afficherTableauMatiere(vector<Matiere> tableauMatiere);
void enregistrerTableauMatiere();
void supprimerMatiere(vector<Matiere> &tableauMatiere);
void modifierMatiere(vector<Matiere> &tableauMatiere, vector<Enseignant> tableauEnseignant);
void chercherMatiere(vector<Matiere> tableauMatiere);

#endif