/* Main header file. */

/* Copyright (C) 2013 Kieran Colford

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see
   <http://www.gnu.org/licenses/>.

   The copyright holder can be contacted at <colfordk@gmail.com>. */

#ifndef COM_H
#define COM_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#include <errno.h>
#include <error.h>

#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <gmp.h>

#include <argp.h>
#include <readline/readline.h>
#include "getpass.h"
#include "gc.h"
#include "xalloc.h"

#define FATAL_ERRORS 1
#define TCP_PORT "3488"
#define AUTH_MESSAGE "Hello, World!  How are you today?"
#define PRIME "6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151"
#define BASE "3578289724048573982478935709382473802573492584578203457938452709382758477205983457380894572380759348573485773892758472309857398573498570272349"

typedef struct 
{
  int sock;
  gc_cipher_handle cipher;
} connect_t;

typedef struct _mylist
{
  char *host;
  connect_t *conn;
  pthread_t thread;
  struct _mylist *nxt;
} list_t;

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

extern pthread_mutex_t tcp_mut;
extern list_t *tcp_rem;
extern char *pass;

extern mpz_t prime;
extern mpz_t base;

extern int authenticate (const list_t *entry);
extern int make_socket (const char *, const char *, int);
extern ssize_t recv_data (connect_t *, void *, size_t);
extern ssize_t send_data (connect_t *, const void *, size_t);

extern list_t *entry (char *, int, int);
extern void add_entry (list_t *);
extern void delete_entry (list_t *);

extern void *listen_daemon (void *);
extern void *connect_daemon (void *);
extern void *relay_daemon (void *);

extern int main (int, char **);

#if 0
{
#endif
#ifdef __cplusplus
}
#endif

#endif
