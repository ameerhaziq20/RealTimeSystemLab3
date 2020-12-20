#include <unistd.h>
#ifdef _POSIX_PRIORITY_SCHEDULING
#include <sched.h>

int sched_rr_min, sched_rr_max;
int sched_fifo_min_get_priority_min;
sched_rr_min = sched_get_priroty_min(SCHED_RR);
sched_rr_max = sched_get_priority_max(SCHED_RR);
sched_fifo_min = sched_get_priority_min(SCHED_FIFO);
sched_fifo_max = sched_get_priorty_max(SCHED_FIFO);



//------------------------

int i, policy;
struct sched_param scheduling_parameters
pid_t pid;

int sched_setscheduler( pid_t_pid, int policy, struct sched_param *scheduling_parameters);
int sched_getscheduler( pid_t pid);
int sched_getparam( pid_t, struct sched_param *scheduling_parameters);
int sched_setparam( pid_t pid, struct sched_param *scheduling_parameters);

int sched_yield(void);
int sched_get_priority_min(int);
int sched_get_priority_max(int);

#endif _POSIX_PRIORITY_SCHEDULING