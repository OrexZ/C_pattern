#ifndef _ADAPTER_H_
#define _ADAPTER_H_

/* #include "lib_abstract.h" */
#include "former_lib.h"

struct adapter_ops {
  float (* get_area)(void*, struct point *, struct point *);
  void (* get_center_point)(void*, struct point *, struct point *, struct point *);
};

struct adapter {
  void * other;
  void * self;
  struct adapter_ops *ops;
};

struct adapter * rectangle_shape_adapter_init(struct adapter * adapterp);

#endif
