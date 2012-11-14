#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define MINS_IN_HOUR 60
#define HOURS_IN_DAY 24

struct simple_time {
    int hour;
    int min;
  int to_min;
};

typedef struct simple_time time;  

int time_to_min(int h, int m) {
  
  return h*MINS_IN_HOUR + m;
}

char *time_to_str(int t_m, int h, int m) {
  char s[1000];
  
  h = t_m / MINS_IN_HOUR;
  m = t_m - h*MINS_IN_HOUR;

  if (h >= HOURS_IN_DAY) {
    h = h - HOURS_IN_DAY;
  }

  sprintf(s, "%d:%02d ", h, m);
  return s;
}

void std_err() {
  
    fprintf(stderr, "Error. In \"time_for_patients\" function: Incorrect time format. Correct your time \n");
    _Exit(1);

}

char *time_for_patients(time *tm_1, time *tm_2, int increment) {
  
  
  int n;
  char *str;

  if (tm_1->hour >= HOURS_IN_DAY || tm_2->hour >= HOURS_IN_DAY) {
    std_err();
  }
  else if (tm_1->hour > tm_2->hour) { 
    
    tm_2->hour = tm_2->hour + HOURS_IN_DAY;
     
  }


  n = (time_to_min(tm_2->hour, tm_2->min) - time_to_min(tm_1->hour, tm_1->min)) / increment * 7;// number of patients
  str = malloc(n * sizeof(char));
  
  for(tm_1->to_min = time_to_min(tm_1->hour, tm_1->min); tm_1->to_min <= time_to_min(tm_2->hour, tm_2->min); tm_1->to_min += increment) {
    
    str = strcat(str, time_to_str(tm_1->to_min, tm_1->hour, tm_1->min));
    
  }
  
  return str;
  free(str);
  }


void test_time_for_patients() {
  
  time t1;
  time t2;

  t1.hour = 23;
  t1.min = 59;
  t2.hour = 3;
  t2.min = 0;
  


}

int main() {
  
  time time1;
  time time2;

  time1.hour = 13;
  time1.min = 55;
  time2.hour = 23;
  time2.min = 50;

  int min = 15; 
 
  printf("%s\n", time_for_patients(&time1, &time2, min));
 

  return 0;
}
