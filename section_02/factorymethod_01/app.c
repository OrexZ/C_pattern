#include "app.h"
#include "factory.h"

int app_init(){
  return 0;
}

int app_run(){
  struct product * product_01 = factory_new_product("TCL");
  struct product * product_02 = factory_new_product("Hisense");
  product_01->show();
  product_02->show();
  return 0;
}
