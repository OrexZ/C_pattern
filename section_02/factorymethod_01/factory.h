#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "product.h"

struct factory_info {
  char f_name [20];
};

struct factory_ops{
  struct product * (* new_product)(void *);
};

struct factory{
  struct factory_ops *ops;
  struct factory_info *info;
  void * private_data;
};

int factory_init(void);
struct factory * get_factory_by_brand (const char *brand);
struct product * factory_new_product (const char* brand);

#endif
