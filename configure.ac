#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([APUE_EXAMPLE], [v0.0.1], [073plan@gmail.com])
AC_CONFIG_SRCDIR([src/sigaction.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile
		 include/Makefile
		 src/Makefile])

AC_OUTPUT
