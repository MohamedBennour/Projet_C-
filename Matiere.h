#ifndef MATIERE_H
#define MATIERE_H
#pragma once
#include "Enseignant.h"	
class Matiere
{
	private:
		string IdMat, NomMat;
		double Coef;
		Enseignant Ens;
	public:

		Matiere();
		~Matiere();
		Matiere(string IdMat, string NomMat, double Coef, Enseignant Ens);
		void setIdMat(string IdMat);
		void setNomMat(string NomMat);
		void setCoef(double Coef);
		void setEns(Enseignant Ens);
		string getIdMat();
		string getNomMat();
		double getCoef();
		Enseignant getEns();
		void initIdMat();
		void initNomMat();
		void initCoef();
		void printMatiere();
		friend void lireTableauMatiere(vector<Matiere> &tableauMatiere);
		friend ostream& operator << (ostream&,  Matiere&);
};
#endif