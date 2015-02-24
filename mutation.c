/*
 * mutation.c
 *
 *  Created on: 6 févr. 2015
 *      Author: utilisateur
 */


#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void mutation(int chromosome[])
	{
	time_t temps;
	srand ((unsigned int)time(&temps));
	int indice;
	indice=rand() % (NB_ARCS+1);
	//afficherChromosome(&chromosome[0]);
	int choixMesure;
	choixMesure=(rand() % (NB_MESURES))+1;
	chromosome[indice]=choixMesure;
	//afficherChromosome(&chromosome[0]);
	}
