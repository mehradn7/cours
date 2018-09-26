#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 60
#define FILENAME_SIZE 30

// Ex 2

int EcritFichier(FILE* fich_lect, char* nom_fich_ecrit, int nb_lignes) {
	// Create new file
	FILE* f = fopen(nom_fich_ecrit, "w");

	if (f == NULL)
		return -1;

	//Read nb_lignes lines from fich_lect and write them to f
	int nb_lignes_lues = 0;
	char buf[BUF_SIZE];

	while (nb_lignes_lues < nb_lignes && (fgets(buf, BUF_SIZE, fich_lect) != NULL)) {
		if (fputs(buf, f) < 0)
			return -2;
		nb_lignes_lues++;
	}

	return nb_lignes_lues;
}

int CoupeFichier(char* nom_fich_lect, char* nom_fich_ecrit_base, int nb_lignes) {
	// Open file for reading
	FILE* fich_lect = fopen(nom_fich_lect, "r");

	if (fich_lect == NULL)
		return -1;

	int indice_fich_ecrit = 1;
	int nb_lignes_lues = 0;
	char nom_fich_ecrit[FILENAME_SIZE];

	// Read nb_lignes lines from fich_lect and write them to separate files
	do {
		if (sprintf(nom_fich_ecrit, "%s.%d", nom_fich_ecrit_base, indice_fich_ecrit) < 0)
			return -2;

		nb_lignes_lues = EcritFichier(fich_lect, nom_fich_ecrit, nb_lignes);

		if (nb_lignes_lues < 0)
			return -3;
		

		indice_fich_ecrit++;
	} while (nb_lignes_lues == nb_lignes);

	return indice_fich_ecrit-1;

}

int Saisie(char* nom_fich_lect, char* nom_fich_ecrit_base, int* nb_lignes) {
	printf("Nom du fichier a lire : ");
	if (scanf("%s", nom_fich_lect) < 0)
		return -1;
	
	printf("Nom de base du fichier a ecrire : ");
	if (scanf("%s", nom_fich_ecrit_base) < 0)
		return -2;
	
	printf("Nombre de lignes a ecrire dans chaque fichier : ");
	if (scanf("%d", nb_lignes) < 0)
		return -3;
	return 0;

}


int main(void) {
	//FILE* testfile = fopen("testfile", "r");

	//printf("%d\n", EcritFichier(testfile, "sortie", 2));
	
	char nom_fich_lect[FILENAME_SIZE], nom_fich_ecrit_base[FILENAME_SIZE];
	int* nb_lignes = malloc(sizeof(int));

	Saisie(nom_fich_lect, nom_fich_ecrit_base, nb_lignes);
	
	printf("%d\n", CoupeFichier(nom_fich_lect, nom_fich_ecrit_base, *nb_lignes));



}
