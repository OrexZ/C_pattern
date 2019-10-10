#include "person.h"
#include <stdlib.h> /* for malloc and free */
#include <string.h> /* for strcpy */

struct person * get_person_info(){
  static struct person *htc = NULL;

  if (htc == NULL){
    htc = malloc(sizeof(struct person));
    strcpy(htc->name, "hongtaoC");
    strcpy(htc->id, "1234123456781234");
  }

  return htc;
}

void drop_person_info(struct person * person){
  free(person);
}
