#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
        size_t buf_size = 0;
        char *buf = NULL;
        char *token;
        int status, j = 0;
        char **array;
         pid_t child_pid;

        while (1)
        {
        write(1, "#cisfun$ ", 9);/*print the shell prompt*/
        getline(&buf, &buf_size, stdin);/*read the  user input*/
        token = strtok(buf, "\t\n");
        array = malloc(sizeof(char *) *1024);/*allocate memory for the command argument*/
                while(token)
                {
                        array[j] = token;/*store token in the argument array*/
                        token = strtok(NULL, "\t\n");/*get the next token*/
                        j++;
                }
        array[j] = NULL;/*Null-terminate the array*/
        child_pid = fork();

        if (child_pid == 0)/*child process*/
        {
                if(execve(array[0], array, NULL) == -1)/* Execute the command*/
                        perror("./shell");
        }

        else
        {
                wait(&status);/*Wait for the child process to finish*/
        }
        j = 0;
        free(array);

        }

        return 0;
}
