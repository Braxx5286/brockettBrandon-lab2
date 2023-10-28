#include <sys/time.h>

double elapsed_time(struct timeval* start_time, struct timeval* end_time){
     double startsec = start_time->tv_sec + (start_time->tv_usec / 1000000), 
    endsec = end_time->tv_sec + (end_time->tv_usec / 1000000);
    return endsec - startsec;
    

}