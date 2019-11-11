#ifndef _PROXY_H_
#define _PROXY_H_

struct action {
    int (* express)(struct action * self, char * msg, int size);
};

struct boy_info {
    char name[20];
    int  tall;
    char work[30];
};

struct boy {
    struct action act;
    struct boy_info * info;
};

struct matchmaker {
    struct action act;
    struct boy * boy_p;
    int (* more_info) (void * priv, char * msg, int size);
};

int init_boy_info(struct boy_info * ip, char * name, int tall, char * work);
int init_boy(struct boy * bp, struct boy_info * ip);
int init_matchmaker(struct matchmaker * mm, struct boy * bp);

void deinit_boy_info(struct boy_info * bi);
void deinit_boy(struct boy * b);
void deinit_matchmaker(struct matchmaker * mm);

#endif
