#include "factory.h"
#include <stdio.h>

static struct product * TCL_new_product (void *private_data){
  struct factory * tcl = (struct factory *) private_data;
  printf("I'm <%s> factory.\n", hisense->info.f_name);
  return new_tv(tcl->info.f_name);
}

static struct product * Hisense_new_product (void *private_data){
  struct factory * hisense = (struct factory *) private_data;
  printf("I'm <%s> factory.\n", hisense->info.f_name);
  return new_tv(hisense->info.f_name);
}

static struct factory_ops TCL_factory_ops = {
  .new_product = TCL_new_product,
};

static struct factory_ops Hisense_factory_ops = {
  .new_product = Hisense_new_product,
};

static struct factory_info TCL_factory_info = {
  .f_name = "TCL";
};

static struct factory_info Hisense_factory_info = {
  .f_name = "Hisense";
};

static struct factory tcl;
static struct factory hisense;

static int TCL_factory_init(void){
  tcl->ops = &TCL_factory_ops;
  tcl->info = &TCL_factory_info;
  tcl->private_data = &tcl;
  return 0;
}

static int Hisense_factory_init(void){
  hisense->ops = &Hisense_factory_ops;
  hisense->info = &Hisense_factory_info;
  hisense->private_data = &hisense;
  return 0;
}

int factory_init(void){
}

struct factory * get_factory_by_brand (const char *brand){

}

struct product * factory_new_product (const char* brand){
  struct factory *f = get_factory_by_brand(brand);
  return f->new_product(f);
}
