#ifndef _LIB_ABSTRACT_H_
#define _LIB_ABSTRACT_H_

#include "former_lib.h"

struct rectangle_operation {
  float (* get_area)(void*, struct point *, struct point *);
  void (* get_center_point)(void*, struct point *, struct point *, struct point *);
};

struct rectangle_info {
  struct point leftbottom;
  struct point righttop;
};

struct rectangle_shape {
  struct rectangle_operation * ops;
  struct rectangle_info * info;
  void * private_data;
};

struct rectangle_info * rectangle_info_init(struct rectangle_info * rip, struct point * p1, struct point * p2);
struct rectangle_shape * rectangle_shape_init(struct rectangle_shape *, struct rectangle_info *);

float rectangle_get_area(struct rectangle_shape* rsp);
void rectangle_get_center_point(struct rectangle_shape *rsp, struct point * center);

#endif
