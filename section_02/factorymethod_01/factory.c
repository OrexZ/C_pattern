#include "factory.h"
#include <stdio.h>

static struct product * TCL_new_product (void *private_data){
  struct factory * tcl = (struct factory *) private_data;
  printf("<%s> factory is producting tv...\n", tcl->info->f_name);
  return new_tv(tcl->info->f_name);
}

static struct product * Hisense_new_product (void *private_data){
  struct factory * hisense = (struct factory *) private_data;
  printf("<%s> factory is producting tv...\n", hisense->info->f_name);
  return new_tv(hisense->info->f_name);
}

static struct factory_ops TCL_factory_ops = {
  .new_product = TCL_new_product,
};

static struct factory_ops Hisense_factory_ops = {
  .new_product = Hisense_new_product,
};

static struct factory_info TCL_factory_info = {
  .f_name = "TCL",
};

static struct factory_info Hisense_factory_info = {
  .f_name = "Hisense",
};

static struct factory tcl;
static struct factory hisense;

static struct factory * TCL_factory_init(void){
  tcl.ops = &TCL_factory_ops;
  tcl.info = &TCL_factory_info;
  tcl.private_data = &tcl;
  tcl.list.next = &tcl.list;
  tcl.list.prev = &tcl.list;
  return &tcl;
}

static struct factory * Hisense_factory_init(void){
  hisense.ops = &Hisense_factory_ops;
  hisense.info = &Hisense_factory_info;
  hisense.private_data = &hisense;
  hisense.list.next = &hisense.list;
  hisense.list.prev = &hisense.list;
  return &hisense;
}

static LIST_HEAD(factorys);

int register_factory(struct factory * fp){
  struct list_head * pos;
  list_for_each(pos, &factorys){
    if (strcmp(list_entry(pos, struct factory, list)->info->f_name,
               fp->info->f_name) == 0 ){
      printf("Factory [%s] already was registered.\n", fp->info->f_name);
      return -1;
    }
  }
  list_add_tail(&fp->list, &factorys);
  return 0;
}

int unregister_factory(const char * brand){
  struct list_head *pos, *next;
  struct factory * fp;

  list_for_each_safe(pos,next, &factorys){
    fp = list_entry(pos, struct factory, list);
    if (strcmp(fp->info->f_name, brand) == 0){
      list_del(pos);
      return 0;
    }
  }
  printf("Factory Brand Unknown [%s]", brand);

  return -1;
}

typedef struct factory * (* init_cb)(void);

init_cb factory_init_func_table [] = {
  TCL_factory_init,
  Hisense_factory_init,
  NULL,
};

int factory_init(void){
  init_cb *cbpp;
  struct factory * fp;

  for (cbpp = &factory_init_func_table[0]; *cbpp != NULL; cbpp++){
    fp = (*cbpp)();
    if (register_factory(fp) != 0){
      printf("factory [%s] can't be registered!\n", fp->info->f_name);
    }else{
      printf("factory [%s] is registered successfully!\n", fp->info->f_name);
    }
  }

  return 0;
}

struct factory * get_factory_by_brand (const char *brand){
  struct list_head * pos;
  struct factory * fp;
  list_for_each(pos, &factorys){
    fp = list_entry(pos, struct factory, list);
    if (strcmp(fp->info->f_name, brand) == 0){
      return fp;
    }
  }
  return (struct factory *)NULL;
}

struct product * factory_new_product (const char* brand){
  struct factory *fp = get_factory_by_brand(brand);
  if (fp == (struct factory *)NULL){
    return (struct product *) NULL;
  }
  return fp->ops->new_product(fp);
}
