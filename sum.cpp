#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "counters.h"

int main(int argc, char *argv[])
{
	hwCounter_t c1;
	c1.init = false;
	initTicks(c1);
	long long sum = 0;

	// Condition C
	//int n = 10000;

	// Condition !C
	int n = atoi(argv[1]);


	uint64_t current_time = getTicks(c1);
	// Compute
	for(long long i = 0; i < n ; i+=1)
	{
		sum += i;
	}
	//sum += 10;
	uint64_t elapsed = getTicks(c1) - current_time;
	printf("Time elapsed: %lu\n", elapsed);

	// Condition B
	// printf("%d\n", (int)sum); // should we move it after
}	


