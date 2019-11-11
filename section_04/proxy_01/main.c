#include "proxy.h"
#include "client.h"
#include <stdlib.h>

int main(int argc, char **argv){
    struct boy_info * bi = malloc(sizeof(struct boy_info));
    struct boy * b = malloc(sizeof(struct boy));
    struct matchmaker * mm = malloc(sizeof(struct matchmaker));

    struct girl * g = malloc(sizeof(struct girl));
#define GIRL_PATIENT_SIZE 100
    char * girl_patient = malloc(GIRL_PATIENT_SIZE);

    init_girl(g, girl_patient, GIRL_PATIENT_SIZE);

    init_boy_info(bi, "Gou Dan", 185, "[ZTE] IT engineer");
    init_boy(b, bi);
    init_matchmaker(mm, b);

    g->listen(g,mm);

    deinit_boy_info(bi);
    deinit_boy(b);
    deinit_matchmaker(mm);
    deinit_girl(g);
    
    return 0;
}
