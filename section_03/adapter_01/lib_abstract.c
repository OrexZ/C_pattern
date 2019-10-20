#include "adapter.h"

static float rect_get_area(void *private_data,
                           struct point * leftbottom,
                           struct point *righttop){
  rectangle_shape_adapter * self = (rectangle_shape_adapter *) private_data;
  return self->ops->get_area(self, leftbottom, righttop);
}

static void rect_get_center_point(void *private_data,
                                  struct point * leftbottom,
                                  struct point *righttop,
                                  struct point * center){
  rectangle_shape_adapter * self = (rectangle_shape_adapter *) private_data;
  self->ops->get_center_point(self, leftbottom, righttop, center);
}

static struct rectangle_operation rect_ops = {
  .get_area = rect_get_area,
  .get_center_point = rect_get_center_point,
};

struct rectangle_info * rectangle_info_init(struct rectangle_info * rip,
                                            struct point * p1,
                                            struct point * p2){
  rip->leftbottom.x = p1->x;
  rip->leftbottom.y = p1->y;

  rip->righttop.x = p2->x;
  rip->righttop.y = p2->y;

  return rip;
}

struct rectangle_shape * rectangle_shape_init(struct rectangle_shape *rsp,
                                              struct rectangle_info *info){
  rsp->ops = &rect_ops;
  rsp->private_data = rsp;
  rsp->info = info;
  return rsp;
}

float rectangle_get_area(struct rectangle_shape* rsp){
  rsp->ops->get_area(rsp,
                     &rsp->info->leftbottom,
                     &rsp->info->righttop);
}

void rectangle_get_center_point(struct rectangle_shape *rsp,
                                struct point * center){
  rsp->ops->get_center_point(rsp,
                             &rsp->info->leftbottom,
                             &rsp->info->righttop, center);
}
