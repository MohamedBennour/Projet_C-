#include "fonctionCalcule.h"

double moyMat(vector<Note> tableauNote, Matiere m, Etudiant e)
{
    double sommeNote = 0;
    int nbrNote = 0;
    vector<Note>::iterator it;

    for(it = tableauNote.begin(); it< tableauNote.end(); it++)
    {
        if(((*it).getMat().getIdMat().compare(m.getIdMat()) == 0) && ((*it).getEtu().getId() == e.getId()))
        {
            nbrNote++;
            sommeNote += (*it).getNt();
        }
    }
    return sommeNote / nbrNote;

}

double moyGM(GroupeModule gm, vector<Note> tableauNote, Etudiant e)
{
    double sommeMoyMat = 0, sommeCoef = 0;

    for(int i = 0; i < gm.getListeMat().size(); i++)
    {
        sommeMoyMat += moyMat(tableauNote,gm.getListeMat().at(i), e) * (gm.getListeMat().at(i).getCoef());
        sommeCoef += gm.getListeMat().at(i).getCoef();
    }

    return sommeMoyMat / sommeCoef;
}

double Moyenne(vector<GroupeModule> tableauGroupeModule, vector<Note> tableauNote, Etudiant e)
{
    double sommeGm = 0, sommeCoef = 0;
    vector<GroupeModule>::iterator it;
    int cmp = 0;

    for(it = tableauGroupeModule.begin(); it < tableauGroupeModule.end(); it++)
    {
        sommeGm += (*it).getCoefGM() * moyGM(tableauGroupeModule[cmp], tableauNote, e);
        sommeCoef += (*it).getCoefGM();
        cmp++;
    }
    return sommeGm / sommeCoef;   
}

string Resultat(double Moy)
{
    if (Moy >= 10)
        return "Admis";
    else
        return "Ajourne" ;   
}

string Mention(double Moy)
{
    if(Moy >= 10 && Moy < 12)
    {
        return "Passable";
    }
    else if(Moy >= 12 &&  Moy < 14)
    {
        return "Assez Bien";
    }
    else if(Moy >= 14 && Moy < 16)
    {
        return "Bien";
    }
    else if(Moy >= 16 && Moy < 18)
    {
        return "Tres Bien";
    }
    else if(Moy >= 18 && Moy < 20)
    {
        return "Excellent";
    }
    else
    {
        return "Ajourne";
    }
}