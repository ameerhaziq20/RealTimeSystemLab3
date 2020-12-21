#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>
int main()
{
int pid_T1, pid_T2, pid_T3, pid_T4, pid_T5;
struct sched_param sched_t1, sched_t2, sched_t3, sched_t4, sched_t5;

sched_t1.sched_priority = 62;
sched_t2.sched_priority = 61;
sched_t3.sched_priority = 60;
sched_t4.sched_priority = 59;
sched_t5.sched_priority = 58;
pid_T1 = fork();
if (pid_T1 == 0)
{
sched_setscheduler(getpid(), SCHED_FIFO, &sched_t1);
execl("T1", "T1", "0", NULL);
}
else if (pid_T1 > 0)
{
printf("Parent T1\n");
}
else
{
printf("Error.Fork Failed\n");
}
pid_T2 = fork();
if (pid_T2 == 0)
{
sched_setscheduler(getpid(), SCHED_FIFO, &sched_t2);
execl("T2", "T2", "0", NULL);
}
else if (pid_T2 > 0)
{
printf("Parent T2\n");
}
else
{
printf("Error.Fork Failed\n");
}
pid_T3 = fork();
if (pid_T3 == 0)
{
sched_setscheduler(getpid(), SCHED_FIFO, &sched_t3);
execl("T3", "T3", "0", NULL);
}
else if (pid_T3 > 0)
{
printf("Parent T3\n");
}
else
{
printf("Error.Fork Failed\n");
}
pid_T4 = fork();
if (pid_T4 == 0)
{
sched_setscheduler(getpid(), SCHED_FIFO, &sched_t4);
execl("T4", "T4", "0", NULL);
}
else if (pid_T4 > 0)
{
printf("Parent T4\n");
}
else
{
printf("Error.Fork Failed\n");
}
pid_T5 = fork();
if (pid_T5 == 0)
{
sched_setscheduler(getpid(), SCHED_FIFO, &sched_t5);
execl("T5", "T5", "0", NULL);
}
else if (pid_T5 > 0)
{
printf("Parent T5\n");
}
else
{
printf("Error.Fork Failed\n");
}
return 0;
}
