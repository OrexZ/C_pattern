#include "proxy.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a,b) ((a > b) ? (a) : (b))

static int boy_express(struct action * self, char * msg, int size){
    struct boy * _b = (struct boy *) self; 
    int used;

    if (msg == NULL || size == 0) {
        printf("E> maybe girl don't want to listen to you.");
        exit(-1);
    }

    snprintf(msg, size, "name: %s, tall: %d, work: %s\n",
                _b->info->name, _b->info->tall, _b->info->work);

    used = min(size, strlen(_b->info->name) +
            sizeof(_b->info->tall) +
            strlen(_b->info->work));

    return used;
}

static int matchmaker_express(struct action * self, char * msg, int size){
    struct matchmaker * mm = (struct matchmaker *) self;
    struct boy * bi = mm->boy_p;
    int used = 0;
    int valid_len, spare_len;
    char * more = "He is the son of the president.";

    used = bi->act.express((struct action *) bi, msg, size);

    spare_len = size - used;
    if (spare_len < strlen(more)){
        printf("D> no enough msg to send... ");
    }

    valid_len = min(spare_len, strlen(more));

    snprintf(msg+used, valid_len, "%s", more);

    return valid_len + used;
}

static int matchmaker_more_info(void * priv, char *msg, int size){
    char * competitive_info = "Other girls like this boy too";
    int used;

    used = snprintf(msg, size, "%s", competitive_info);
    return used;
}

int init_boy_info(struct boy_info * ip, char * name, int tall, char * work){
    strcpy(ip->name, name);
    ip->tall = tall;
    strcpy(ip->work, work);
    return 0;
}

int init_boy(struct boy * bp, struct boy_info * ip){
    bp->act.express = boy_express;
    bp->info = ip;
    return 0;
}

int init_matchmaker(struct matchmaker * mm, struct boy * bp){
    mm->act.express  =  matchmaker_express;
    mm->boy_p = bp;
    mm->more_info = matchmaker_more_info;
    return 0;
}

void deinit_boy_info(struct boy_info * bi){
    free(bi);
}

void deinit_boy(struct boy * b){
    free(b);
}

void deinit_matchmaker(struct matchmaker * mm){
    free(mm);
}

