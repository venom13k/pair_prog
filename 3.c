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

time timecat(time *t1, time *t2) {
  time t;

  t = min_to_time(time_to_min(t1) + time_to_min(t2));

  return t;
}

int timecmp(time *t1, time *t2) {
  
  if (time_to_min(t1) > time_to_min(t2)) {
      return 1;
    }
  else if(time_to_min(t1) < time_to_min(t2)) {
    return -1;    
  }
  else {
    return 0;
  }
}

time *time_for_patients(time *t1, time *t2, int increment) {
  
  time *t;
  int i, n;

  int minutes;

  n = (time_to_min(t2) - time_to_min(t1)) / increment; // number of patients
  t = malloc(n * sizeof(time));

  t[0] = *t1;
  minutes = time_to_min(t);

  printf("t1:%d  tm_2:%d \n", time_to_min(t1), time_to_min(t2));

  for( i = 0; minutes <= time_to_min(t2); i++) {
    t[i] = min_to_time(minutes);
    //    printf(" %02d:%02d; min: %d\n", t[i].hour, t[i].min, minutes);
    minutes += increment;
  }

    return t;
  }


int main() {
  
  time time1;
  time time2;
  time *time;
  int n, i;

  printf("Input the first time: ");
  n = (time_to_min(&time1) - time_to_min(&time2)) / 15; // number of patients
  input_time(&time1);
  printf("Input the second time:");
  input_time(&time2);
  
  time = time_for_patients(&time1, &time2, 15);

  for( i = 0; i < n ; i++) {
    printf(" %02d:%02d \n", time[i].hour, time[i].min);
  }


  return 0;
}
