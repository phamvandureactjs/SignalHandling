// CPP program to illustrate dup2()
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    // int file_desc = open("output.txt",O_WRONLY | O_APPEND);

    // dup2(file_desc, STDOUT_FILENO) ;

    // printf("I will be printed in the file tricky.txt\n");
    // close(file_desc);
    // return 0;
    int number1, number2, sum;

    int input_fds = open("output.txt", O_RDONLY);

    if (dup2(input_fds, STDIN_FILENO) < 0)
    {
        printf("Unable to duplicate file descriptor.");
        exit(EXIT_FAILURE);
    }

    scanf("%d %d", &number1, &number2);

    sum = number1 + number2;

    printf("%d + %d = %d\n", number1, number2, sum);

    return EXIT_SUCCESS;
}
