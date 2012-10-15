#include<stdio.h>
#include <assert.h>


void test_memset2(){
  char i;
  char m[100];

  printf("TEST MEMSET2: ");

  // забиваем массив тестовыми данными
  // 1,2,3,4,5...100
  for (i = 0; i < 100; ++i)
    m[i] = i;

  // 1 тест
  // memset не должен тронуть массив если n = 0
  memset2(m, 5, 0);
  for (i = 0; i < 100; ++i)
    assert(m[i] == i);

  // 2 тест
  // memset должен выставить на 5 только первые 25 элементов
  // остальные не должен тронуть
  memset2(m, 5, 25);
  // проверяем первые 25 элементов
  // там должны быть пятёрки
  for (i = 0; i < 25; ++i)
    assert(m[i] == 5);
  // проверяем оставшиеся элементы
  // там должны быть старые данные
  for (i = 25; i < 100; ++i)
    assert(m[i] == i);
  printf("[ OK ]\n");
}

void memset2( char *s, char c, int n) {

int i;

for(i = 0; i < n; i++) {
      s[i] = c;

 }

}




int main() {



  test_memset2();

}
