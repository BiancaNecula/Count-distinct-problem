// Copyright 2020 Necula Bianca

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Functie pentru aflarea maximului dintre 2 elemente.
int maxim(int num1, int num2) { return (num1 > num2) ? num1 : num2; }

// Functie pentru detreminarea numarului de biti 0 la inceputul unui numar int.
unsigned int leading_zero(int x) {
  unsigned int nr = 0;
  const unsigned bits = sizeof(x) * 8;
  for (unsigned int i = 1; i < bits; i++) {
    if (x < 0) break;
    nr++;
    x <<= 1;
  }
  return nr;
}
// Functie de hashing pentru int.
unsigned int hash_function_int(void *a) {
  unsigned int uint_a = *((unsigned int *)a);

  uint_a = ((uint_a >> 16u) ^ uint_a) * 0x45d9f3b;
  uint_a = ((uint_a >> 16u) ^ uint_a) * 0x45d9f3b;
  uint_a = (uint_a >> 16u) ^ uint_a;
  return uint_a;
}

int main(int argc, char *argv[]) {
  // daca parametrii dati in linia de comanda sunt diferiti de 2 se opreste
  // executia.
  if (argc != 2) {
    return 0;
  }
  // declarare si initializare variabile
  int m = 2048;
  double sum = 0, Z = 0;
  int M[2048] = {0};
  int nr = 0;
  unsigned int hashnr = 0, j = 0, x = 0, n = 0, E = 0;
  // se deschide fisierul de intrare si se citesc numere pana la sfarsitul
  // acestuia
  FILE *in = fopen(argv[1], "r");
  while (!feof(in)) {
    fscanf(in, "%d ", &nr);
    // se aplica functia de hash pe fiecare numar
    hashnr = hash_function_int(&nr);
    // se extrag primii 11 biti din numar
    j = hashnr >> 21;
    // se extrag ultimii biti si se numara primii biti egali cu 0
    hashnr = hashnr << 11;
    x = leading_zero(hashnr);
    // in vectorul M se memoreaza cea mai mare valoare inscrisa a numarului de
    // biti 0
    M[j] = maxim(M[j], x);
  }

  // se calculeaza media armonica a puterilor lui 2 cu exponentul egal cu
  // valorile din vectorul M
  for (int i = 0; i < m; i++) {
    n = 1 << M[i];
    sum += (1 / (double)n);
  }
  Z = 1. / (double)sum;
  // se calculeaza solutia  cu ajutorul formulei
  E = 0.7209 * m * m * Z * 2;
  printf("%d\n", E);
  fclose(in);
  return 0;
}
