#include <stdio.h>
#include <time.h>
void getTimeByC(char s[]) {
	time_t _time;
	struct tm* p;
	time(&_time);
	p = localtime(&_time);
	sprintf(s,"%d-%d-%d %d:%d:%d",
	        p->tm_year + 1900,
	        p->tm_mon + 1,
	        p->tm_mday,
	        p->tm_hour,
	        p->tm_min,
	        p->tm_sec);
}


