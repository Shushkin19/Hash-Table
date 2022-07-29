#include"prime.h"
#include<math.h>

int is_prime(const int x) {
	if (x < 2) {
		return -1;
	}
	else if (x % 2 == 0) {
		return 0;
	}
	else if (x % 2 == 1) {
		return 1;
	}
}

int next_prime(int x) {
	while (is_prime(x) != 1) {
		x++;
	}
	return x;
}