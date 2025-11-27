# NAME : VISWAJITH LALITHRAM R.V
# REG.NO : 212224240187


# Ex02-OS-Linux-Process API - fork(), wait(), exec()

# AIM:
To write C Program that uses Linux Process API - fork(), wait(), exec()

# DESIGN STEPS:

### Step 1:

Navigate to any Linux environment installed on the system or installed inside a virtual environment like virtual box/vmware or online linux JSLinux (https://bellard.org/jslinux/vm.html?url=alpine-x86.cfg&mem=192) or docker.

### Step 2:

Write the C Program using Linux Process API - fork(), wait(), exec()

### Step 3:

Test the C Program for the desired output. 

# PROGRAM:

### C Program to create new process using Linux API system calls fork() and getpid() , getppid() and to print process ID and parent Process ID using Linux API system calls

```c
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

```


### OUTPUT


![Alt text](FORKC.png)





## C Program to execute Linux system commands using Linux API system calls exec() , exit() , wait() family

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int status;

    printf("Running ps with execl\n");
    if (fork() == 0) {
        execl("/bin/ps", "ps", "-f", NULL);   // Correct full path
        perror("execl failed");
        exit(1);
    }

    wait(&status);
    if (WIFEXITED(status)) {
        printf("Child exited with status: %d\n", WEXITSTATUS(status));
    } else {
        printf("Child did not exit successfully\n");
    }

    printf("Running ps with execlp (without full path)\n");
    if (fork() == 0) {
        execlp("ps", "ps", "-f", NULL);       // execlp searches PATH—OK
        perror("execlp failed");
        exit(1);
    }

    wait(&status);
    if (WIFEXITED(status)) {
        printf("Child exited for execlp with status: %d\n", WEXITSTATUS(status));
    } else {
        printf("Child did not exit successfully\n");
    }

    printf("Done.\n");
    return 0;
}
```

### OUTPUT



![Alt text](FORKO.png)



# RESULT:
The programs are executed successfully.
