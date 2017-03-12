#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([ngmonitor], [0.1.0], [heidsoft@qq.com])
AC_CONFIG_SRCDIR([src/daemon/NgDeamon.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign]) 
# Checks for programs.
AC_PROG_CC

# If SUBDIRS is defined, then your `configure.in' must include AC_PROG_MAKE_SET. 
# When Automake invokes make in a subdirectory, it uses the value of the MAKE variable. 
# It passes the value of the variable AM_MAKEFLAGS to the make invocation; 
# this can be set in `Makefile.am' if there are flags you must always pass to make.
AC_PROG_MAKE_SET

# Checks for libraries.
# FIXME: Replace `main' with a function in `-levent':
AC_CHECK_LIB([event], [main])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/daemon/Makefile
                 src/monitor/Makefile])
AC_OUTPUT
