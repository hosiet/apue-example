/*
 * mydaemon.c
 *
 * Copyright (C) 2015 - Boyuan Yang
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "mybase.h"

char *fs_declaration = "This program is free software; you can redistribute it and/or modify\n"
                       "it under the terms of the GNU General Public License as published by\n"
                       "the Free Software Foundation; either version 3 of the License, or\n"
                       "(at your option) any later version.\n\n"
                       "You should have received a copy of the GNU General Public License\n"
                       "along with this program; if not, see <http://www.gnu.org/licenses/>.\n";

void print_version_msg()
{
    fprintf(stdout, "\n%s\n\n", PACKAGE_STRING);
    fprintf(stdout, "%s\n", fs_declaration);
    return;
}

int main(int argc, char **argv)
{
    int status = 0;
    int opt;		/* getopt */
    int standalone = 1;

    /* getopt */

    while ((opt = getopt(argc, argv, "ihv")) != -1) {
	switch (opt) {
	    case 'i':
		standalone = 0;
		break;
	    case 'v':
		print_version_msg();
		exit(EXIT_FAILURE);
	    case 'h':
	    default: /* '?' */
		fprintf(stdout, "Usage: %s [-v] [-h] [-i]\n"
		    "\n"
		    " -i    interactive mode (no fork)\n"
		    " -v    show version info\n"
		    " -h    show help message\n\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    }

    /* open syslog() recording */

    openlog("mydaemon", LOG_PERROR | LOG_PID, LOG_DAEMON | LOG_USER);

    /* determine whether to run as a daemon */

    // FIXME

    /* register sigaction functions. */

    status = sigaction_init_process();
    if (status == -1) {
	/* unsuccessful sigaction set */
	syslog(LOG_ERR, "sigaction assignment failed. Exiting.");
	exit(EXIT_FAILURE);
    }
    
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
