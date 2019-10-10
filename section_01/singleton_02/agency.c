#include "agency.h"
#include <stdio.h>

void check_identity(void){
  struct person *person_01, *person_02;

  person_01 = get_person_info();
  person_02 = get_person_info();

  if (person_01 == person_02){
    printf("person_01 is the same as person_02\n"
           "PERSOIN INFO>\nname: %s\nid: %s\n",
           person_01->name,
           person_01->id);
  }else{
    /* Never be here */
    printf("person_01 is different from person_02\n");
  }

}
