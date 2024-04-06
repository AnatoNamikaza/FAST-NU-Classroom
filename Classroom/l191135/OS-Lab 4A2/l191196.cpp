#include<iostream>
#include<semaphore.h>
using namespace std;

sem_t mutex;
sem_t readLock;

int array[100];
int array_index=0;

void comulativeSum();
void feedRandomNumber();
void* writeRoutine(void*);
void* readRoutine(void*);

void comulativeSum(){
  sem_wait(&readLock);
  sem_wait(&mutex);
  int sum=0;
  for(int i=0;i<array_index;i++)
    sum+=array[i];
  cout<<"comulative sum so far: ";
  cout << sum << endl;
  sem_post(&mutex);    
}

void feedRandomNumber(){
  sem_wait(&mutex);
  int rnumber=rand()%6;
  cout<<"random number: ";
  cout << rnumber << endl;
  array[array_index]=rnumber;
  array_index++;
  sem_post(&mutex);
  sem_post(&readLock);
}

void* readRoutine(void*){
  comulativeSum();    
  return NULL;
}

void* writeRoutine(void*){
  feedRandomNumber(); 
  return NULL;
}

int n=100; // no of threads
int main(){
  sem_init(&mutex,0,1);
  sem_init(&readLock,0,0);
  pthread_t t[2*n]; //100 for reading and 100 for
 
  for(int i=0; i < n; i++){
    pthread_create(&t[i],NULL,&readRoutine,NULL);
  }
   
  for(int i=100; i< 2*n; i++){
    pthread_create(&t[i],NULL,&writeRoutine,NULL);
  }

  for(int i=0;i< 2*n;i++)
    pthread_join(t[i],NULL);

  return 0;
}
