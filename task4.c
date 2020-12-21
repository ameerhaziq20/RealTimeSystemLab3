#define _POSIX_C_SOURCE 199309L //200809L
#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <signal.h>

timer_t gTimerid;
void start_timer(void)
{

    struct itimerspec value;
    value.it_value.tv_sec = 2;
    value.it_value.tv_nsec = 0;
    value.it_interval.tv_sec = 8;
    value.it_interval.tv_nsec = 0;

    timer_create (CLOCK_REALTIME,NULL,&gTimerid);
    timer_settime(gTimerid,0,&value, NULL);
    
}

void timer_callback(int sig)
{

    executioninAction();
    (void) signal(SIGALRM, timer_callback);

}

int main(int ac, char**av)
{

    (void)signal(SIGALRM, timer_callback);
    start_timer();
    while(1);

}

//Task 4

void executioninAction(void)
{

    int i;
    long long ns; //milliseconds
    time_t s; //seconds
    struct timespec tstart, tend;

    clock_gettime(CLOCK_REALTIME,&tstart);
    usleep(4000); //4ms. in reality usleep is blocking so it goes to wait state instead of run so not good.
    clock_gettime(CLOCK_REALTIME,&tend);

    printf("Task 4: pid %d",getpid());
    printf("Executed for: %ld ns \n",
    (
    
        ((int64_t)tend.tv_sec * 1000000000)
        + (int64_t)tend.tv_nsec
        - ((int64_t)tend.tv_sec * 1000000000 
        + (int64_t)tstart.tv_nsec))
        
    );
}

//Task 4 end



