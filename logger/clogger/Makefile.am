lib_LIBRARIES = libclogger.a
libclogger_a_CPPFLAGS = -I../ -I../../util/time/
libclogger_a_SOURCES = clogger.c
libclogger_a_LIBADD = ../../util/time/libt_utility.a

bin_PROGRAMS = clogger_test
clogger_test_CPPFLAGS = -I../
clogger_test_SOURCES = clogger_test.c
clogger_test_LDADD = libclogger.a ../../util/time/libt_utility.a

CLEANFILES = *.a *.o Makefile.in Makefile
