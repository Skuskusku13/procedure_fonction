/* Gestion des tableaux */
#include <stdio.h>
#include <stdlib.h>

//Declaration du tableau global
int tab [100];
// Liste des signatures des donctuon en C
void saisir (int taille);
void afficher (int tab [], int taille);
float moyenne (int tab [], int taille0);
void min_max (int tab [], int taille);
int rechercher (int tab [], int taille, int valeur);
int remplacer (int tab [], int taille, int v1, int v2);
void rotationG (int tab [], int taille, int nbrot);
void rotationG (int tab [], int taille, int nbrot);
void diviseursDesElements (int tab [], int taille);
void factorielDesElements (int tab [], int taille);
void fibonacciDesElements (int tab [], int taille);
void menu ();

//programme principal
int main () {
    menu ();
    return 0;
}

//realisation des fonctions
void saisir (int taille)
{
	int i;
	
	for(i = 0; i<taille; i++)
	{
		printf("Donnez un �l�ment :");
		scanf("%d", & tab[i]);
	}
}
void afficher (int tab[], int taille)
{
	int i;
	printf("\n\t\t ___ voici le tableau _____\n");
	for(i=0; i<taille; i++)
	{
		printf("\n\t\t element :  %d", tab[i]);	
	}	
}
float moyenne (int tab [], int taille)
{
	int somme;
	float moyenne;
	int i;
	
	somme = 0;
	
	for(i=0; i<taille; i++)
	{
		somme += tab[i];
	}	
	moyenne = (float)somme / taille;
	return moyenne;
}
void min_max (int tab [], int taille)
{
	int i;
	int min=tab [0];
	int max=tab[0];
	
	for(i=0; i<taille; i++)
	{
		if(tab[i]<min)
		{
			min=tab[i];
		}
		if(tab[i]>max)
		{
			max=tab[i];
		}
	}
	printf("\n\t\t La valeur minimale : %d", min);
	printf("\n\t\t La valeur maximale : %d", max);
}
int rechercher (int tab [], int taille, int valeur)
{
    int compteur = 0 ; 
    int i = 0;
	for (i=0; i<taille; i++)
	{
        if (tab[i]==valeur) 
		{
            compteur++ ; 
    	}
    }
  return compteur;
}
int remplacer (int tab [], int taille, int v1, int v2)
{
	int compteur;
	int i;
	compteur=0;
	i=0;
	
	for (i=0; i<taille; i++)
	{
		if(tab[i]==v1)
		{
			tab[i]=v2;
			compteur++;
		}
	}
	return compteur;
}
void rotationG (int tab[], int taille, int nbrot){
    int i, j;
    int temp; 
    for (j=1; j<=nbrot; j++){

    temp = tab[0] ;
     for(i = 0; i <taille- 1; i++){
             tab[i] = tab[i + 1];
     }

      tab[taille-1] = temp; 
  }
  printf("\n\t\t Rotation effectuee avec succes!");
}
void rotationD (int tab[], int taille, int nbrot){
    int i, j;
    int temp; 
    for (j=1; j<=nbrot; j++){

    temp = tab[taille-1] ;
     for(i = taille-1;i>0; i--){
             tab[i] = tab[i-1];
     }

      tab[0]=temp; 
  }
  printf("\n\t\t Rotation effectuee avec succes!");
}
void diviseursDesElements (int tab [], int taille)
{
	int i, div;
	
	for(i=0; i<taille; i++)
	{
		printf("\n\t\t %d a pour diviseurs: ", tab[i]);
		for(div=1; div<=tab[i]; div++)
		{
			if(tab[i]%div==0)
			printf("%d", div);
		}
	}
	
}
void factorielDesElements (int tab [], int taille)
{
	int i, j, fact;

	for(i=0; i<taille; i++)
	{
		printf("\n\t\t la factoriel de %d est :", tab[i]);
		fact = 1;
		for(j=1; j<=tab[i]; j++)
		{
			fact=fact*j;	
		}
		printf("%d", fact);
	}
	
}
void fibonacciDesElements (int tab [], int taille)
{
	int i, j;
	int a, b, c;
	
	
	for(i=0; i<taille; i++)
	{
		a=0;
		b=1;
		for(j=1; j<=tab[i]; j++)
		{
			c = a+b;
			a = b;
			b = c;
		}
		printf("\n\t\t le fibonnacci de %d est : %d", tab[i], c);
	}
		
}
void menu ()
{
	printf("\n\t\t__TP Gestion des tableaux____");
	int choix = 0;
	int nbelements;
	do
	{
		printf("\n\t\t ____________Menu_______________");
		printf("\n\t\t 1- Saisie des elements");
		printf("\n\t\t 2- Afficher le tableau");
		printf("\n\t\t 3- La moyenne des elements");
		printf("\n\t\t 4- Les valeurs min et max");
		printf("\n\t\t 5- la recherche d'une valeur");
		printf("\n\t\t 6- Remplacer des valeurs");
		printf("\n\t\t 7- Rotation a gauche");
		printf("\n\t\t 8- Rotation a droite");
		printf("\n\t\t 9- les diviseurs des �lements");
		printf("\n\t\t 10- Les factoriels");
		printf("\n\t\t 11- les fibonaccis");
		printf("\n\t\t 0- Quiter la prog");
		printf("\n\t\t _________________________________");
		printf("\n\t\t Votre choix :");
		scanf("%d", & choix);
		switch (choix)
		{
			case 1 :
				printf("\n\t\t Donner le nombre d'elements'");
				scanf("%d", &nbelements);
				saisir(nbelements);
				break;
			case 2 : 
				afficher(tab, nbelements);
				break;
			case 3:
				printf("\n\t\t La moyenne des elements est de : %f", moyenne(tab, nbelements));
				break;
			case 4 :
				min_max (tab, nbelements);
				break;
			case 5 : 
			{
			int valeur; 
			printf("\n\t\t Donnez la valeur a rechercher :");
			scanf("%d", &valeur);
			printf("\n\t\t La valeur apparait %d fois dans le tableau.", rechercher(tab, nbelements, valeur));
			break;
			}
			case 6 :
			{
			int v1, v2; 
			printf("\n\t\t Donnez la valeur a remplacer :");
			scanf("%d", &v1);
			printf("\n\t\t Donnez la nouvelle valeur :");
			scanf("%d", &v2);
			printf("\n\t\t La valeur %d apparait  et a �t� remplac�e %d fois dans le tableau.", v1, remplacer(tab, nbelements, v1, v2));
			break;
			}
			case 7 :
			{
				int nbrot;
				printf("\n\t\t Nombre de rotations � gauche :");
				scanf("%d", &nbrot);
				rotationG(tab, nbelements, nbrot);
			}
			break;
			case 8 :
			{
				int nbrot;
				printf("\n\t\t Nombre de rotations � droite :");
				scanf("%d", &nbrot);
				rotationD(tab, nbelements, nbrot);
			}
			break;
			case 9 :
			diviseursDesElements(tab, nbelements);
			break;
			case 10 :
			factorielDesElements(tab, nbelements);
			break;
			case 11 :
			fibonacciDesElements(tab, nbelements);
			break;
			
			
				
		}
	}
	while(choix!= 0);
}
