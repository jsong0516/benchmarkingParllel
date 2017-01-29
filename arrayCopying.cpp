#include <sys/time.h>
#include <time.h>
#include <emmintrin.h>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
void my_memcpy(int* dst, int* src, int nbytes);
void simd_memcpy(void *dst, void *src, size_t nbytes);
void simd_memcpy_cache(void *dst, void *src, size_t nbytes);


int main(int argc, char *argv[])
{
  int trash = 0;
  int Ni = atoi(argv[1]);

  printf("MINE\n");
  int* copiedarray = new int[Ni];
  int* myarray = new int[Ni];
  for(int i = 0; i < Ni; i++)
    myarray[i] = i;

  double total = 0;
  double time_ellapsed;
  // Warming up
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
  my_memcpy(copiedarray, myarray, Ni);
    
  // Get time  
  struct timeval tv;
  struct timeval tv2;
  gettimeofday(&tv, 0);
  my_memcpy(copiedarray, myarray, Ni);
  gettimeofday(&tv2, 0);
  double time1 = tv.tv_sec + 1e-6 * tv.tv_usec; // Won't affect on the performance much
  double time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec; // Won't affect on the performance much
  time_ellapsed = time2 - time1;
  trash += copiedarray[Ni-1];// to make sure
  printf("%f\n", (sizeof(int) * Ni / time_ellapsed) / (1048576)); // 1 MB = 1048576 Bytes, sizeof(int) * N / time_ellapsed / 1048576
  // Multiplied by 8 because it is in bits

  printf("SIMD\n");

  // Warming up
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int)); 

  gettimeofday(&tv, 0);
  simd_memcpy(copiedarray, myarray, Ni * sizeof(int));
  gettimeofday(&tv2, 0);
  time1 = tv.tv_sec + 1e-6 * tv.tv_usec; // Won't affect on the performance much
  time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec; // Won't affect on the performance much
  time_ellapsed = time2 - time1;
  trash += copiedarray[Ni-1];// to make sure
    
    printf("%f\n", (sizeof(int) * Ni / time_ellapsed) / (1048576)); // 1 MB = 1048576 Bytes, sizeof(int) * N / time_ellapsed / 1048576
  

  printf("cache\n");
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  // Get time  
  gettimeofday(&tv, 0);
  simd_memcpy_cache(copiedarray, myarray, Ni * sizeof(int));
  gettimeofday(&tv2, 0);
  time1 = tv.tv_sec + 1e-6 * tv.tv_usec; // Won't affect on the performance much
  time2 = tv2.tv_sec + 1e-6 * tv2.tv_usec; // Won't affect on the performance much
  time_ellapsed = time2 - time1;
  trash += copiedarray[Ni-1];// to make sure
    
  printf("%f\n", (sizeof(int) * Ni / time_ellapsed) / (1048576)); // 1 MB = 1048576 Bytes, sizeof(int) * N / time_ellapsed / 1048576
  delete myarray;
  delete copiedarray;
  
  printf("%d", trash);

}

void my_memcpy(int* dst, int *src, int size)
{
  for(int i = 0; i < size; i++)
  {
    dst[i] = src[i];
  }
}

void simd_memcpy(void *dst, void *src, size_t nbytes)
{
  size_t i;

  size_t ilen = nbytes/sizeof(int);
  size_t ilen_sm = ilen - ilen%16;

  char *cdst=(char*)dst;
  char *csrc=(char*)src;

  int * idst=(int*)dst;
  int * isrc=(int*)src;

  __m128i l0,l1,l2,l3;

  _mm_prefetch((__m128i*)&isrc[0], _MM_HINT_NTA);
  _mm_prefetch((__m128i*)&isrc[4], _MM_HINT_NTA);
  _mm_prefetch((__m128i*)&isrc[8], _MM_HINT_NTA);
  _mm_prefetch((__m128i*)&isrc[12], _MM_HINT_NTA);
  
  for(i=0;i<ilen_sm;i+=16)
    {
      l0 =  _mm_load_si128((__m128i*)&isrc[i+0]);
      l1 =  _mm_load_si128((__m128i*)&isrc[i+4]);
      l2 =  _mm_load_si128((__m128i*)&isrc[i+8]);
      l3 =  _mm_load_si128((__m128i*)&isrc[i+12]);
    
      _mm_prefetch((__m128i*)&isrc[i+16], _MM_HINT_NTA);
      _mm_prefetch((__m128i*)&isrc[i+20], _MM_HINT_NTA);
      _mm_prefetch((__m128i*)&isrc[i+24], _MM_HINT_NTA);
      _mm_prefetch((__m128i*)&isrc[i+28], _MM_HINT_NTA);

      _mm_stream_si128((__m128i*)&idst[i+0],  l0);
      _mm_stream_si128((__m128i*)&idst[i+4],  l1);
      _mm_stream_si128((__m128i*)&idst[i+8],  l2);
      _mm_stream_si128((__m128i*)&idst[i+12], l3);

    }

  for(i=ilen_sm;i<ilen;i++)
    {
      idst[i] = isrc[i];
    }

  for(i=(4*ilen);i<nbytes;i++)
    {
      cdst[i] = csrc[i];
    }
}

void simd_memcpy_cache(void *dst, void *src, size_t nbytes)
{
  size_t i;
  size_t sm = nbytes - nbytes%sizeof(int);
  size_t ilen = nbytes/sizeof(int);
  size_t ilen_sm = ilen - ilen%16;

  //printf("nbytes=%zu,ilen=%zu,ilen_sm=%zu\n",
  //nbytes,ilen,ilen_sm);


  char *cdst=(char*)dst;
  char *csrc=(char*)src;

  int * idst=(int*)dst;
  int * isrc=(int*)src;

  __m128i l0,l1,l2,l3;

  _mm_prefetch((__m128i*)&isrc[0], _MM_HINT_T0);
  _mm_prefetch((__m128i*)&isrc[4], _MM_HINT_T0);
  _mm_prefetch((__m128i*)&isrc[8], _MM_HINT_T0);
  _mm_prefetch((__m128i*)&isrc[12], _MM_HINT_T0);
  
  for(i=0;i<ilen_sm;i+=16)
    {
      l0 =  _mm_load_si128((__m128i*)&isrc[i+0]);
      l1 =  _mm_load_si128((__m128i*)&isrc[i+4]);
      l2 =  _mm_load_si128((__m128i*)&isrc[i+8]);
      l3 =  _mm_load_si128((__m128i*)&isrc[i+12]);
    
      _mm_prefetch((__m128i*)&isrc[i+16], _MM_HINT_T0);
      _mm_prefetch((__m128i*)&isrc[i+20], _MM_HINT_T0);
      _mm_prefetch((__m128i*)&isrc[i+24], _MM_HINT_T0);
      _mm_prefetch((__m128i*)&isrc[i+28], _MM_HINT_T0);

      _mm_store_si128((__m128i*)&idst[i+0],  l0);
      _mm_store_si128((__m128i*)&idst[i+4],  l1);
      _mm_store_si128((__m128i*)&idst[i+8],  l2);
      _mm_store_si128((__m128i*)&idst[i+12], l3);

    }

  for(i=ilen_sm;i<ilen;i++)
    {
      idst[i] = isrc[i];
    }

  for(i=(ilen*4);i<nbytes;i++)
    {
      cdst[i] = csrc[i];
    }
}