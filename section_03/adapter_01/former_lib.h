#ifndef _FORMER_LIB_H_
#define _FORMER_LIB_H_

struct point {
  float x;
  float y;
};

struct base_item {
  float width;
  float high;
};

float acquire_area(struct base_item *);
void acquire_center_point(struct base_item *, struct point *, struct point *);

#endif
