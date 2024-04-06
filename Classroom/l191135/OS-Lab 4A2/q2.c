#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int pid;
  int fd[2];
  int max_lenght =100;
  char buffer[max_lenght];
  
  if(pipe(fd) == -1){
    perror("pipe error\n");
    exit(EXIT_FAILURE);
  }
  pid=fork();
  if(pid == -1){
    perror("fork error\n");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0){
    /* child process reads, processes and write back  */
    wait(NULL); /* let the parent write a message */
    close(fd[1]);
    read(fd[0],buffer,100);
    close(fd[0]);
    FILE *fp1;
    fp1 = fopen(argv[2],"w+");    
    for(int i=0; i< 100; i++){
      fputc(buffer[i],fp1);
    }
    fclose(fp1);
    close(fd[0]);
  }
  else{
    int index=0;
    /*parent process writes message to pipe*/
    close(fd[0]); /* close read end of pipe */
    FILE *fp;
    fp = fopen(argv[1],"r");
    char c;
    while(!feof(fp)){
      c = fgetc(fp);
      buffer[index++] = c;
    }
    buffer[index]='\0';
    write(fd[1],buffer,index);
    close(fd[1]);
    fclose(fp);
    wait(NULL);
  }
  return 0;
}
