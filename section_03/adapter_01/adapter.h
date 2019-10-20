#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "lib_abstract.h"

typedef struct rectangle_info rectangle_info_adapter;
typedef struct rectangle_shape rectangle_shape_adapter;
typedef struct rectangle_operation rectangle_operation_adapter;

rectangle_info_adapter * rectangle_info_adapter_init(rectangle_info_adapter * info_adp,
                                                     struct point *,
                                                     struct point *);
rectangle_shape_adapter * rectangle_shape_adapter_init(rectangle_shape_adapter * adapterp,
                                                       rectangle_info_adapter * info);

#endif
