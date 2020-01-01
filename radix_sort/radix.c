#include "digit.h"

int main() {
  int n;
  int enough = 1;
  int incrementing_szamjegyek = 1;

  printf("The array length will be: ");
  scanf("%d", &n);

  int *arr = calloc(n, sizeof(int));
  int *sorted_arr = calloc(n, sizeof(int));
  int *d_arr = calloc(n, sizeof(int));
  int *d_counter = calloc(10, sizeof(int));

  printf("-----------------------------\n");
  printf("The original array is:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  while (enough) {

    for (int i = 0; i < n; i++) {
      d_arr[i] = getDigit(arr[i], incrementing_szamjegyek);
    }

    for (int i = 0; i < 10; i++) {
      d_counter[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      d_counter[d_arr[i]]++;
    }

    for (int i = 1; i < 10; i++) {
      d_counter[i] = d_counter[i - 1] + d_counter[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      sorted_arr[--d_counter[d_arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
      arr[i] = sorted_arr[i];
    }

    enough = 0;

    incrementing_szamjegyek++;

    for (int i = 0; i < n; i++) {
      if (hasMinDigits(arr[i], incrementing_szamjegyek)) {
        enough = 1;
      }
    }
  }

  printf("The sorted array is:\n");

  for (int i = 0; i < n; i++) {
    printf("%d\n", sorted_arr[i]);
  }

  free(arr);
  free(sorted_arr);
  free(d_arr);
  free(d_counter);

  return 0;
}