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
    ret = make_time(h, m, &t);
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

time *min_to_time(time *t) {

  t->hour = (t->hour*MINS_IN_HOUR + t->min) / MINS_IN_HOUR;
  t->min = (t->hour*MINS_IN_HOUR + t->min) - t->hour*MINS_IN_HOUR;

  if (t->hour >= HOURS_IN_DAY) {
    t->hour = t->hour - HOURS_IN_DAY;
  }

  return t;
}

void std_err() {
  
    fprintf(stderr, "Error. In \"time_for_patients\" function: Incorrect time format. Correct your time \n");
    _Exit(1);

}

time  *time_for_patients(time *tm_1, time *tm_2, int increment) {
  


  return 0;
  }

/*
void test_time_for_patients() {
  
  time t1;
  time t2;

  t1.hour = 23;
  t1.min = 59;
  t2.hour = 3;
  t2.min = 0;
  


}
*/

int main() {
  
  time time1;
  time time2;
  
  printf("Input the first time: ");
  input_time(&time1);
  printf("Input the second time:");
  input_time(&time2);


  printf("%d:%d\n %d:%d\n", time1.hour, time1.min, time2.hour, time2.min);
 

  return 0;
}
