AC_PREREQ([2.69])
AC_INIT([deccenc], [1.0])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])

# Checks for programs.
AM_PROG_AR
AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AM_CONDITIONAL([TARGET_LOGTYPE_RLOG], [test x$logtype = xrlog])
AM_CONDITIONAL([TARGET_LOGTYPE_CLOG], [test x$logtype = xclog])

AC_CONFIG_FILES([
        Makefile 
        util/Makefile
        util/time/Makefile
        logger/Makefile
        logger/rlogger/Makefile
        logger/clogger/Makefile
        common/Makefile
        component/Makefile
        media/Makefile
])

AC_OUTPUT
