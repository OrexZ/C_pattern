#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h> /* for size_t */

#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#define container_of(ptr, type, member) ({\
  const typeof(((type *)0)->member) * __mptr = ptr;\
  (type *) ((char *)__mptr - offsetof(type,member));})

#endif
