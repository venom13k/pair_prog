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

int time_to_min(time *t) {
  
  return (t->hour*MINS_IN_HOUR + t->min);
}

char *min_to_time(time *t) {

  char *s;
  s = malloc(7*sizeof(char));

  t->hour = t->to_min / MINS_IN_HOUR;
  t->min = t->to_min - t->hour*MINS_IN_HOUR;

  if (t->hour >= HOURS_IN_DAY) {
    t->hour = t->hour - HOURS_IN_DAY;
  }

  sprintf(s, "%d:%02d ", t->hour, t->min);
  return s;
}

void std_err() {
  
    fprintf(stderr, "Error. In \"time_for_patients\" function: Incorrect time format. Correct your time \n");
    _Exit(1);

}

char *time_for_patients(time *tm_1, time *tm_2, int increment) {
  
  
  int n;
  char *str;
  char *one_time;

  if (tm_1->hour >= HOURS_IN_DAY || tm_2->hour >= HOURS_IN_DAY) {
    std_err();
  }
  else if (tm_1->hour > tm_2->hour) { 
    
    tm_2->hour = tm_2->hour + HOURS_IN_DAY;
     
  }


  n = (time_to_min(tm_2) - time_to_min(tm_1)) / increment * 7;// number of patients

  str = malloc(n * sizeof(char));
  
  for(tm_1->to_min = time_to_min(tm_1); tm_1->to_min <= time_to_min(tm_2); tm_1->to_min += increment) {
    
    one_time = min_to_time(tm_1);
    str = strcat(str, one_time);
    free(one_time);
  }

  return str;
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
  
  char *s;

  time1.hour = 23;
  time1.min = 55;
  time2.hour = 13;
  time2.min = 50;

  int min = 15;
  
  s = time_for_patients(&time1, &time2, min);
  printf("%s\n", s);
  free(s);

  return 0;
}
