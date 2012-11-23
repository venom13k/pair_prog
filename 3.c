#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define MINS_IN_HOUR 60
#define HOURS_IN_DAY 24

struct simple_time {
    int hour;
    int min;
};

typedef struct simple_time time;  

void input_time(time *t) {

  int h, m, ret;
  do {
    scanf("%d:%d", &h, &m);
    ret = make_time(h, m, t);
    if (!ret) {
      printf("Incorrect time format. Correct your time \n");
   }
  } while (ret != 1);
}

int make_time(int h, int m, time *t) {
  
  if (h >= HOURS_IN_DAY || h < 0 || m >= MINS_IN_HOUR || m < 0) {
    return 0;
  }
  else {
    t->hour = h;
    t->min = m;
 
    return 1;
  }
}



int time_to_min(time *t) {
  
  return (t->hour*MINS_IN_HOUR + t->min);
}

time min_to_time(int m) {

  time t;

  t.hour = m / MINS_IN_HOUR;
  t.min = m % MINS_IN_HOUR;

  printf("Time: %02d:%02d\n", t.hour, t.min);
  
  return t;
}

time  *time_for_patients(time *tm_1, time *tm_2, int increment) {
  
  time *tm;
  int i, n;

  int minutes;

  n = (time_to_min(tm_2) - time_to_min(tm_1)) / increment; // number of patients
  tm = malloc(n * sizeof(time));

  tm[0] = *tm_1;
  minutes = time_to_min(tm);
  printf("tm_1:%d  tm_2:%d \n", time_to_min(tm_1), time_to_min(tm_2));
  for( i = 0; i <= n; i++) {
    
    printf("%d:%d %d\n", tm[i].hour, tm[i].min, minutes);
    tm[i] = min_to_time(minutes);
    minutes += increment;
  }

  return tm;
  }


int main() {
  
  time time1;
  time time2;
  time *time;

  printf("Input the first time: ");

  input_time(&time1);
  printf("Input the second time:");
  input_time(&time2);
  
  printf("%d:%d\n%d:%d\n", time1.hour, time1.min, time2.hour, time2.min);
  time = time_for_patients(&time1, &time2, 15);

  return 0;
}
