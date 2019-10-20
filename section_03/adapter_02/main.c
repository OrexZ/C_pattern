#include "app.h"
#include <stdlib.h>

int main(int argc, char ** argv){

  struct adapter * adapter_p;
  struct rectangle_info * info_p;
  struct rectangle_shape * rect_p;

  struct point leftbottom = {1,1};
  struct point righttop = {10,14};

  rect_p = malloc(sizeof(struct rectangle_shape));
  if (rect_p == NULL){
    return -1;
  }

  info_p = malloc(sizeof(struct rectangle_info));
  if (info_p == NULL){
    return -1;
  }

  adapter_p = malloc(sizeof(struct adapter));
  if (adapter_p == NULL){
    return -1;
  }


  rectangle_shape_adapter_init(adapter_p); /* must before rectangle_shape_init */
  rectangle_info_init(info_p, &leftbottom, &righttop);
  rectangle_shape_init(rect_p, info_p, adapter_p);

  app_init(rect_p);
  app_exec();

  return 0;
}
