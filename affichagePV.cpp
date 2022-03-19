#include "affichagePV.h"

void affichagePV(Groupe grp, vector<Note> tableauNote)
{

	cout << setw(100) << grp.getIdGRP() << " " << grp.getNiveau() << " " << grp.getDiplome() << " " <<
    grp.getSpecialite() << "-" << grp.getNum_G() << endl;
    cout << endl;
	cout << setfill(' ') << left << setw(60) << " ";

	for (int i = 0; i < grp.getListeModules().size(); i++) 
    {
		cout << setfill(' ') << setw(10 * (grp.getListeModules().at(i).getListeMat().size()+1)+ grp.getListeModules().at(i).getListeMat().size()) << grp.getListeModules().at(i).getNomGM() << "|";
	}
	cout << setw(10) << "Moyenne" << "|" << setw(10) << "Resultat" << "|" << setw(10) << "Mention" << "|";
	cout << endl;
	cout << setfill(' ') << left << setw(60) << " ";

	for (int i = 0;i < grp.getListeModules().size();i++) 
    {
		cout << setfill(' ') << setw(10 * (grp.getListeModules().at(i).getListeMat().size() + 1) + grp.getListeModules().at(i).getListeMat().size()) << grp.getListeModules().at(i).getCoefGM() << "|";
	}
	cout << endl;
	cout << setfill(' ') << left << setw(60) << " ";

	for(int i = 0; i < grp.getListeModules().size(); i++)
	{
		for (int j = 0; j < grp.getListeModules().at(i).getListeMat().size(); j++)
		{
			cout << setfill(' ') << setw(10) << grp.getListeModules().at(i).getListeMat().at(j).getNomMat() << "|";
		}
		cout << setw(10) << "Moyenne" << "|";
			
	}
	cout << endl;
	cout << setfill(' ') << left << setw(60) << " ";

	for(int i = 0; i < grp.getListeModules().size(); i++)
	{
		for(int j = 0; j < grp.getListeModules().at(i).getListeMat().size(); j++)
		{
			cout << setprecision(0) << setw(10) << grp.getListeModules().at(i).getListeMat().at(j).getCoef() << "|";
		}
		cout << setw(10) << " " << "|";
	}
	cout << endl;
	cout << setw(15) << "Numero" << "|" << setw(15) << "Nom" << "|" << setw(15) << "Prenom" << endl;
	for(int i=0;i<grp.getListeEtudiants().size();i++)
	{
		double moy = 0;
		double moy_mat = 0;
		double moy_gm = 0;
        cout << setw(15) << grp.getListeEtudiants().at(i).getNum_insc() << "|" << setw(15) 
        << grp.getListeEtudiants().at(i).getNom() << "|" << setw(28) << grp.getListeEtudiants().at(i).getPrenom();

		for(int j = 0; j < grp.getListeModules().size(); j++)
		{
			double coef = 0;
			double note = 0;
			for (int k = 0; k < grp.getListeModules().at(j).getListeMat().size(); k++) 
            {
                moy_mat = moyMat(tableauNote, grp.getListeModules().at(j).getListeMat().at(k), grp.getListeEtudiants().at(i));
				moy_gm = moyGM(grp.getListeModules().at(j), tableauNote, grp.getListeEtudiants().at(i));
				moy = Moyenne(grp.getListeModules(), tableauNote, grp.getListeEtudiants().at(i));
                cout << setprecision(2) << setfill(' ') << setw(10) << moy_mat << "|";
			}		
			cout << fixed;
			cout << setfill(' ') << setw(10) << moy_gm << '|';
			
		}
		cout << setfill(' ') << setw(10) << moy << "|" << setw(10) << Resultat(moy) << "|" << setw(10) << Mention(moy) << "|";
		cout << endl;
	}
	
}