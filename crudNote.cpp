#include "crudNote.h"

Note n;

void ajoutNote(vector<Note> &tableauNote, vector<Matiere> tableauMatiere, vector<Etudiant> tableauEtudiant)
{
    int nbrNote = tableauNote.size();

    initMat(tableauMatiere, n);
    initEtu(tableauEtudiant, n);
    n.initType();

    if (nbrNote == 0)
    {
        
        n.initNt();
        tableauNote.push_back(n);
        cout << "-> Ajout effectue avec succes " << endl;
        enregistrerTableauNote();
    }
    else if (noteExiste(tableauNote, n.getMat().getIdMat(), n.getEtu().getId(), n.getType()))
    {
        cout << "-> Erreur element existe ! " << endl;
    }
    else
    {
        n.initNt();
        tableauNote.push_back(n);
        cout << "-> Ajout effectue avec succes " << endl; 
        enregistrerTableauNote();       
    }
}

void initMat(vector<Matiere> tableauMatiere, Note &n)
{
    vector<Matiere>::iterator it;
    string IdMat;
    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;

    if (!matiereExiste(tableauMatiere, IdMat))
    {
        cout << "-> Erreur matiere inexistante ! " << endl;
    }
    else
    {
        for(it = tableauMatiere.begin(); it < tableauMatiere.end(); it++) 
        {
            if (((*it).getIdMat().compare(IdMat)) == 0)
            {
                n.setMat((*it));
            }    
        }
    }
}

void initEtu(vector<Etudiant> tableauEtudiant, Note &n)
{
    vector<Etudiant>::iterator it;
    int Id;

    cout << "Id Etudiant : ";
    cin >> Id;

    if(etudiantExiste(tableauEtudiant, Id))
    {
        for(it = tableauEtudiant.begin(); it < tableauEtudiant.end(); it++) 
        {
            if ((*it).getId() == Id)
            {
                n.setEtu((*it));
            }    
        }       
    }
    else
    {
        cout << "-> Erreur etudiant inexistant ! " << endl;
    }
}

bool noteExiste(vector<Note> tableauNote, string IdMat, int Id, string Type)
{
    vector<Note>::iterator it;
    for(it = tableauNote.begin(); it < tableauNote.end(); it++) 
    {
        if ((((*it).getMat().getIdMat().compare(IdMat)) == 0) && ((*it).getEtu().getId() == Id) && ((*it).getType().compare(Type)) == 0)
        {
            return true;
        } 
    }
    return false;
}

void  afficherTableauNote(vector<Note> tableauNote)
{
    vector<Note>::iterator it;

    for(it = tableauNote.begin(); it != tableauNote.end(); it++) 
    {
        cout << (*it);
        cout << "\n";
    }  
}

void enregistrerTableauNote()
{
    fstream fout("Note.txt", ios::app);

    fout << n.getMat().getIdMat() << " " << n.getMat().getNomMat() << " " << n.getMat().getCoef() << " " 
    << n.getMat().getEns().getId() << " " << n.getMat().getEns().getNom() << " " << n.getMat().getEns().getPrenom()
    << " " << n.getMat().getEns().getMail() << " " << n.getMat().getEns().getCNSS() << " " <<
    n.getEtu().getId() << " " << n.getEtu().getNom() << " " << n.getEtu().getPrenom() << " " << 
    n.getEtu().getMail() << " " << n.getEtu().getNum_insc() << " " << n.getType() << " " << n.getNt() << endl; 

    fout.close();
}

void lireTableauNote(vector<Note> &tableauNote)
{
    int Id, Id1, CNSS, Num_insc;
    string Nom, Prenom, Mail, Nom1, Prenom1, Mail1, IdMat, NomMat;
    double Coef;
    ifstream fin;
    fin.open("Note.txt");
    tableauNote.clear();
    if (!fin)
    {
        cout << "Error in opening file ! " << endl;
    }

    while (fin >> IdMat >> NomMat >> Coef >> Id >> Nom >> Prenom >> Mail >> CNSS >> Id1 >> Nom1 >> Prenom1 >> Mail1 >> Num_insc >> n.Type >> n.Nt)
    {
        Enseignant ens(Id, Nom, Prenom, Mail, CNSS);
        Matiere m(IdMat, NomMat, Coef, ens);
        n.setMat(m);
        Etudiant e(Id1, Nom1, Prenom1, Mail1, Num_insc);
        n.setEtu(e);

        tableauNote.push_back(n);
    }

    fin.close(); 
}

void modifierNote(vector<Note> &tableauNote, vector<Matiere> tableauMatiere, vector<Etudiant> tableauEtudiant)
{
    vector<Note>::iterator it;
    string IdMat, Type;
    int Id;

    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;
    
    cout << "Id Etudiant : ";
    cin >> Id;

    cout << "Type : ";
    cin >> Type;

    if (noteExiste(tableauNote , IdMat, Id, Type) == false)
    {
        cout << "-> Note inexistant ";
    }
    else
    {
        for(it = tableauNote.begin(); it < tableauNote.end(); it++)
        {
            if ((((*it).getMat().getIdMat().compare(IdMat)) == 0) && ((*it).getEtu().getId() == Id) && ((*it).getType().compare(Type)) == 0)
            {
                (*it).initNt();   
            }
        }

        fstream fout("Note.txt", ios::out);
        for(it = tableauNote.begin(); it < tableauNote.end(); it++)
        {
            fout << (*it).getMat().getIdMat() << " " << (*it).getMat().getNomMat() << " " << (*it).getMat().getCoef() << " " 
            << (*it).getMat().getEns().getId() << " " << (*it).getMat().getEns().getNom() << " " << (*it).getMat().getEns().getPrenom()
            << " " << (*it).getMat().getEns().getMail() << " " << (*it).getMat().getEns().getCNSS() << " " <<
            (*it).getEtu().getId() << " " << (*it).getEtu().getNom() << " " << (*it).getEtu().getPrenom() << " " << 
            (*it).getEtu().getMail() << " " << (*it).getEtu().getNum_insc() << " " << (*it).getType() << " " << (*it).getNt() << endl; 
        }
        fout.close();
    }   
}

void supprimerNote(vector<Note> &tableauNote)
{
    vector<Note>::iterator it;
    string IdMat, Type;
    int Id;

    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;
    
    cout << "Id Etudiant : ";
    cin >> Id;

    cout << "Type : ";
    cin >> Type;

    if (noteExiste(tableauNote , IdMat, Id, Type) == false)
    {
        cout << "-> Note inexistant ";
    }
    else
    {
        for(it = tableauNote.begin(); it < tableauNote.end(); it++)
        {
            if ((((*it).getMat().getIdMat().compare(IdMat)) == 0) && ((*it).getEtu().getId() == Id) && ((*it).getType().compare(Type)) == 0)
            {
                tableauNote.erase(it);
                cout << "-> Suppression effectue avec succes " << endl;   
            }
        }
        
        fstream fout("Note.txt", ios::out);
        for(it = tableauNote.begin(); it < tableauNote.end(); it++)
        {
            fout << (*it).getMat().getIdMat() << " " << (*it).getMat().getNomMat() << " " << (*it).getMat().getCoef() << " " 
            << (*it).getMat().getEns().getId() << " " << (*it).getMat().getEns().getNom() << " " << (*it).getMat().getEns().getPrenom()
            << " " << (*it).getMat().getEns().getMail() << " " << (*it).getMat().getEns().getCNSS() << " " <<
            (*it).getEtu().getId() << " " << (*it).getEtu().getNom() << " " << (*it).getEtu().getPrenom() << " " << 
            (*it).getEtu().getMail() << " " << (*it).getEtu().getNum_insc() << " " << (*it).getType() << " " << (*it).getNt() << endl; 
        }
        fout.close();
        
    }
}

void chercherNote(vector<Note> tableauNote)
{
    vector<Note>::iterator it;
    string IdMat, Type;
    int Id;

    cout << "\n**********************************************" << endl;
    cout << "IdMat : ";
    cin >> IdMat;
    
    cout << "Id Etudiant : ";
    cin >> Id;

    cout << "Type : ";
    cin >> Type;

    if (noteExiste(tableauNote , IdMat, Id, Type) == false)
    {
        cout << "-> Note inexistant ";
    }
    else
    {
        for(it = tableauNote.begin(); it < tableauNote.end(); it++)
        {
            if ((((*it).getMat().getIdMat().compare(IdMat)) == 0) && ((*it).getEtu().getId() == Id) && ((*it).getType().compare(Type)) == 0)
            {
                cout << (*it);   
            }
        }
    }
}