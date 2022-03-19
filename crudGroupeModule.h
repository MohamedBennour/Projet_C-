#ifndef CRUD_GROUPEMODULE_H
#define CRUD_GROUPEMODULE_H
#include <string.h>
#include "GroupeModule.h"

void ajoutGroupeModule(vector<GroupeModule> &tableauGroupeModule, vector<Matiere> tableauMatiere);
void initListeMat(vector<Matiere> tableauMatiere, GroupeModule &gm);
bool groupeModuleExiste(vector<GroupeModule> tableauGroupeModule, string IdGM);
void afficherTableauGroupeModule(vector<GroupeModule> tableauGroupeModule);
void enregistrerTableauGroupeModule(); 
void supprimerGroupeModule(vector<GroupeModule> &tableauGroupeModule);
void modifierGroupeModule(vector<GroupeModule> &tableauGroupeModule, vector<Matiere> tableauMatiere);
void chercherGroupeModule(vector<GroupeModule> tableauGroupeModule);

#endif