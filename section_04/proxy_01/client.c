#include "client.h"
#include <stdio.h>
#include <stdlib.h>

static void girl_listen(void *self, struct matchmaker *mm){
    struct girl * g = (struct girl *) self;
    int used;

    used = mm->act.express((struct action *)mm, g->patient, g->len);

    if (mm->more_info){
        mm->more_info(mm, g->patient+used, g->len-used);
    }

    printf("GIRL> %s\n", g->patient);
}

int init_girl(struct girl * g, char * patient, int len){
    g->listen = girl_listen;
    g->patient = patient;
    g->len = len;
    return 0;
}

void deinit_girl(struct girl * g){
    free(g);
}
