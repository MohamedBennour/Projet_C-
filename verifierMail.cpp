// Vérifiez si l'adresse e-mail donnée est valide ou non 

#include "verifierMail.h"

// Fonction pour vérifier le caractère est un alphabet ou pas
bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Fonction pour vérifier le caractère est un chiffre ou non
bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

// Fonction pour vérifier l'adresse mail est valide ou non
bool is_valid(string email)
{
	int taille = email.length();
    // Vérifie le premier caractère est un alphabet ou non
	if (!isChar(email[0])) 
    {

        // Si ce n'est pas un alphabet l'adresse mail n'est pas valide
		return 0;
	}
    // Variable pour stocker la position de At(@) et Point(.)
	int At = -1, Dot = -1;

	// Chercher la posituion de At et Point
	for (int i = 0; i < taille; i++) 
	{

		if (email[i] == '@') 
		{

			At = i;
		}

		else if (email[i] == '.') 
		{

			Dot = i;
		}
	}

	// Si At ou Point n'est pas présent
	if (At == -1 || Dot == -1)
		return 0;

	// Si Point est présent avant At
	if (At > Dot)
		return 0;

	// Si Point est présent à la fin
	return !(Dot >= (taille - 1));
}