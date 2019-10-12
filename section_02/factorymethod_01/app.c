#include "app.h"
#include "factory.h"
#include <stdio.h>

int app_init(){
  /* Now do nothing */
  return 0;
}

int app_run(){
  struct product * product_01 = factory_new_product("TCL");
  struct product * product_02 = factory_new_product("Hisense");

  if (product_01 != NULL){
    product_01->ops->show(product_01);
  }

  if (product_02 != NULL){
    product_02->ops->show(product_02);
  }

  return 0;
}
