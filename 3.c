#include<stdio.h>
#include<time.h>

int patients()


int main() {

  int res;
  struct tm time1;
  struct tm time2;

  time1.tm_year = 2012 - 1900;
  time1.tm_mon = 6;
  time1.tm_mday = 5;
  time1.tm_hour = 12;
  time1.tm_min = 30;
  time1.tm_sec = 0;

  time2.tm_year = 2012 - 1900;
  time2.tm_mon = 6;
  time2.tm_mday = 5;
  time2.tm_hour = 16;
  time2.tm_min = 30;
  time2.tm_sec = 0;
  
  res = ((mktime(&time2) - mktime(&time1))/60)%increment;
  printf("Time is %d", res);


  return 0;
}
