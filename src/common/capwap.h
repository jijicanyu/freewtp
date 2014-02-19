#ifndef __CAPWAP_HEADER__
#define __CAPWAP_HEADER__

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <sys/time.h>
#include <net/if.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* Endian */
#if __BYTE_ORDER == __BIG_ENDIAN
	#define CAPWAP_BIG_ENDIAN
#else
	#define CAPWAP_LITTLE_ENDIAN
#endif

/* Min & Max */
#ifndef max
	#define max(a,b) ((a) >= (b) ? (a) : (b))
#endif

#ifndef min
	#define min(a,b) ((a) <= (b) ? (a) : (b))
#endif

/* UDPLite */
#ifdef HAVE_NETINET_UDPLITE_H
#include <netinet/udplite.h>
#else
#ifndef IPPROTO_UDPLITE
#define IPPROTO_UDPLITE			136
#endif
#ifndef SOL_UDPLITE
#define SOL_UDPLITE				136
#endif
#ifndef UDPLITE_SEND_CSCOV
#define UDPLITE_SEND_CSCOV		10
#endif
#endif

/* standard include */
#include "capwap_logging.h"
#include "capwap_debug.h"
#include "capwap_error.h"

/* Helper exit */
void capwap_exit(int errorcode);

/* Random generator */
void capwap_init_rand(void);
int capwap_get_rand(int max);

/* Helper timeout calc */
struct timeout_control_item {
	int enable;
	long delta;
	unsigned long durate;
	struct timeval timestop;
};

#define CAPWAP_TIMER_UNDEF						-1
#define CAPWAP_TIMER_CONTROL_CONNECTION			0
#define CAPWAP_TIMER_CONTROL_ECHO				1
#define CAPWAP_TIMER_DATA_KEEPALIVE				2
#define CAPWAP_TIMER_DATA_KEEPALIVEDEAD			3
#define CAPWAP_MAX_TIMER						4

struct timeout_control {
	struct timeout_control_item items[CAPWAP_MAX_TIMER];
};

struct timeout_control* capwap_timeout_init(void);
void capwap_timeout_free(struct timeout_control* timeout);

long capwap_timeout_get(struct timeout_control* timeout, long* index);
void capwap_timeout_update(struct timeout_control* timeout);
void capwap_timeout_set(unsigned long value, struct timeout_control* timeout, unsigned long index);

void capwap_timeout_wait(struct timeout_control* timeout, unsigned long index);

int capwap_timeout_isenable(struct timeout_control* timeout, unsigned long index);
int capwap_timeout_hasexpired(struct timeout_control* timeout, unsigned long index);

void capwap_timeout_kill(struct timeout_control* timeout, unsigned long index);
void capwap_timeout_killall(struct timeout_control* timeout);

/* */
void capwap_daemon(void);

/* */
#define capwap_outofmemory()						do {																	\
														capwap_logging_fatal("Out of memory %s(%d)", __FILE__, __LINE__);	\
														capwap_exit(CAPWAP_OUT_OF_MEMORY); 									\
													} while(0)

/* Helper buffer copy */
char* capwap_duplicate_string(const char* source);
void* capwap_clone(const void* buffer, int buffersize);

/* */
char* capwap_itoa(int input, char* output);
char* capwap_ltoa(long input, char* output);

#endif /* __CAPWAP_HEADER__ */
