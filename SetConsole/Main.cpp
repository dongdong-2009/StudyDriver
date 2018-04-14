#include "SystemInclude.h"
#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
    char bytes[2] = {11,0}; /* 11 is the TIOCLINUX cmd number. */

    if (argc==2)
        bytes[1] = atoi(argv[1]); /* the chosen console */
    else
    {
        cerr << "need a single argument." << endl;
        return -1;
    }
    if (ioctl(STDIN_FILENO, TIOCLINUX, bytes) < 0)
    {
        cerr << "ioctl() failed." << endl;
    }

    return 0;
}

