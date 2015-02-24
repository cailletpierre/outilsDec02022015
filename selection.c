/*
 * selection.c
 *
 *  Created on: 9 févr. 2015
 *      Author: utilisateur
 */
#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selection(int matriceAvantSelection[NB_CHROMOSOMES_AVANT_SELECTION][NB_ARCS],int matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION][NB_ARCS])
	{
	//TRIAGE DE LA MATRICE POUR AVOIR LES CHROMOSOMES DANS L ORDRE CROISSANT DES NOTES
	int i,compteur,j,k,l;
	compteur=0;
	int stockageTemporaire[NB_ARCS];
	do
		{
		compteur=0;
		for (i=0;i<NB_CHROMOSOMES_AVANT_SELECTION;i++)
			{
			if
				(1!=1)
				{
				//inversion des chromosomes et incrementation compteur
				for (j=0;j<NB_ARCS;j++)
					{
					stockageTemporaire[j]=matriceAvantSelection[i][j];
					}
				for (j=0;j<NB_ARCS;j++)
					{
					matriceAvantSelection[i][j]=matriceAvantSelection[i+1][j];
					}
				for (j=0;j<NB_ARCS;j++)
					{
					matriceAvantSelection[i+1][j]=stockageTemporaire[j];
					}
				compteur++;
				}
			}
		}
	while (compteur!=0);

	//on prend les 100 premiers (les 100 meilleures notes)
	for (k=0;k<NB_CHROMOSOMES_APRES_SELECTION;k++)
		{
		for (l=0;l<NB_ARCS;l++)
			{
			matriceApresSelection[k][l]=matriceAvantSelection[k][l];
			//printf("%d",matriceApresSelection[k][l]);
			}
		}
	}
