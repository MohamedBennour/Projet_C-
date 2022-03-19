#ifndef ETUDIANT_H
#define ETUDIANT_H
#pragma once
#include "Personne.h"

class Etudiant : public Personne
{
	private:
		int Num_insc;

	public:
		Etudiant();
		~Etudiant();
		Etudiant(int Id, string Nom, string Prenom, string Mail, int Num_insc);	
		void setNum_insc(int Num_insc);
		int getNum_insc();
		void initNum_insc();
		void printEtudiant();
		friend void lireTableauEtudiant(vector<Etudiant> &tableauEtudiant);
		friend ostream& operator << (ostream&, Etudiant&);
};
#endif