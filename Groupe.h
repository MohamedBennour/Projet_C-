#ifndef GROUPE_H
#define GROUPE_H
#pragma once
#include "GroupeModule.h"
#include "Etudiant.h"

class Groupe
{
    private:
        string IdGRP, Niveau, Diplome, Specialite;
        int Num_G;
        vector<GroupeModule> ListeModules;
        vector<Etudiant> ListeEtudiants;

    public:
        Groupe();
        Groupe(string IdGRP, string Niveau, string Diplome, string Specialite, int Num_G);
        ~Groupe();
        void setIdGRP(string IdGRP);
        void setNiveau(string Niveau);
        void setDiplome(string Diplome);
        void setSpecialite(string Specialite);
        void setNum_G(int Num_G);
        void setListeModules(vector<GroupeModule> ListeModules);
        void setListeEtudiants(vector<Etudiant> ListeEtudiants);
        string getIdGRP();
        string getNiveau();
        string getDiplome();
        string getSpecialite();
        int getNum_G();
        vector<GroupeModule> getListeModules();
        vector<Etudiant> getListeEtudiants();
        void initIdGRP();
        void initNiveau();
        void initDiplome();
        void initSpecialite();
        void initNum_G();
        void printGroupe();
        friend ostream& operator << (ostream&,  Groupe&);
};

#endif