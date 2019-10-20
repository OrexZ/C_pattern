#include "lib_abstract.h"

static float rect_get_area(void *private_data,
                           struct point * leftbottom,
                           struct point *righttop){
  struct adapter * adp = (struct adapter *) private_data;
  return adp->ops->get_area(adp->self, leftbottom, righttop);
}

static void rect_get_center_point(void *private_data,
                                  struct point * leftbottom,
                                  struct point *righttop,
                                  struct point * center){
  struct adapter * adp = (struct adapter *) private_data;
  adp->ops->get_center_point(adp->self, leftbottom, righttop, center);
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
                                              struct rectangle_info *info,
                                              struct adapter * adp){
  rsp->ops = &rect_ops;

  adp->other = rsp;
  rsp->private_data = adp;

  rsp->info = info;
  return rsp;
}

float rectangle_get_area(struct rectangle_shape* rsp){
  rsp->ops->get_area(rsp->private_data,
                     &rsp->info->leftbottom,
                     &rsp->info->righttop);
}

void rectangle_get_center_point(struct rectangle_shape *rsp,
                                struct point * center){
  rsp->ops->get_center_point(rsp->private_data,
                             &rsp->info->leftbottom,
                             &rsp->info->righttop, center);
}
