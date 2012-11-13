#include<stdio.h>

#define MINS_IN_HOUR 60

struct simple_time {
    int hour;
    int min;
    int to_min;
    char str;
};

typedef struct simple_time time;  

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


int patients(time *tm_1, time *tm_2, int increment) {
  
  char *s;

  for(tm_1->to_min = time_to_min(tm_1->hour, tm_1->min); tm_1->to_min <= time_to_min(tm_2->hour, tm_2->min); tm_1->to_min += increment) {
    
    //    s = time_to_str(tm_1->to_min, tm_1->hour, tm_1->min);
    printf("%d \n", tm_1->to_min);
  }
	
  return 0;
}


int main() {
  
  time time1;
  time time2;

  time1.hour = 13;
  time1.min = 15;
  time2.hour = 15;
  time2.min = 59;

  int min = 30; 
 
  patients(&time1, &time2, min);
 

  return 0;
}
