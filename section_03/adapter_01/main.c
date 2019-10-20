#include "app.h"
#include <stdlib.h>

int main(int argc, char ** argv){

  rectangle_shape_adapter * rect_p;
  rectangle_info_adapter * info_p;

  struct point leftbottom = {1,1};
  struct point righttop = {10,14};

  rect_p = malloc(sizeof(rectangle_shape_adapter));
  if (rect_p == NULL){
    return -1;
  }

  info_p = malloc(sizeof(rectangle_info_adapter));
  if (info_p == NULL){
    return -1;
  }


  rectangle_info_adapter_init(info_p, &leftbottom, &righttop);
  rectangle_shape_adapter_init(rect_p, info_p);

  app_init((struct rectangle_shape *)rect_p);
  app_exec();

  return 0;
}
