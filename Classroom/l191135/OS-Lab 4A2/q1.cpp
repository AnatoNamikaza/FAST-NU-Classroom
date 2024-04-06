#include <iostream>
#include <pthread.h>
#include <semaphore.h>
/* 
logic: 
thread1 is opend at start and other two closed
thread1 opens thread2 without posting its lock
thread2 opens thread3 without posting its lock
thread3 opens thread1 without posting its lock
it runs in cycle
*/
using namespace std;

sem_t th1_lock;
sem_t th2_lock;
sem_t th3_lock;

//Th1
void* th1(void *){
  while(1){
    sem_wait(&th1_lock);
    cout << "aaa";
    sem_post(&th2_lock);
  }
}

//Th2
void* th3(void *){
  while(1){
    sem_wait(&th2_lock);
    cout << "b";
    sem_post(&th3_lock);
  }
}

//Th3
void* th2(void *){
  while(1){
    sem_wait(&th3_lock);
    cout << "c";
    sem_post(&th1_lock);
  }
}


int main(){

  sem_init(&th1_lock,0,1); // allow thread1 at start
  sem_init(&th2_lock,0,0); // don't allow thread2 one at start
  sem_init(&th3_lock,0,0); // don't allow thread3 one at start

  pthread_t t1,t2,t3;
  pthread_create(&t1,NULL,&th1,NULL);
  pthread_create(&t2,NULL,&th2,NULL);
  pthread_create(&t3,NULL,&th3,NULL);


  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  pthread_join(t3,NULL);
}
