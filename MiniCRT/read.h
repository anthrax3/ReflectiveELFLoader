#ifndef READ_H
#define READ_H 1

#include "CRT.h"

__attribute__((always_inline)) int crt_read(int fd, char *buffer, unsigned long bufferlen);

#ifdef LINUX

	#ifdef x86

	#endif

	#ifdef ARM

	#endif

#ifdef x86_64
__attribute__((always_inline)) int
crt_read(int fd, char *buffer, unsigned long bufferlen)
{

	long ret;
	__asm__ volatile ("syscall" : "=a" (ret) : "a" (__NR_read),
		      "D" (fd), "S" (buffer), "d" (bufferlen) :
		      "cc", "memory", "rcx",
		      "r8", "r9", "r10", "r11" );
	if (ret < 0)
	{
		ret = -1;
	}
	return (int)ret;
}
#endif

#endif

#ifdef FREEBSD

	#ifdef x86

	#endif

	#ifdef ARM

	#endif

	#ifdef x86_64

	#endif
#endif


#endif






