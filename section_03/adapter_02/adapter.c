#include "adapter.h"
#include <stdio.h>

static int convert_points_to_item(struct point * leftbottom, struct point * righttop, struct base_item * item){
  item->width = (righttop->x - leftbottom->x);
  item->high  = (righttop->y - leftbottom->y);

  return 0;
}

static float adapter_get_area(void *private_data,
                              struct point * leftbottom,
                              struct point * righttop){
  struct base_item item;
  convert_points_to_item(leftbottom, righttop, &item);
  return acquire_area(&item);
}

static void adapter_get_center_point(void *private_data,
                                     struct point *leftbottom,
                                     struct point *righttop,
                                     struct point *center){
  struct base_item item;
  convert_points_to_item(leftbottom, righttop, &item);
  acquire_center_point(&item, leftbottom, center);
}

static struct adapter_ops _adapter_ops = {
  .get_area = adapter_get_area,
  .get_center_point = adapter_get_center_point,
};


struct adapter * rectangle_shape_adapter_init(struct adapter * adapterp){
  adapterp->ops = &_adapter_ops;
  adapterp->self = adapterp;
  adapterp->other = NULL;
  return adapterp;
}

