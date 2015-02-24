/*
 * noterUnChromosome.c
 *
 *  Created on: 9 févr. 2015
 *      Author: utilisateur
 */


#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int noterUnChromosome(int chromosome[])
	{
	int res,m;
	res=0;
	for (m=0;m<NB_ARCS;m++)
			{
			res=res+chromosome[m];
			}
	return res;
	}
