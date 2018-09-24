#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
	int val;
	struct liste * suiv;
} cellule;

typedef struct {
	cellule* debut;
	cellule* fin;
} file;

file* creer_file_vide() {
	file* f = malloc(sizeof(file));
	f->debut = NULL;
	f->fin = NULL;

	return f;

}

void ajouter_element(file* f, int valeur) {
	if (f == NULL)
		return;
	
	cellule* c = malloc(sizeof(cellule));
	c->val = valeur;
	c->suiv = NULL;

	if (f->debut == NULL) {
		// La file est vide
		f->debut = c;
		f->fin = c;
	}
	else {
		// La file contient déjà au moins 1 élément
		f->fin->suiv = c;
		f->fin = c;
	}
}

void retirer_element(file* f) {
	if (f == NULL)
		return;

	// File vide
	if (f->debut == NULL)
		return;

	cellule* c = f->debut;

	// File à 1 seul élément
	if (c->suiv == NULL) {
		f->debut = NULL;
		f->fin = NULL;
	}
	// Plus de 2 éléments
	else {
		f->debut = f->debut->suiv;
	}

	free(c);
}

void afficher_premier_element(file f) {
	if (f.debut == NULL)
		return;

	printf("%d\n", f.debut->val);
}

void afficher_dernier_element(file f) {
	if (f.fin == NULL)
		return;

	printf("%d\n", f.fin->val);
}

int nb_elements(file f) {
	if (f.debut == NULL)
		return 0;

	int length = 0;

	cellule* cour = f.debut;

	while (cour != NULL) {
		length++;
		cour = cour->suiv;
	}
	return length;

}


void afficher(file f) {
	if (nb_elements(f) == 0)
		return;
	
	cellule* cour = f.debut;
	printf("(%d)", f.debut->val);

	cour = cour->suiv;

	while (cour != NULL){
		printf("-->(%d)", cour->val);
		cour = cour->suiv;
	}

	printf("\n");

}
int est_vide(file f) {
	return nb_elements(f) == 0;
}

int main(void) {
	file* f = creer_file_vide();

	printf(est_vide(*f) ? "la file est vide\n" : "la file n'est pas vide\n");

	ajouter_element(f, 42);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	ajouter_element(f, -2);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	ajouter_element(f, 0);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	afficher(*f);

	retirer_element(f);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	retirer_element(f);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	retirer_element(f);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	retirer_element(f);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	ajouter_element(f,10);
	afficher_premier_element(*f);
	afficher_dernier_element(*f);
	printf(" Nombre d'elements = %d\n", nb_elements(*f));

	printf(est_vide(*f) ? "la file est vide\n" : "la file n'est pas vide\n");

	afficher(*f);

	return 0;
}
