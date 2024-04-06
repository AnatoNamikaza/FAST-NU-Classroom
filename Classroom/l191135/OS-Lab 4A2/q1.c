#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
  char buffer[50] = "this is SOME ranDOM text\n";  
  int pid;
  int fd[2];
  int fd2[2];
  if(pipe(fd) == -1 || pipe(fd2) == -1){
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
    read(fd[0],buffer,50);
    close(fd[0]);
    for(int i=0; i< 50 && buffer[i] != '\0'; i++){
      if(buffer[i]-'Z' > 0){
	/* small letter */
	buffer[i] = buffer[i]-32;
      }
      else if(buffer[i] != ' '){
	buffer[i] = buffer[i]+32;
      }
    }
    close(fd2[0]);
    write(fd2[1],buffer,50);
    close(fd2[0]);
  }
  else{    
    /*parent process writes message to pipe*/
    printf("original message below ...\n");
    printf("%s\n",buffer);
    close(fd[0]); /* close read end of pipe */    
    write(fd[1],buffer,50);
    close(fd[1]);
    wait(NULL); /* wait for the child to complete its job */
    /* now print that modified message to the screen */
    close(fd2[1]);
    read(fd2[0], buffer,50);
    close(fd2[0]);
    printf("modified message below ...\n");
    printf("%s\nee",buffer);   
  }
  return 0;
}
