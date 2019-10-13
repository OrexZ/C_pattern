#include "former_lib.h"

float acquire_area(struct point *leftbottom, struct point *righttop){
  return (righttop->y - leftbottom->y) * (righttop->x - leftbottom->x);
}

void acquire_center_point(struct point * leftbottom, struct point *righttop, struct point *center){
  center->x = (righttop->x - leftbottom->x)/2;
  center->y = (righttop->y - leftbottom->y)/2;
}
