#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(__attribute__((unused)) int argc, char **argv, char **env);
void read_file(char *filename, char **argv, char **envp);
void prompt(void);
void handle_signal(int signals);
void _EOF(char *buffer);
void run(char *buffer, char *shell, char **envp, int iterations);
void create_child(char **cmd, char *name, char **env, int iterations);

void exit_shell(char **cmd);
int change_directory(const char *path);
void print_env(char **env);
char **_getPATH(char **env);

void execute(char **cmd, char *name, char **env, int iterations);
void error_msg(char *shell, int iterations, char **cmd);
void free_cmd(char **cmd, int exit_flag);

void trimLeadingWhiteSpace(char *str);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *src);
int _strncmp(char *s1, char *s2, size_t bytes);
char **split_string(char *buffer, const char *s);
char *comment_handling(char *buffer);
void semicolon_handle(char *buffer, char *shell, char **envp, int iterations);
int64_t _getline(char **buffer, size_t *size, FILE *fp);
char *_getenv(char *name);
extern char **environ;

#endif /* _SHELL_H_ */
