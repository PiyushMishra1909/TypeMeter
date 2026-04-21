#include <stdio.h>
#include <unistd.h> // for sleep/usleep

int main()
{
    while (1)
    {
        printf("Hello");
        fflush(stdout);   // force print
        usleep(500000);   // 0.5 sec

        printf("\r     "); // erase text (same length)
        fflush(stdout);
        usleep(500000);

        printf("\r"); // return to start
    }
    return 0;
}