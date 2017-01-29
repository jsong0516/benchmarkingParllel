#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <time.h>
#include "counters.h"

int main(int argc, char *argv[])
{
	// Size N
	int N = atoi(argv[1]);
	int* randomArray = new int[N];

	//Seed the random number generator with the current time
	srand(time(NULL));

	// Initialize the array
	for(int i = 0; i < N; i++)
	{
		randomArray[i] = i;
	}

	//Generate a random integer between 0 and N
	if(N > 1)
	{
		for(int i = 0; i < N; i++)
		{
			int index = rand() % N; // Get random index

			// Swap
			int value = randomArray[index];
			randomArray[index] = randomArray[i];
			randomArray[i] = value;
		}
	}

	// Pointer chasing
	int steps = 1048576; // number of steps, 2 ^ 20 same as 1 << 20
	long total = 0.0;
	int i = 0;

	/* Timing elements*/
	hwCounter_t c1;
	c1.init = false;
	initTicks(c1);
	// Vary the size of the array from 32 kilobytes to 8 megabytes.
	// Assuming the size of int = 4 bytes, then the size of the array varies from 8*1024 = 8192 size, 8388608 bytes in 8 megabytes = 2097152
	uint64_t current_time = getTicks(c1);
	for(int n = 0; n < steps; n++)
	{
		i = randomArray[i];
	}
	total =(getTicks(c1) - current_time);
	printf("Average cycle per steps: %lu\n", total);
	printf("TO MAKE SURE %d\n", i);
	
	delete randomArray;

}
