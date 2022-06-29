lib_LIBRARIES = libsyslogger.a
libsyslogger_a_CPPFLAGS = -I../ -I../../util/time/ -I../../util/string/
libsyslogger_a_SOURCES = syslogger.c
libsyslogger_a_LIBADD = ../../util/time/libt_utility.a ../../util/string/libt_string.a

bin_PROGRAMS = syslogger_test
syslogger_test_CPPFLAGS = -I../
syslogger_test_SOURCES = syslogger_test.c
syslogger_test_LDADD = libsyslogger.a ../../util/time/libt_utility.a ../../util/string/libt_string.a -lpthread

CLEANFILES = *.a *.o Makefile.in Makefile
