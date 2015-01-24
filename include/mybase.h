#ifndef APUE_EXAMPLE_MYBASE_H
#define APUE_EXAMPLE_MYBASE_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

extern char *fs_declaration;

/* number used in signal handling */
extern sig_atomic_t signumber;

/* library function API */
int start_daemon();
int sigaction_init_process();

#endif /* APUE_EXAMPLE_MYBASE_H */
