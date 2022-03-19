#ifndef NOTE_H
#define NOTE_H
#pragma once
#include "Groupe.h"

class Note
{
    private:
        Matiere Mat;
        Etudiant Etu;
        double Nt;
        string Type;
    public:
        Note();
        Note(Matiere Mat, Etudiant Etu, double Nt, string Type);
        ~Note();
        void setMat(Matiere Mat);
        void setEtu(Etudiant Etu);
        void setNt(double Nt);
        void setType(string Type);
        Matiere getMat();
        Etudiant getEtu();
        double getNt();
        string getType();
        void initNt();
        void initType();
        void printNote();
        friend void lireTableauNote(vector<Note> &tableauNote);
        friend ostream& operator << (ostream&,  Note&);
};

#endif