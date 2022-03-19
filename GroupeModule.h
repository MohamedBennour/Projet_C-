#ifndef GROUPEMODULE_H
#define GROUPEMODULE_H
#pragma once
#include<vector>
#include "Matiere.h"

class GroupeModule  
{
	private:
		string IdGM, NomGM;
		double CoefGM;
		vector<Matiere> ListeMat;

	public:
		GroupeModule();
		~GroupeModule();
		GroupeModule(string IdGM, string NomGM, double CoefGM);
		void setIdGM(string IdGM);
		void setNomGM(string NomGM);
		void setCoefGM(double CoefGM);
		void setListeMat(vector<Matiere> ListeMat);
		string getIdGm();
		string getNomGM();
		double getCoefGM();
		vector<Matiere> getListeMat();
		void initIdGM();
		void initNomGM();
		void initCoefGM();
		void printGroupeModule();
		friend void lireTableauGroupeModule(vector<GroupeModule> &tableauGroupeModule);
		friend ostream& operator << (ostream&,  GroupeModule&);
};
#endif