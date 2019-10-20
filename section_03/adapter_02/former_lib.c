#include "former_lib.h"

float acquire_area(struct base_item* item){
  return (item->width) * (item->high);
}

void acquire_center_point(struct base_item * item, struct point*leftbottom, struct point *center){
  center->x = (leftbottom->x) + (item->width)/2;
  center->y = (leftbottom->y) + (item->high)/2;
}
