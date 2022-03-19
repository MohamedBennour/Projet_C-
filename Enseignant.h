#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#pragma once
#include "Personne.h"
	
class Enseignant : public Personne
{
	private:
		int CNSS;

	public:
		Enseignant();
		~Enseignant();
		Enseignant(int Id, string Nom, string Prenom, string Mail, int CNSS);
		void setCNSS(int CNSS);
		int getCNSS();
		void initCNSS();
		void printEnseignant();
		friend void lireTableauEnseignant(vector<Enseignant> &tableauEnseignant);
		friend ostream& operator << (ostream&, Enseignant&);
};
#endif