#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define ARG_SIZE 64

int main(void)
{
    char *buffer;
    char *args[ARG_SIZE];
    size_t buffer_size = BUFFER_SIZE;
    ssize_t chars_read;
    pid_t pid;
    int status;
    int argc;

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

        argc = 0;
        args[argc] = strtok(buffer, " ");
        while (args[argc] != NULL && argc < ARG_SIZE - 1) {
            argc++;
            args[argc] = strtok(NULL, " ");
        }
        args[argc] = NULL;

        pid = fork();
        if (pid < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("%s: command not found\n", args[0]);
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(pid, &status, 0);
        }

        free(buffer);
    }

    return (0);
}

