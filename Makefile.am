SUBDIRS = lib tests
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = m4/gnulib-cache.m4 $(TESTS)

AM_CPPFLAGS = -I$(srcdir)/lib
AM_CFLAGS = -pthread

pkglib_LTLIBRARIES = libcom.la
libcom_la_LDFLAGS = $(GETADDRINFO) $(HOSTENT_LIB) $(INET_NTOP_LIB) $(LIBSOCKET) $(LTLIBINTL) $(LTLIBREADLINE) $(SERVENT_LIB)
libcom_la_SOURCES = 				\
src/add_entry.c					\
src/authenticate.c 				\
src/broadcast.c                                 \
src/connect_daemon.c				\
src/delete_entry.c				\
src/entry.c					\
src/init.c					\
src/input.c                                     \
src/listen_daemon.c				\
src/make_socket.c 				\
src/recv_data.c 				\
src/relay_daemon.c				\
src/send_data.c

include_HEADERS = com.h

bin_PROGRAMS = com
com_SOURCES = src/main.c
com_LDADD = libcom.la lib/libgnu.la

dist_man1_MANS = com.1

com.1: src/main.c $(top_srcdir)/configure.ac
	$(MAKE) $(AM_MAKEFLAGS) com$(EXEEXT)
	help2man -o com.1 ./com$(EXEEXT)
