#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

long sharedVal = 100;

/* thread function */
void *thr_func(void *arg)
{
  int data = (int)arg;
  printf("Thread ID: %d\n", data);
  sharedVal += data;
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  printf("Shared variable: %ld\n", sharedVal);
  pthread_t thr[NUM_THREADS];
  int i, rc;

  /* create threads */
  for (i = 0; i < NUM_THREADS; ++i)
  {
    if ((rc = pthread_create(&thr[i], NULL, thr_func, (void *)i)))
    {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }
  /* block until all threads complete */
  for (i = 0; i < NUM_THREADS; ++i)
  {
    pthread_join(thr[i], NULL);
  }
  printf("Shared variable: %ld\n", sharedVal);
  return EXIT_SUCCESS;
}
