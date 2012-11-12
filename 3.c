#include<stdio.h>

#define MINS_IN_HOUR 60

  struct time {
    int hour;
    int min;
    int in_min;
    char str;
  };

int time_to_min(int h, int m) {
  
  return h*MINS_IN_HOUR + m;
}

char *time_to_str(int i_m, int h, int m) {
  char *s = '\0';
  
  h = i_m % MINS_IN_HOUR;
  m = i_m - h*MINS_IN_HOUR;

  sprintf(s, "%d:%d", h, m);
  return s;
}


int patients(int time1_h, int time1_m, int time2_h, int time2_m, int increment) {
  
  
  struct time tm_1;
  struct time tm_2;
  

  tm_1.hour = time1_h;
  tm_1.min = time1_m;
  tm_2.hour = time2_h;
  tm_2.min = time2_m;

  for(tm_1.in_min = time_to_min(tm_1.hour, tm_1.min); tm_1.in_min <= time_to_min(tm_2.hour, tm_2.min); tm_1.in_min += increment) {
    
    time_to_str(tm_1.in_min, tm_1.hour, tm_1.min);
    printf("%s \n", str);
  }
	
  return 0;
}


int main() {
  
  
  int hour_1 = 13;
  int min_1 = 15;
  int hour_2 = 15;
  int min_2 = 59;

  int min = 30; 
 
  patients(hour_1, min_1, hour_2, min_2, min);
 

  return 0;
}
