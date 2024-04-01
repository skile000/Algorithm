#include <stdio.h>
#include <stdlib.h>

int leak[1001];
int tape[1001];

int compare(const void *a, const void *b) {
  int num1 = *(int *)a;
  int num2 = *(int *)b;
  if (num1 < num2)
    return -1;
  if (num1 > num2)
    return 1;
  return 0;
}

int main() {
  int N, L;
  int cnd = 0;
  scanf("%d %d", &N, &L);
  for (int a = 0; a < N; a++) {
    scanf("%d", &leak[a]);
  }
  qsort(leak, N, 4, compare);
  for (int a = 0; a < N; a++) {
    if (tape[leak[a]] == 0) {
      for (int b = 0; b < L; b++)
        tape[leak[a] + b] = 1;
      cnd++;
    }
  }
  printf("%d\n", cnd);
}