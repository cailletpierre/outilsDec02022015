#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "chromosome.h"


void main(void){

	int a[NB_ARCS]={1,2,3,4};
	int b[NB_ARCS]={2,3,4,5};
	int c[NB_ARCS]={3,4,5,6};
	int d[NB_ARCS]={4,5,6,7};
	int e[NB_ARCS]={5,6,7,8};
	int f[NB_ARCS]={6,7,8,9};
	int g[NB_ARCS]={7,8,9,1};
	int h[NB_ARCS]={8,9,1,2};
	int i[NB_ARCS]={9,1,2,3};
	int j[NB_ARCS]={1,1,2,3};
	int matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION][NB_ARCS]={{1,2,3,4},{2,3,4,5},{3,4,5,6},{4,5,6,7},{5,6,7,8},{6,7,8,9},{7,8,9,1},{8,9,1,2},{9,1,2,3},{1,1,2,3}};
	int matriceAvantSelection[NB_CHROMOSOMES_AVANT_SELECTION][NB_ARCS]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int enfant1[NB_ARCS];
	int enfant2[NB_ARCS];
	int ind1;

//------AFFICHAGE MATRICE INITIALE

	printf("\nMatrice initiale:\n");
		for (ind1=0;ind1<NB_CHROMOSOMES_APRES_SELECTION;ind1++)
			{
			afficherChromosome(matriceApresSelection[ind1]);
			}
	printf("\n");


//-------DECLENCHEMENT D UNE GENERATION

	generation(matriceAvantSelection,matriceApresSelection,enfant1,enfant2);

//-------AFFICHAGE MATRICE AVEC ENFANTS ET MUTATIONS

	int ind2;
	printf("\nMatrice apres generation mais avant selection:\n");
	for (ind2=0;ind2<NB_CHROMOSOMES_AVANT_SELECTION;ind2++)
		{
		afficherChromosome(matriceAvantSelection[ind2]);
		}

//-----SELECTION DES MEILLEURS (à implementer)

	selection(matriceAvantSelection,matriceApresSelection);

//------AFFICHAGE MATRICE APRES SELECTION

	int ind3;
	printf("\nMatrice après selection:\n");
	for (ind3=0;ind3<NB_CHROMOSOMES_APRES_SELECTION;ind3++)
		{
		afficherChromosome(matriceApresSelection[ind3]);
		}
	}


	

	
