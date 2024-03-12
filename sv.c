#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("1");
    fflush(stdout); // Flush the output buffer to ensure immediate printing
}

void sigusr2_handler(int signum) {
    printf("0");
    fflush(stdout); // Flush the output buffer to ensure immediate printing
}

int main() {
    // Register signal handlers for SIGUSR1 and SIGUSR2
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("Error setting up SIGUSR1 handler");
        exit(EXIT_FAILURE);
    }
    if (signal(SIGUSR2, sigusr2_handler) == SIG_ERR) {
        perror("Error setting up SIGUSR2 handler");
        exit(EXIT_FAILURE);
    }

    printf("Server is running...%d\n", getpid());

    // Wait indefinitely
    while (1) {
        pause(); // Wait for signals indefinitely
    }

    return 0;
}