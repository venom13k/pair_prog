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


int patients(struct time *tm_1, struct time *tm_2, int increment) {
  
  for(tm_1->in_min = time_to_min(tm_1->hour, tm_1->min); tm_1->in_min <= time_to_min(tm_2->hour, tm_2->min); tm_1->in_min += increment) {
    
    //    time_to_str(tm_1.in_min, tm_1.hour, tm_1.min);
    printf("%d \n", tm_1->in_min);
  }
	
  return 0;
}


int main() {
  
  struct time time1;
  struct time time2;

  time1.hour = 13;
  time1.min = 15;
  time2.hour = 15;
  time2.min = 59;

  int min = 30; 
 
  patients(&time1, &time2, min);
 

  return 0;
}
