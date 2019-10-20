#include <stdio.h>
#include "app.h"

static struct rectangle_shape * rect_shape_p;

int app_init(struct rectangle_shape *rsp){
  rect_shape_p = rsp;
  return 0;
}

int app_exec(){
  struct point center;
  float rect_area;

  rect_area = rectangle_get_area(rect_shape_p);
  rectangle_get_center_point(rect_shape_p, &center);

  printf("< rectangle - area: %.2f, coordinate: (%.2f, %.2f) >\n",
         rect_area,
         center.x,
         center.y);

  return 0;
}
