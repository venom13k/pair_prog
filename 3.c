#include<stdio.h>

#define MINS_IN_HOUR 60

int patients(int time1_h, int time1_m, int time2_h, int time2_m, int increment) {
  

 
  
    /*  res = ((time2_h * MINS_IN_HOUR + time2_m) - (time1_h * MINS_IN_HOUR + time1_m))%increment;
      printf("Time is %d", res);
    */
  for(; time1_h <= time2_h && time1_m <= time2_m; time1_m = time1_m + increment) {

    if(time1_m >= MINS_IN_HOUR) {
      time1_h++;
      time1_m = time1_m - MINS_IN_HOUR;
    }
    printf("%d:%d \n", time1_h, time1_m);
  } 

  return 0;
}


int main() {
  
  
  int hour_1 = 13;
  int min_1 = 0;
  int hour_2 = 15;
  int min_2 = 0;

  int min = 30; 
 
  patients(hour_1, min_1, hour_2, min_2, min);
 

  return 0;
}
