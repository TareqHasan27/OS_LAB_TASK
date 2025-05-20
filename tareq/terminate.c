#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child: I am alive with PID = %d\n", getpid());
        while (1) {
            // Keep the child running
            printf("hlw\n");
            sleep(1);
        }
    } else {
        // Parent process
        sleep(3);  // Let the child run for a bit
        printf("Parent: Terminating child process with PID = %d\n", pid);
        kill(pid, SIGKILL);  // Send SIGKILL to child
        printf("Parent: Child terminated\n");
    }

    return 0;
}
