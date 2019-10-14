#include "product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void tcl_tv_show (struct product *pp){
  printf("\nProduct Information, device_id : [%s]\n"
         ">> TCL TV show\n", pp->info->device_id);
}

static struct product_ops tcl_tv_ops= {
  .show = tcl_tv_show,
};

static struct product_info tcl_tv_info = {
  .device_id = "TCL PANADA",
};

static void hisense_tv_show (struct product *pp){
  printf("\nProduct Information, device_id : [%s]\n"
         ">> Hisense TV show\n", pp->info->device_id);
}

static struct product_ops hisense_tv_ops= {
  .show = hisense_tv_show,
};

static struct product_info hisense_tv_info = {
  .device_id = "Hisense K876",
};

static struct product * new_TCL_tv (){
  struct product * tclp = malloc(sizeof(struct product));
  if (tclp != NULL){
    tclp->ops = &tcl_tv_ops;
    tclp->info = &tcl_tv_info;
    printf("<%s> is generated !\n", tclp->info->device_id);
  }
  return tclp;
}

static struct product * new_Hisense_tv (){
  struct product * hisensep = malloc(sizeof(struct product));
  if (hisensep != NULL){
    hisensep->ops = &hisense_tv_ops;
    hisensep->info = &hisense_tv_info;
    printf("<%s> is generated !\n", hisensep->info->device_id);
  }
  return hisensep;
}

struct product * new_tv (const char * brand){
  if (strcmp(brand, "TCL") == 0){
    return new_TCL_tv();
  }else if (strcmp(brand, "Hisense") == 0){
    return new_Hisense_tv();
  }else {
    printf("No match factory.[%s]\n", brand);
    return (struct product *)NULL;
  }
}

void destroy_product(struct product * tv){
  free(tv);
}

