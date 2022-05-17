#include <stdio.h>    // for printf()
#include <sys/wait.h> // for wait()
#include <unistd.h>   // for pipe(), dup2(), close(), fork(), and execvp()

void childCode(int pipefd[2]);
void parentCode(int pipefd[2]);

/*
 * This program demonstrates the system calls involved
 * when executing the following shell command with a pipe.
 *
 *    sort words.txt | uniq
 */
int main(int argc, char * argv[]){
  /*
   * After a successful call to pipe(pipefd),
   * pipefd[1] will hold the write end of the pipe
   * and pipefd[0] will hold the read end of the pipe.
   * pipefd[1] ---------------> pipefd[0].
   *
   * pipe returns 0 if it is successful or -1 if it fails
   */
  int pipefd[2]; // hold file descriptors for a pipe system call  
  int p = pipe(pipefd);  // pipe and store pipe file descriptors in pipefd

  if(p < 0) {
    printf("Pipe failed\n");
  }
  else{
    int pid = fork();
    if(pid < 0) printf("Fork failed\n");
    else if (pid == 0) childCode(pipefd);
    else parentCode(pipefd);
  }
  return 0;
}

void childCode(int pipefd[2]){
  // child does not need the read end of the pipe
  // so it should close it
  close(pipefd[0]);

  // replace child's standard output fd (1) with the pipe's write end
  dup2(pipefd[1], 1);
    
  char * args[] = {"sort", "words.txt", NULL};
  // execute sort words.txt
  execvp("sort", args);
}

void parentCode(int pipefd[2]){
  // parent does not need the write end of the pipe
  // so it should close it
  close(pipefd[1]);

  // replace parents's standard input fd (0) with the pipe's read end
  dup2(pipefd[0], 0);

  int status;
  // parent waits for child to complete
  wait(&status);
    
  char * args[] = {"uniq", NULL};
  // execute uniq
  execvp("uniq", args);
}

