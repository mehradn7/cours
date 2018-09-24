#include <stdio.h>
#include <stdlib.h>

// 1. tableau[i][j] = tab_lineaire[(DIMENSION1-1)*i + j] (faux)



void saisie(int tab[][], int N, int M) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("tab[%d][%d] = ? \n", i, j, &tab[i][j]);
		}
	}

}


int main(void) {

	return 0;
}
