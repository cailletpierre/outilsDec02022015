/*
 * generation.c
 *
 *  Created on: 9 févr. 2015
 *      Author: utilisateur
 */

#include "chromosome.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generation(int matriceAvantSelection[NB_CHROMOSOMES_AVANT_SELECTION][NB_ARCS],int matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION][NB_ARCS],int enfant1[],int enfant2[])
	{


	int nbEnfantAFaire=9*NB_CHROMOSOMES_APRES_SELECTION/10;
	if (nbEnfantAFaire % 2 != 0)
		{
		nbEnfantAFaire=nbEnfantAFaire-1;
		}
	int nbMutationAFaire=NB_CHROMOSOMES_APRES_SELECTION-nbEnfantAFaire;
	//printf("%d",nbEnfantAFaire);
	//printf("%d",nbMutationAFaire);


	//selection des chromosomes pour mutation
	int ind4;
	int indiceARemplir=NB_CHROMOSOMES_APRES_SELECTION;
	int nbChromosomeOuChoisir;
	nbChromosomeOuChoisir=NB_CHROMOSOMES_APRES_SELECTION;
	for (ind4=0; ind4<nbMutationAFaire;ind4++)
		{
			time_t temps;
			srand ((unsigned int)time(&temps));
			int ind5;
			ind5=rand() % (nbChromosomeOuChoisir);
			int chromosomeAMuter[NB_ARCS];
			int ind6;

			//on copie le chromosome a muter en tampon
			for (ind6=0;ind6<NB_ARCS;ind6++)
				{
				chromosomeAMuter[ind6]=matriceApresSelection[ind5][ind6];
				}

			//on remonte les chromosomes de ind5+1 à NB_CHROMOSOMES_APRES_SELECTION de un rang dans le tableau
			int ind7;
			for (ind7=ind5;ind7<NB_CHROMOSOMES_APRES_SELECTION;ind7++)
				{
				for (ind6=0;ind6<NB_ARCS;ind6++)
					{
					matriceApresSelection[ind7][ind6]=matriceApresSelection[ind7+1][ind6];

					}
				}


			//on copie le chromosome à muter au rang NB_CHROMOSOMES_APRES_SELECTION (en bas de la matriceApresSelection, pour ne plus le resélectionner)
			for (ind6=0;ind6<NB_ARCS;ind6++)
				{
				matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION-1][ind6]=chromosomeAMuter[ind6];
				}

			// on fait la mutation
			mutation(chromosomeAMuter);

			// on place le chromosome muté dans la matriceAvantSelection, au rang NB_CHROMOSOMES_APRES_SELECTION+ind4
			// on remet les anciens chromosomes dans la matrice
			for (ind6=0;ind6<NB_ARCS;ind6++)
				{
				matriceAvantSelection[NB_CHROMOSOMES_APRES_SELECTION+ind4][ind6]=chromosomeAMuter[ind6];
				int ind8;
				for (ind8=0;ind8<NB_CHROMOSOMES_APRES_SELECTION;ind8++)
					{
					matriceAvantSelection[ind8][ind6]=matriceApresSelection[ind8][ind6];
					}
				}
			nbChromosomeOuChoisir--;
			indiceARemplir++;
		}

//------------------------------------------------------------------------
	//selection des chromosomes pour faireEnfant



	for (ind4=0; ind4<nbEnfantAFaire/2;ind4++)
		{
		//on selectionne le pere
		int indPere,ind6;
		indPere=rand() % (nbChromosomeOuChoisir);
		nbChromosomeOuChoisir--;
		//on le place dans le tableau pere
		int pere[NB_ARCS];
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			pere[ind6]=matriceApresSelection[indPere][ind6];
			}
		//on remonte les chromosomes, on place le pere a la fin
		int ind7;
		for (ind7=indPere;ind7<NB_CHROMOSOMES_APRES_SELECTION;ind7++)
			{
			for (ind6=0;ind6<NB_ARCS;ind6++)
				{
				matriceApresSelection[ind7][ind6]=matriceApresSelection[ind7+1][ind6];
				}
			}
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION-1][ind6]=pere[ind6];
			}

		//on selectionne la mere
		int indMere;
		indMere=rand() % (nbChromosomeOuChoisir);
		nbChromosomeOuChoisir--;

		//on la place dans le tableau mere
		int mere[NB_ARCS];
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			mere[ind6]=matriceApresSelection[indMere][ind6];
			}
		//on remonte les chromosomes, on place la mere a la fin
		for (ind7=indMere;ind7<NB_CHROMOSOMES_APRES_SELECTION;ind7++)
			{
			for (ind6=0;ind6<NB_ARCS;ind6++)
				{
				matriceApresSelection[ind7][ind6]=matriceApresSelection[ind7+1][ind6];
				}
			}
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION-1][ind6]=mere[ind6];
			}
		//on fait les enfants
		faireEnfant(pere,mere,enfant1,enfant2);

		//on place les enfants dans matriceAvantSelection
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			matriceAvantSelection[indiceARemplir][ind6]=enfant1[ind6];
			}
		indiceARemplir++;
		for (ind6=0;ind6<NB_ARCS;ind6++)
			{
			matriceAvantSelection[indiceARemplir][ind6]=enfant2[ind6];
			}
		indiceARemplir++;
		}



	}
