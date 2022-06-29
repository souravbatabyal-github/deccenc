if TARGET_LOGTYPE_CLOG
SUBDIRS = clogger
else
if TARGET_LOGTYPE_FLOG
SUBDIRS = flogger
else
if TARGET_LOGTYPE_RLOG
SUBDIRS = rlogger
else
if TARGET_LOGTYPE_SYSLOG
SUBDIRS = syslogger
else
SUBDIRS = clogger
endif
endif
endif
endif
CLEANFILES = *.a *.o Makefile.in Makefile
