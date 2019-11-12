#include "resume.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv){
    struct resume * r, *another, *once_more;
    struct work_experience * we;

    /* char my_name[20] = "rex_zheng"; */
    /* char my_sex[10] = "boy"; */
    /* char my_age[3] = "28"; */

    /* char my_work_date[20] = "2015-2019"; */
    /* char my_company_name[30] = "Sierra Wireless"; */

    we = malloc(sizeof(*we));

    if (we == NULL){
        printf("E> no mem, for we");
        goto FREE;
    }
    
    r = malloc(sizeof(*r));

    if (r == NULL){
        printf("E> no mem, for resume");
        goto FREE;
    }

    /* init_work_exp(we, my_work_date, my_company_name); */
    /* init_resume(r, my_name, my_sex, my_age, we); */

    init_work_exp(we, "2010-2020", "TCL mobile");
    init_resume(r, "rex_zheng", "man", "28", we);

    r->ops->display(r);

    another = r->super.clone(r);

    another->ops->set_personal_info(another, "girl", "38");
    another->ops->display(another);

    once_more = r->super.clone(r);
    once_more->ops->set_work_experience(once_more, "2000-2020", "Google");
    once_more->ops->display(once_more);
    r->ops->display(r);
    
    free(another);
    free(once_more);

FREE:
    free(we);
    free(r);

    return 0;
}
