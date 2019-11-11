#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "proxy.h"

struct girl {
    void (*listen)(void * self, struct matchmaker * mm);
    char *patient;
    int  len;
};

void deinit_girl(struct girl * g);
int init_girl(struct girl * g, char * patient, int len);

#endif
