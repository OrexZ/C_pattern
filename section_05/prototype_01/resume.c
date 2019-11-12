#include "resume.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void * work_exp_clone(void * priv){
    struct work_experience * we = TO_WORK_EXP_OBJ(priv);
    struct work_experience * _copy = malloc(sizeof(*we));

    if (_copy == NULL){
        printf("E> NO MEMORY for clone work_exp.");
    } else {
        memmove(_copy, we, sizeof(*we));
        _copy->priv = _copy; /* NOTE: must ref yourself ! */
    }

    return _copy;
}


static void * resume_clone(void * priv){
    struct resume * r = TO_RESUME_OBJ(priv);
    struct resume * _copy;
    struct work_experience * _work_copy;

    _copy = malloc(sizeof(*r));
    if (_copy == NULL){
        printf("E> NO MEMORY for clone resume obj.");
        return _copy;
    } else {
        memmove(_copy, r, sizeof(*r));
    }

    _work_copy = r->we->super.clone(r->we);

    _copy->we = _work_copy;
    _copy->priv = _copy; /* NOTE: must ref yourself ! */

    return _copy;
}


static void r_set_personal_info (void * priv, char *sex, char *age){
    struct resume * r = TO_RESUME_OBJ(priv);
    strcpy(r->sex, sex);
    strcpy(r->age, age);
}


static void r_set_work_experience(void * priv, char *work_date, char *company){
    struct resume * r = TO_RESUME_OBJ(priv);
    strcpy(r->we->work_date, work_date);
    strcpy(r->we->company, company);
}

static void r_display(void *priv){
    struct resume * r = TO_RESUME_OBJ(priv);
    printf("[RESUME SHOW]\nSELF> name: %s, sex: %s, age: %s\nWORK> %s %s\n",
            r->name, r->sex, r->age,
            r->we->work_date, r->we->company);
}

static struct resume_ops _r_ops = {
    .set_personal_info = r_set_personal_info,
    .set_work_experience = r_set_work_experience,
    .display = r_display,
};


int init_work_exp(struct work_experience * we, char *work_date, char *company){
    strcpy(we->work_date, work_date);
    strcpy(we->company,  company);

    we->super.clone = work_exp_clone;
    we->priv = we;
    return 0;
}


int init_resume(struct resume * r, char * name, char * sex, char * age,
        struct work_experience * we){
    strcpy(r->name, name);
    strcpy(r->sex, sex);
    strcpy(r->age, age);

    r->we = we; // we == NULL or object.
    
    r->super.clone = resume_clone;
    r->ops = &_r_ops;    
    r->priv = r;

    return 0;
}

