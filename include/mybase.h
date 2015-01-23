#ifndef APUE_EXAMPLE_MYBASE_H
#define APUE_EXAMPLE_MYBASE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

/* number used in signal handling */
extern sig_atomic_t signumber;

#endif /* APUE_EXAMPLE_MYBASE_H */
