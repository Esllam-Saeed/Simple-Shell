#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
    char *buffer;
    size_t buffer_size = BUFFER_SIZE;
    ssize_t chars_read;
    pid_t pid;
    int status;

    while (1) {
        buffer = (char *)malloc(buffer_size * sizeof(char));
        if (buffer == NULL) {
            perror("malloc error");
            exit(EXIT_FAILURE);
        }

        printf("$ ");
        chars_read = getline(&buffer, &buffer_size, stdin);
        if (chars_read == -1) {
            printf("\n");
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execlp(buffer, buffer, (char *)NULL) == -1) {
                printf("%s: command not found\n", buffer);
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, &status, 0);
        }

        free(buffer);
    }

    return (0);
}

