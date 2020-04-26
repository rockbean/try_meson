#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#include <common.h>
#include <mt_config.h>
#ifdef MT_FOO_SUPPORT
#include <foo.h>
#endif
#ifdef MT_BOO_SUPPORT
#include <boo.h>
#endif

void *mt_thread(void *arg);

void *mt_thread(void *arg) 
{
	sleep(1);
	printf("Hello from thread\n");
	return NULL;
}

int main(void)
{
	pthread_t thread_id;
	printf("Hello World\n");
#ifdef MT_FOO_SUPPORT
	mt_foo_enable();
	mt_foo_disable();
#endif

	pthread_create(&thread_id, NULL, mt_thread, NULL); 
	pthread_join(thread_id, NULL);

#ifdef MT_BOO_SUPPORT
	mt_boo_enable();
	mt_boo_disable();
#endif
	return 0;
}