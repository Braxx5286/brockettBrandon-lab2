#include <sys/time.h>

double elapsed_time(struct timeval* start_time, struct timeval* end_time){
    double startsec = (start_time->tv_sec * 1000000.0)  + start_time->tv_usec, 
    endsec = (end_time->tv_sec * 1000000.0) + end_time->tv_usec;
    return (endsec - startsec) / 1000000.0;
    

}