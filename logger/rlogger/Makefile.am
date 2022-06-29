lib_LIBRARIES = librlogger.a
librlogger_a_CPPFLAGS = -I../ -I../../util/time/ -I../../util/string/
librlogger_a_SOURCES = rlogger.c
librlogger_a_LIBADD = ../../util/time/libt_utility.a ../../util/string/libt_string.a

bin_PROGRAMS = rlogger_test
rlogger_test_CPPFLAGS = -I../
rlogger_test_SOURCES = rlogger_test.c
rlogger_test_LDADD = librlogger.a ../../util/time/libt_utility.a ../../util/string/libt_string.a -lpthread

CLEANFILES = *.a *.o Makefile.in Makefile
