/*
 * faireEnfant.c
 *
 *  Created on: 5 févr. 2015
 *      Author: utilisateur
 */
#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int i,j;

void faireEnfant(int pere[], int mere[],int enfant1[],int enfant2[])
	{
	time_t temps;
	srand ((unsigned int)time(&temps));
	int indice;
	indice=rand() % (NB_ARCS+1);
	/*printf("indice choisi au hasard: ");
	printf("%d",indice);
	printf("\n");
	printf("pere:  ");*/
	//afficherChromosome(&pere[0]);
	//printf("mere:  ");
	//afficherChromosome(&mere[0]);
	for (j=0;j<indice;j++)
		{
		enfant1[j]=pere[j];
		enfant2[j]=mere[j];
		}
	for (j=indice;j<NB_ARCS;j++)
		{
		enfant1[j]=mere[j];
		enfant2[j]=pere[j];
		}
	//printf("\nenfant1:  ");
	//afficherChromosome(enfant1);
	//printf("\nenfant2:  ");
	//afficherChromosome(enfant2);
	}


