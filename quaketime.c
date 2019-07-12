#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


#define RED(x) "\033[1;31m" x "\033[0;m"
#define BLUE(x) "\033[1;96m" x "\033[0;m"

void asktime()
{
	struct timeval start, stop;

	for (;;) {
		int n = rand() % 60;
		int mans = (n + 35) % 60;
		int rans = (n + 25) % 60;
		int in;

		int item = rand() % 2;

		if (item == 0)
			printf("\n##### " BLUE("MEGA") ": %d\n", n);
		else
			printf("\n##### " RED("RED") ": %d\n", n);

		gettimeofday(&start, NULL);
		scanf("%d", &in);
		gettimeofday(&stop, NULL);
		
		double dif = (double)(stop.tv_sec - start.tv_sec);
		dif += (double)(stop.tv_usec - start.tv_usec) / 1000000.0f;

		if (item == 0) {
			if (in == mans) {
				printf("well done");
			} else {
				printf("wrong: %d", mans);
			}
		} else {
			if (in == rans) {
				printf("well done");
			} else {
				printf("wrong: %d", rans);
			}
		}

		printf(" (time: %.02fs)\n", dif);
		dif = 0;
	}
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	asktime();
}
