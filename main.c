#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>

int main()
{
int pid_task1, pid_task2, pid_task3, pid_task4;
struct sched_param sched_task1, sched_task2, sched_task3, sched_task4;

sched_task1.sched_priority = 32;
sched_task2.sched_priority = 28;
sched_task3.sched_priority = 26;
sched_task4.sched_priority = 24;


pid_task1 = fork();

if (pid_task1 == 0)
{
	sched_setscheduler(getpid(), SCHED_FIFO, &sched_task1);
	execl("task1", "task1", "0", NULL);
}
else if (pid_task1 > 0)
{
	printf("Parent task1\n");
}
else
{
	printf("Fork Error\n");
}
pid_task2 = fork();
if (pid_task2 == 0)
{
	sched_setscheduler(getpid(), SCHED_FIFO, &sched_task2);
	execl("task2", "task2", "0", NULL);
}
else if (pid_task2 > 0)
{
	printf("Parent task2\n");
}
else
{
	printf("Fork Error\n");
}
pid_task3 = fork();
if (pid_task3 == 0)
{
	sched_setscheduler(getpid(), SCHED_FIFO, &sched_task3);
	execl("task3", "task3", "0", NULL);
}
else if (pid_task3 > 0)
{
	printf("Parent task3\n");
}
else
{
	printf("Fork Error\n");
}
	pid_task4 = fork();
if (pid_task4 == 0)
{
	sched_setscheduler(getpid(), SCHED_FIFO, &sched_task4);
	execl("task4", "task4", "0", NULL);
}
else if (pid_task4 > 0)
{
	printf("Parent task4\n");
}
else
{
	printf("Fork Error\n");
}
return 0;
}
