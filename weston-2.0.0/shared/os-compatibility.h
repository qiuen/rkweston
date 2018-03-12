/*
 * Copyright © 2012 Collabora, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef OS_COMPATIBILITY_H
#define OS_COMPATIBILITY_H

#include "config.h"

#include <sys/types.h>
#include <time.h>

#ifdef HAVE_EXECINFO_H
#include <execinfo.h>
#else
static inline int
backtrace(void **buffer, int size)
{
	return 0;
}
#endif

#ifndef CLOCK_BOOTTIME
#define CLOCK_BOOTTIME 7
#endif

int
os_fd_set_cloexec(int fd);

int
os_socketpair_cloexec(int domain, int type, int protocol, int *sv);

int
os_epoll_create_cloexec(void);

int
os_create_anonymous_file(off_t size);

#ifndef HAVE_STRCHRNUL
char *
strchrnul(const char *s, int c);
#endif

#endif /* OS_COMPATIBILITY_H */