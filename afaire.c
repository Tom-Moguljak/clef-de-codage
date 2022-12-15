#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CODAGE 1
#define DECODAGE 0

/*Fonction permettant l'encodage et le décodage*/
int code(char* nom_fichier_entree,char* nom_fichier_cle, char* nom_fichier_sortie, int option) {
	FILE* fichier_entree;
	FILE* fichier_cle;
	FILE* fichier_sortie;
	int c;
	int k1;
	int calcul;	

	fichier_entree = fopen(nom_fichier_entree, "r");
	if(fichier_entree == NULL) {
		return -1;	
	}
	
	fichier_cle = fopen(nom_fichier_cle, "r");
	if(fichier_cle == NULL) {
		fclose(fichier_entree);
		return -1;
	}

	fichier_sortie = fopen(nom_fichier_sortie, "w");
	if(fichier_sortie == NULL) {
		fclose(fichier_entree);
		fclose(fichier_cle);
		return -1;
	}

	while ((c = fgetc(fichier_entree)) != EOF) {
		k1 = fgetc(fichier_cle);
		if (option == CODAGE)
			calcul = (c+k1) % 256;
		else
			calcul = c-k1 >= 0?c-k1:256-(c-k1);
		fputc(calcul, fichier_sortie);
	}

	fclose(fichier_entree);
	fclose(fichier_cle);
	fclose(fichier_sortie);

	return 0;
}

/*Fonction permettant la génération de la clé*/
int genkey(char* nom_fichier_entree, char* nom_fichier_cle) {
	FILE* fichier_entree;
	FILE* fichier_cle;
	char* txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	size_t l = strlen(txt);
	int c, n;
	srand(time(NULL));
	
	fichier_entree = fopen(nom_fichier_entree, "r");
	if(fichier_entree == NULL) {
		return -1;	
	}
	
	fichier_cle = fopen(nom_fichier_cle, "w");
	if(fichier_cle == NULL) {
		fclose(fichier_entree);
		return -1;
	}

	while ((c = fgetc(fichier_entree)) != EOF) {
		n = rand() % l;
		fputc(txt [n], fichier_cle);
	}

	fclose(fichier_entree);
	fclose(fichier_cle);

	return 0;
}

int main(int argc, char *argv[]) {
	
	if(argc <= 1) {
		fprintf( stderr, "Usage: %s [] \n", argv[0]);
		return EXIT_FAILURE;
	}
	
	if(strcmp(argv[1], "-c") == 0) {
		/* Encodage */
		if(argc != 5) {
			fprintf(stderr, "Usage: %s -c [FICHIER_ENTREE] [FICHIER_CLE] [FICHIER_SORTIE]\n", argv[0]);
			return EXIT_FAILURE;
		}

		if(code(argv[2], argv[3], argv[4], CODAGE) == -1)
		{
			fprintf(stderr, "Ouverture de fichier impossible\n");
			return EXIT_FAILURE;
		}

	} else if(strcmp(argv[1], "-d") == 0) {
		/* Décodage */
		if(argc != 5) {
			fprintf(stderr, "Usage: %s -d [FICHIER_ENTREE] [FICHIER_CLE] [FICHIER_SORTIE]\n", argv[0]);
			return EXIT_FAILURE;
		}

		if(code(argv[2], argv[3], argv[4], DECODAGE) == -1)
		{
			fprintf(stderr, "Ouverture de fichier impossible\n");
			return EXIT_FAILURE;
		}

	} else if(strcmp(argv[1], "-k") == 0) {
		/* Génération de clé */
		if(argc != 4) {
			fprintf(stderr, "Usage: %s -k [FICHIER_ENTREE] [FICHIER_CLE]\n", argv[0]);
			return EXIT_FAILURE;
		}

		if(genkey(argv[2], argv[3]) == -1) {
			fprintf(stderr, "Ouverture de fichier impossible\n");
			return EXIT_FAILURE;	
		}

	} else {
		fprintf(stderr, "\"%s\" pas reconnu.\n", argv[1]);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}