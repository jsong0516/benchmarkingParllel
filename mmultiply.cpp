#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sys/time.h>
#include <time.h>
#include "counters.cpp"

void opt_simd_sgemm(float *Y, float *A, float *B, int n);
void opt_scalar1_sgemm(float *Y, float *A, float *B, int n);
void opt_scalar0_sgemm(float *Y, float *A, float *B, int n);
void naive_sgemm(float *Y, float *A, float *B, int n);

int main(int argc, char *argv[])
{
	int n = (1<<10); // 1 << 10 = 2 ^ 10
	float* A = new float[n*n];
	float* B = new float[n*n];
	float* Y = new float[n*n];

	// For cycle
	hwCounter_t c;
	c.init = false;
	initTicks(c);
	hwCounter_t c1;
	c1.init = false;
	initInsns(c1);
	{ 
	// To make life is easier
	// Initializing
	struct timeval tv;
	struct timeval tv2;

	gettimeofday(&tv, 0);
	naive_sgemm(Y, A, B, n);
	gettimeofday(&tv2, 0);
	double time1 = tv.tv_sec + 1e-6 * tv.tv_usec;
	double time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec;
	double diff_time_sec = time2 - time1;

	// insturctions
	uint64_t count = getInsns(c1);
	naive_sgemm(Y, A, B, n);
	uint64_t executed = getInsns(c1) - count;

	// cycle
	uint64_t current_time = getTicks(c);
	naive_sgemm(Y, A, B, n);
	uint64_t elapsed = getTicks(c) - current_time;

	printf("Naive instructions %lu \n", executed);
	printf("cycles              %lu\n", elapsed );
	printf("Naive Time in sec  : %lf\n", diff_time_sec);
	float trash = Y[n*n - 1] + A[n*n - 1] + B[n*n - 1];
	}

	{ // To make life is easier
	// Initializing
	struct timeval tv;
	struct timeval tv2;


	// time elapsed
	gettimeofday(&tv, 0);
	opt_simd_sgemm(Y, A, B, n);
	gettimeofday(&tv2, 0);
	double time1 = tv.tv_sec + 1e-6 * tv.tv_usec;
	double time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec;
	double diff_time_sec = time2 - time1;

	// insturctions
	uint64_t count = getInsns(c1);
	opt_simd_sgemm(Y, A, B, n);
	uint64_t executed = getInsns(c1) - count;

	// cycle
	uint64_t current_time = getTicks(c);
	opt_simd_sgemm(Y, A, B, n);
	uint64_t elapsed = getTicks(c) - current_time;

	printf("opt_simd_sgemm instructions %lu \n", executed);
	printf("cycles              %lu\n", elapsed );
	printf("opt_simd_sgemm Time in sec  : %lf\n", diff_time_sec);
	float trash = Y[n*n - 1] + A[n*n - 1] + B[n*n - 1];
	}
	{ // To make life is easier
	// Initializing
	struct timeval tv;
	struct timeval tv2;

	// time elapsed
	gettimeofday(&tv, 0);
	opt_scalar1_sgemm(Y, A, B, n);
	gettimeofday(&tv2, 0);
	double time1 = tv.tv_sec + 1e-6 * tv.tv_usec;
	double time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec;
	double diff_time_sec = time2 - time1;

	// insturctions
	uint64_t count = getInsns(c1);
	opt_scalar1_sgemm(Y, A, B, n);
	uint64_t executed = getInsns(c1) - count;

	// cycle
	uint64_t current_time = getTicks(c);
	opt_scalar1_sgemm(Y, A, B, n);
	uint64_t elapsed = getTicks(c) - current_time;
	double IPC = (double)executed / (double)elapsed;
	printf("opt_scalar1_sgemm instructions %lu \n", executed);
	printf("cycles              %lu\n", elapsed );
	printf("opt_scalar1_sgemm Time in sec  : %lf\n", diff_time_sec);
	float trash = Y[n*n - 1] + A[n*n - 1] + B[n*n - 1];
	}
	{ // To make life is easier
	// Initializing
	struct timeval tv;
	struct timeval tv2;


	// time elapsed
	gettimeofday(&tv, 0);
	opt_scalar0_sgemm(Y, A, B, n);
	gettimeofday(&tv2, 0);
	double time1 = tv.tv_sec + 1e-6 * tv.tv_usec;
	double time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec;
	double diff_time_sec = time2 - time1;

	// insturctions
	uint64_t count = getInsns(c1);
	opt_scalar0_sgemm(Y, A, B, n);
	uint64_t executed = getInsns(c1) - count;

	uint64_t current_time = getTicks(c);
	opt_scalar0_sgemm(Y, A, B, n);
	uint64_t elapsed = getTicks(c) - current_time;

	// cycle



	printf("opt_scalar0_sgemm instructions %lu \n", executed);
	printf("cycles              %lu\n", elapsed );
	printf("opt_scalar0_sgemm Time in sec  : %lf\n", diff_time_sec);
	float trash = Y[n*n - 1] + A[n*n - 1] + B[n*n - 1];
	}
	delete [] A;
	delete [] B;
	delete [] Y;


}