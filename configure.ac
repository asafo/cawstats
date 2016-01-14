#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

#AC_PREREQ(2.60)
AC_INIT(cawstats, 1.0, asaf@hadasa-oss.net)
AC_LANG([C++])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([cawstats.cpp])
AC_CONFIG_HEADER([config.hpp])
AM_INIT_AUTOMAKE(cawstats, main)

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for modules.
# PKG_CHECK_MODULES([DEPS], [curlpp >= 0.7.3])

# Checks for libraries.
AM_PROG_LIBTOOL

# Checks for header files
dnl CFLAGS="-I/usr/include"

AC_CHECK_HEADER([cppcms/application.h], [ ], [AC_MSG_ERROR([could not find cppcms/application.h])])
AC_CHECK_HEADER([boost/date_time/time.hpp], [], [AC_MSG_ERROR([could not find Boost  date time : boost/date_time/time.hpp])])

# Checks for typedefs, structures, and compiler characteristics.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
