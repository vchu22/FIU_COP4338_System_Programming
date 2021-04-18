#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

long sharedVal = 100;
pthread_mutex_t lock;

void *thr_func(void *arg)
{
  int id = (int)arg;
  printf("Thread ID: %d\n", id);
  pthread_mutex_lock(&lock);
  sharedVal += id;
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
  printf("Shared variable: %ld\n", sharedVal);
  pthread_t thr[NUM_THREADS];
  int i, rc;

  pthread_mutex_init(&lock, NULL);
  for (i = 0; i < NUM_THREADS; ++i)
  {
    if ((rc = pthread_create(&thr[i], NULL, thr_func, (void *)i)))
    {
      fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      return EXIT_FAILURE;
    }
  }

  for (i = 0; i < NUM_THREADS; ++i)
  {
    pthread_join(thr[i], NULL);
  }
  printf("Shared variable: %ld\n", sharedVal);
  return EXIT_SUCCESS;
}
