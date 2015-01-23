#include "mybase.h"

int main(int argc, char **argv)
{
    int status = 0;
    /* getopt */

    // FIXME

    /* open syslog() recording */
    openlog("mydaemon", LOG_PERROR | LOG_PID, LOG_DAEMON | LOG_USER);

    // FIXME

    /* determine whether to run as a daemon */

    // FIXME

    /* register sigaction functions. */

    status = sigaction_init_process();
    if (status == -1) {
	/* unsuccessful sigaction set */
	syslog(LOG_ERR, "sigaction assignment failed. Exiting.");
	exit(EXIT_FAILURE);
    }

    // FIXME
    
    /* do sleep cycle; waiting for signals. */
    for (;;)
    {
	sleep(30);
	syslog(LOG_INFO, "daemon cron check.");
    }

    /* should never happen */
    printf("Hello World!\n");
    return(0);
}
