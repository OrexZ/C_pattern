#include "person.h"

static struct person htc = {
  .name = "hongtaoC",
  .id = "123456123456781234",
};

struct person * get_person_info(){
  return &htc;
}
