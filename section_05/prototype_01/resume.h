#ifndef _RESUME_H_
#define _RESUME_H_

struct prototype {
    void *(* clone) (void *);
};

struct work_experience {
    struct prototype super;

    /* NOTE: deep copy */
    char work_date[30];
    char company[50];

    /* NOTE: shallow copy */
    /* char * work_date; */
    /* char * company; */

    void * priv;
};


struct resume_ops {
    void (* set_personal_info)(void * priv, char * sex, char * age);
    void (* set_work_experience)(void * priv, char * work_date, char * company);
    void (* display)(void *priv);
};


struct resume {
    struct prototype super;

    /* NOTE: deep copy */
    char name[30];
    char sex[10];
    char age[5];

    /* NOTE: shallow copy */
    /* char * name; */
    /* char * sex; */
    /* char * age; */

    struct work_experience * we;
    struct resume_ops * ops;

    void * priv;
};

#define TO_WORK_EXP_OBJ(priv) ((struct work_experience *)(priv))
#define TO_RESUME_OBJ(priv) ((struct resume *)(priv))

int init_work_exp(struct work_experience * we,
        char *work_date, char *company);
int init_resume(struct resume * r, char * name,
        char * sex, char * age,
        struct work_experience * we);


#endif
