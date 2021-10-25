// Copyright 2020 Necula Bianca

#include <stdio.h>
#include <stdlib.h>
#define NMAX 2000001
int main() {
  // declarare si initializare vector de frecventa
  int *freq_array, nr = 0;
  freq_array = calloc(NMAX, sizeof(int));
  // se citesc toate numerele pana la sfarsitul fisierului si se creste valoarea
  // memorata la indexul respectiv
  while (!feof(stdin)) {
    scanf("%d ", &nr);
    freq_array[nr]++;
  }
  // se afiseaza la stdout numarul de aparitii
  for (int i = 0; i < NMAX; i++) {
    if (freq_array[i] != 0) {
      printf("%d %d", i, freq_array[i]);
      printf("\n");
    }
  }
  free(freq_array);
  return 0;
}

