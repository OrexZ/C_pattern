#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "product.h"
/* #include "../../utils/list.h" */
#include "list.h"

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
  struct list_head list;
};


struct factory * get_factory_by_brand (const char *brand);
struct product * factory_new_product (const char* brand);

int register_factory(struct factory * fp);
int unregister_factory(const char * brand);

int factory_init(void);

#endif
