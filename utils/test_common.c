#include "common.h" /* include stdio.h already */

struct student {
  char name[20];
  int age;
  int weight;
};

void main(void){
  struct student test = {
    .name = "REX",
    .age = 28,
    .weight = 135,
  };

  printf("name offset: 0x%X, id offset : 0x%X, dir offset: 0x%X\n",
         (unsigned)offsetof(struct student, name),
         (unsigned)offsetof(struct student, age),
         (unsigned)offsetof(struct student, weight));

  printf("student unique: %p\n", container_of(&test.name, struct student, name));
  printf("student unique: %p\n", container_of(&test.age, struct student, age));
  printf("student unique: %p\n", container_of(&test.weight, struct student, weight));
}
