lib_LIBRARIES = libflogger.a
libflogger_a_CPPFLAGS = -I../ -I../../util/time/
libflogger_a_SOURCES = flogger.c
libflogger_a_LIBADD = ../../util/time/libt_utility.a

bin_PROGRAMS = flogger_test
flogger_test_CPPFLAGS = -I../ -Wall -ggdb3
flogger_test_SOURCES = flogger_test.c
flogger_test_LDADD = libflogger.a ../../util/time/libt_utility.a

CLEANFILES = *.a *.o Makefile.in Makefile
