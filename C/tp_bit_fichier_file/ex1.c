#include <stdio.h>
#include <stdlib.h>


// Ex 1

int mult_par2(int i){
	return i << 1;
}

unsigned int question2(unsigned int a, unsigned int b) {
	unsigned int c1 = a>>16;
	unsigned int c2 = ~(b<<16);
	c2 = c2&65280;

	return c1|c2;
}

int bit10different(unsigned int a, unsigned int b) {
	return (a^b) == (1<<9);

}

int bitcount(int n) {
	int count = 0;
	while(n != 0) {
		if ((n&1) == 1)
			count++;
		n = n>>1;
	}
	return count;

}

int main(void) {
	int k = 47;
	printf("%d fois 2 = %d\n", k, mult_par2(k));

	unsigned int a = 0;
	unsigned int b = 65280;
	printf("question2(%u,%u) = %u\n", a, b, question2(a,b));

	a = 0xffffffff;
	b = 0xfffffdff;
	printf("bit10different(%u,%u) = %u\n", a, b, bit10different(a,b));

	int c = 47;
	int d = 65535;
	printf("bitcount(%u) = %u\n", c, bitcount(c));
	printf("bitcount(%u) = %u\n", d, bitcount(d));



	return 0;
}
