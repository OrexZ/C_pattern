#include "lib_abstract.h"
#include "former_lib.h"

static float rect_get_area(struct point * leftbottom, struct point *righttop){
  return acquire_area(leftbottom, righttop);
}

static void rect_get_center_point(struct point * leftbottom, struct point *righttop, struct point * center){
  acquire_center_point(leftbottom, righttop, center);
}

static struct rectangle_operation rect_ops = {
                                              .get_area = rect_get_area,
                                              .get_center_point = rect_get_center_point,
};

struct rectangle_info * rectangle_info_init(struct rectangle_info * rip, struct point * p1, struct point * p2){
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
  rsp->ops->get_area(&rsp->info->leftbottom, &rsp->info->righttop);
}

void rectangle_get_center_point(struct rectangle_shape *rsp, struct point * center){
  rsp->ops->get_center_point(&rsp->info->leftbottom, &rsp->info->righttop, center);
}
