#ifndef _PRODUCT_H_
#define _PRODUCT_H_

struct product_info {
  char device_id[20];
};


struct product;

struct product_ops {
  void (* show) (struct product *);
};

struct product {
  struct product_ops * ops;
  struct product_info * info;
};

struct product * new_tv (const char *);
void destory_product(struct product *);

#endif
