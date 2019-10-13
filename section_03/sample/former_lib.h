#ifndef _FORMER_LIB_H_
#define _FORMER_LIB_H_

struct point {
  float x;
  float y;
};

float acquire_area(struct point *, struct point *);
void acquire_center_point(struct point *, struct point *, struct point *);

#endif
