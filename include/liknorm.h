#ifndef LIKNORM_H
#define LIKNORM_H

typedef void log_partition (double  theta,
                            double *b0,
                            double *logb1,
                            double *b1_sign,
                            double *logb2,
                            double *b2_sign);

typedef struct
{
        double y;
        double aphi;
        double aphi_sign;
        log_partition* lp;
        double left;
        double right;
} ExpFam;

typedef struct
{
        double eta;
        double tau;
} Normal;

typedef struct
{
        double *log_zeroth;
        double *u;
        double *v;
        int n;
        double precision;
} LikNormMachine;

LikNormMachine* create_liknorm_machine(int n, double precision);
void destroy_liknorm_machine(LikNormMachine* machine);
void integrate(LikNormMachine *machine, ExpFam ef, Normal normal,
               double* mean, double *variance);
log_partition* get_log_partition(char *name);
void get_interval(char *name, double* left, double* right);

#endif /* ifndef LIKNORM_H */
