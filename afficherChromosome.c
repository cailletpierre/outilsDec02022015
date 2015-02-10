/*
 * afficherChromosome.c
 *
 *  Created on: 6 févr. 2015
 *      Author: utilisateur
 */

#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void afficherChromosome(int chromosome[])
	{
	int m;
	for (m=0;m<NB_ARCS;m++)
		{
		printf("%d",chromosome[m]);
		}
	printf("\n");
	}

