#include "mybase.h"

/* global var */

sig_atomic_t signumber = 0;

/* sigaction handler functions */

static void
SIGTERM_handler(int sa_number)
{
    /* signal should be dealt here */
    syslog(LOG_NOTICE, "This is SIGTERM handler. exiting...");
    exit(EXIT_SUCCESS);
    return;
}

static void
SIGUSR1_handler(int sa_number)
{
    syslog(LOG_NOTICE, "SIGUSR1 received.");
    return;
}

static void
SIGUSR2_handler(int sa_number)
{
    syslog(LOG_NOTICE, "SIGUSR2 received.");
    return;
}

static void
SIGHUP_handler(int sa_number)
{
    syslog(LOG_NOTICE, "SIGHUP received.");
    return;
}

/**
 * @brief 设置信号处理函数
 * */
int
sigaction_init_process()
{
    struct sigaction sa_SIGHUP;
    struct sigaction sa_SIGTERM;
    struct sigaction sa_SIGUSR1;
    struct sigaction sa_SIGUSR2;

    /* maybe unnecessary */
    memset(&sa_SIGHUP, 0, sizeof(sa_SIGHUP));
    memset(&sa_SIGTERM, 0, sizeof(sa_SIGTERM));
    memset(&sa_SIGUSR1, 0, sizeof(sa_SIGUSR1));
    memset(&sa_SIGUSR2, 0, sizeof(sa_SIGUSR2));

    sigemptyset(&sa_SIGHUP.sa_mask);
    sigemptyset(&sa_SIGTERM.sa_mask);
    sigemptyset(&sa_SIGUSR1.sa_mask);
    sigemptyset(&sa_SIGUSR2.sa_mask);

    sa_SIGHUP.sa_handler = SIGHUP_handler;
    sa_SIGTERM.sa_handler = SIGTERM_handler;
    sa_SIGUSR1.sa_handler = SIGUSR1_handler;
    sa_SIGUSR2.sa_handler = SIGUSR2_handler;

    /* assign sigaction */
    if (sigaction(SIGTERM, &sa_SIGTERM, NULL) == -1)
    {
	syslog(LOG_CRIT, "SIGTERM assign failed!");
	return(-1);
    }
    if (sigaction(SIGHUP, &sa_SIGHUP, NULL) == -1)
    {
	syslog(LOG_CRIT, "SIGHUP assign failed!");
	return(-1);
    }
    if (sigaction(SIGUSR1, &sa_SIGUSR1, NULL) == -1)
    {
	syslog(LOG_CRIT, "SIGUSR1 assign failed!");
	return(-1);
    }
    if (sigaction(SIGUSR2, &sa_SIGUSR2, NULL) == -1)
    {
	syslog(LOG_CRIT, "SIGUSR2 assign failed!");
	return(-1);
    }
    return(0);
}

/* FIXME
 *
 * try to use sa.sa_mask;
 * deal with child processes;
 * use siginfo_t for better dealing experience.
 */
