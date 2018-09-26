#include <stdio.h>
#include <stdlib.h>

// 1. tableau[i][j] = tab_lineaire[(DIMENSION2)*i + j]



void saisie(int N, int M, int tab[][M]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			printf("tab[%d][%d] = ", i, j);
			scanf("%d", &tab[i][j]);
		}
	}

}

void saisiep(int N, int M, int* tab) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			printf("tab[%d][%d] = ", i, j);
			scanf("%d", (tab+(M*i + j)));
		}
	}
	
}

void affiche(int N, int M, int tab[][M]) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			printf("tab[%d][%d] = %d \n", i, j, tab[i][j]);
		}
	}


}

//--------------------------

void saisie2(int n, int m, int** mat) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("mat[%d][%d] = ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}

}

void saisie2p(int n, int m, int** mat) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("mat[%d][%d] = ", i, j);
			scanf("%d", ((*(mat+i))+j));
		}
	}
	
}

void affiche2(int n, int m, int** mat) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("mat[%d][%d] = %d \n", i, j, mat[i][j]);
		}
	}


}

void init(int*** M) {
	int nlig;
	int ncol;

	printf("nb de lignes : ");
	scanf("%d", &nlig);

	printf("nb de colonnes : ");
	scanf("%d", &ncol);

	*M = malloc(nlig*sizeof(int*));

	for (int i=0; i<nlig; i++) {
		*((*M)+i) = malloc(ncol*sizeof(int));
	}

}



int main(void) {
	/*int tab[2][3];

	saisiep(2,3,(int*)tab);

	printf("\n");

	affiche(2,3,tab);*/

	//-------------------
	
	int nlig=2;
	int ncol=3;

	int** M;

	/*int** M = malloc(nlig*sizeof(int*));

	for (int i=0; i<nlig; i++) {
		*(M+i) = malloc(ncol*sizeof(int));
	}*/
	init(&M);

	//saisie2(nlig, ncol, M);
	
	saisie2p(nlig, ncol, M);

	printf("\n");
	
	affiche2(nlig, ncol, M);


	return 0;
}
