#ifndef CRUD_NOTE_H
#define CRUD_NOTE_H
#include "Note.h"
#include "crudMatiere.h"
#include "crudEtudiant.h"

void ajoutNote(vector<Note> &tableauNote, vector<Matiere> tableauMatiere, vector<Etudiant> tableauEtudiant);
void initMat(vector<Matiere> tableauMatiere, Note &n);
void initEtu(vector<Etudiant> tableauEtudiant, Note &n);
bool noteExiste(vector<Note> tableauNote, string IdMat, int Id, string Type);
void afficherTableauNote(vector<Note> tableauNote);
void enregistrerTableauNote();
void modifierNote(vector<Note> &tableauNote, vector<Matiere> tableauMatiere, vector<Etudiant> tableauEtudiant);
void supprimerNote(vector<Note> &tableauNote);
void chercherNote(vector<Note> tableauNote);

#endif