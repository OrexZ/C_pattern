#include "list.h"
#include <stdlib.h>
#include <string.h>

struct person {
  char name[25];
  char gender[10];
  unsigned age;
  struct list_head node;
};

struct person * init_person(char * name, char * gender, unsigned age){
  struct person * p = (struct person *)malloc(sizeof(struct person));
  strncpy(p->name, name, sizeof(p->name));
  strncpy(p->gender, gender, sizeof(p->gender));
  p->age = age;
  p->node.next = &p->node;
  p->node.prev = &p->node;
  return p;
}

void deinit_person(struct person * p){
  free(p);
}

int main (int argc, const char ** argv){

  struct list_head * iter;
  struct person * pperson;

  LIST_HEAD(students);

  struct person * tom = init_person("TOM", "MAN", 12);
  struct person * rex = init_person("REX", "MAN", 28);
  struct person * jim = init_person("JIM", "WOMEN", 40);

  list_add(&tom->node, &students);
  list_add_tail(&rex->node, &tom->node);
  list_add(&jim->node, &tom->node);

  list_for_each(iter, &students){
    pperson = list_entry(iter, struct person, node);
    printf("< Name: %s, Age: %d, Gender: %s>\n",
           pperson->name,
           pperson->age,
           pperson->gender);
  }

  return 0;
}
