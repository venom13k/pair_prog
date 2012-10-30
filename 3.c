#include<stdio.h>
#include<time.h>

int patients(int *yy, int *mm, int *dd, int *hh1,  int *m1, int *s1, int *hh2, int *m2, int *s2, long int *reception) {
 
  
  struct tm time1;
  struct tm time2;

  time1.tm_year = yy - 1900;
  time1.tm_mon = mm;
  time1.tm_mday = dd;
  time1.tm_hour = hh1;
  time1.tm_min = m1;
  time1.tm_sec = s1;

  time2.tm_year = yy - 1900;
  time2.tm_mon = mm;
  time2.tm_mday = dd;
  time2.tm_hour = hh2;
  time2.tm_min = m2;
  time2.tm_sec =s2;
  
  res = ((mktime(&time2) - mktime(&time1))/60)%reception; 

  return res;
}


int main() {
  
  int result;
  int year, month, day, hour1, hour2, min1, min2, sec1, sec2;
  long int min;
  year = 2012;
  month = 6;
  day = 5;
  hour1 = 12;
  min1 = 30;
  sec1 = 0;
  hour2 = 16;
  min2 = 30;
  sec2 = 0;
  
  min = 30;

    result = patients(year, month, day, hour1, min1, sec1, hour2, min2, sec2, min);
  printf("Number of patients %d", result);


  return 0;
}
