#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int
main(int argc, char *argv[])
{
    time_t currentTime;
    time(&currentTime);

    struct tm *myTime = localtime(&currentTime);
        int month = myTime->tm_mon + 1;
        int year = myTime->tm_year + 1900;

    printf("The current date and time is: %i/%i/%i %i:%i:%i\n", month, myTime->tm_mday, year, myTime->tm_hour, myTime->tm_min, myTime->tm_sec);

    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
    }

    return 0;
}
