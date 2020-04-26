#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#include <foo.h>
#include <common.h>

int mt_foo_enable(void)
{
	printf("FOO %d\n", MT_MOD_ENABLE);
	return 0;
}

int mt_foo_disable(void)
{
	printf("FOO %d\n", MT_MOD_DISABLE);
	return 0;
}