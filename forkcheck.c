//C Program to create new process using Linux API system calls fork() and exit()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }

    if (pid == 0) {  
        // Child process
        printf("I am child, my PID is %d\n", getpid());
        printf("My parent PID is %d\n", getppid());
        exit(0);
    } 
    else {          
        // Parent process
        printf("I am parent, my PID is %d\n", getpid());
        sleep(1);  
        exit(0);
    }
}
