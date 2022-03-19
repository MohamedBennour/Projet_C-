#ifndef PERSONNE_H
#define PERSONNE_H
#pragma once
#include "verifierMail.h"
#include<vector>
#include<iostream>
#include <fstream>
using namespace std;



class Personne  
{
	private:

		
	public:
		Personne();
		~Personne();
		Personne(int Id, string Nom, string Prenom, string Mail);
		void setId(int Id);
		void setNom(string Nom);
		void setPrenom(string Prenom);
		void setMail(string Mail);
		int getId();
		string getNom();
		string getPrenom();
		string getMail();
		void initId();
		void intiNom();
		void initPrenom();
		void initMail();
		void printPersonne();
		friend ostream& operator << (ostream&, Personne&);

	protected:
		int Id;
		string Nom, Prenom, Mail;

};
#endif