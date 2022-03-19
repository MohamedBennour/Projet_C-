#ifndef FONCTION_CALCULE_H
#define FONCTION_CALCULE_H
#include "Menu.h"

double moyMat(vector<Note> tableauNote, Matiere m, Etudiant e);
double moyGM(GroupeModule gm, vector<Note> tableauNote, Etudiant e);
double Moyenne(vector<GroupeModule> tableauGroupeModule, vector<Note> tableauNote, Etudiant e);
string Resultat(double Moy);
string Mention(double Moy);

#endif