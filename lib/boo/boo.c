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
#include <boo.h>

int mt_boo_enable(void)
{
	printf("BOO %d\n", MT_MOD_ENABLE);
	return 0;
}

int mt_boo_disable(void)
{
	printf("BOO %d\n", MT_MOD_DISABLE);
	return 0;
}