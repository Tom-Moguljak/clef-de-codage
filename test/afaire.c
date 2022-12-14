#include <stdio.h>
#include <stdlib.h>
#include "cle.h"
#include "code.h"
#include "decode.h"
#define CODAGE


int main(int argc, char *argv[]) {
	FILE *f_m, *f_k, *f_mc; /* strcutures permettant, une fois FOPEN 
	exécuté de recupérer des informations pour manipuler les fichiers
	en C */
	
	int c;
	int k1;
	int calcul;
	int option;
	
	/* recupération sur la ligne de commande des noms de fichiers et option (-c pour codage
		-d pour décodage : message cle message_calculé 
	
	
	
	code -c f1 f2 f3
	code -d f1 f2 f3
	
	*/
	
	datafile = ouvre_fichier(argv[1], argv[2], argv[3]);
	ouvre_fichier (argv[1], argv[2], argv[3], &f1, &f2, &f3);
		
		
	fermefichier(datafile);
	return EXIT_SUCCESS;
}