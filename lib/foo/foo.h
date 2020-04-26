#ifndef _FOO_H_
#define _FOO_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

int mt_foo_enable(void);
int mt_foo_disable(void);

#ifdef __cplusplus
}
#endif

#endif //_FOO_H_