#include "mybase.h"

/**
 * @brief Be a daemon.
 * @return pid on success
 * @return -1 on failure
 * */
int
start_daemon()
{
    int pid = -1;
    int fdnum = getdtablesize();

    /* fork(), setsid(), fork() */
    if (fork()) {
	exit(EXIT_SUCCESS);
    }
    if (setsid() == -1) {
	syslog(LOG_ERR, "failed in setsid().");
	exit(EXIT_FAILURE);
    }
    if ((pid =fork())) {
	exit(EXIT_SUCCESS);
    }
    
    /* close file descriptor */
    while (fdnum) {
	(void) close(--fdnum);
    }
    syslog(LOG_INFO, "the program is now a daemon.");

    return(pid);
}

