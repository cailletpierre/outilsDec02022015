/*
 * chromosome.h
 *
 *  Created on: 5 févr. 2015
 *      Author: utilisateur
 */

#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_
#define NB_ARCS 4
#define NB_MESURES 8
#define NB_CHROMOSOMES_AVANT_SELECTION 20
#define NB_CHROMOSOMES_APRES_SELECTION 10





void faireEnfant(int pere[],int mere[],int enfant1[],int enfant2[]);
void afficherChromosome(int chromosome[]);
void mutation(int chromosome[]);
void selection(int matriceAvantSelection[NB_CHROMOSOMES_AVANT_SELECTION][NB_ARCS],int matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION][NB_ARCS]);
int noterUnChromosome(int chromosome[]);
void generation(int matriceAvantSelection[NB_CHROMOSOMES_AVANT_SELECTION][NB_ARCS],int matriceApresSelection[NB_CHROMOSOMES_APRES_SELECTION][NB_ARCS],int enfant1[],int enfant2[]);


#endif /* CHROMOSOME_H_ */
