// Copyright 2020 Necula Bianca

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structura pt un item din hashtable key-value
// valoarea este reprezentata chiar de frecventa aparitiilor
struct item {
  int freq;
  char key[100];
};
// structura hashtable
// flag este folosit pentru a identifica daca elementul a aparut cel putin o
// data
struct ht_item {
  int flag;
  struct item *data;
};
// functie de hashing pentru stringuri
unsigned int string_hash(void *str) {
  unsigned int result = 5381;
  unsigned char *p;

  p = (unsigned char *)str;

  while (*p != '\0') {
    result = (result << 5) + result + *p;
    ++p;
  }

  return result;
}
// Functie pentru a insera un item nou in hashtable.
// Pentru un orice string nou, se creeaza un item nou, se insereaza in hashtable
// la valoarea indexului creat de functia de hash si se schimba flag-ul la
// valoarea 1.
// Daca la indexul respectiv se afla alt element se incearca pe pozitiile
// urmatoare.
// Daca toate pozitiile pana la capat sunt ocupate, se continua cu indexul 0.
// Daca elementul deja exista atunci se creste valoarea retinuta (frecventa) cu
// 1.
void insert_ht(struct ht_item *array, char *str, unsigned int index) {
  struct item *new_item = (struct item *)calloc(1, sizeof(struct item));
  snprintf(new_item->key, sizeof(new_item->key), "%s", str);
  new_item->freq = 1;
  while (array[index].flag == 1) {
    if (!strcmp(array[index].data->key, str)) {
      array[index].data->freq++;
      free(new_item);
      return;
    }
    index = (index + 1) % 30;
  }
  array[index].flag = 1;
  array[index].data = new_item;
}

// Functie pentru afisarea stringurilor si frecventele acestora.
void display(struct ht_item *array) {
  struct item *curr = NULL;
  for (int i = 0; i < 30; i++) {
    curr = (struct item *)array[i].data;
    if (curr == NULL) {
      continue;
    } else {
      printf("%s %d\n", curr->key, curr->freq);
    }
  }
}

// Functie pentru eliberarea memoriei hashtable-ului.
void free_ht(struct ht_item *array) {
  struct item *curr = NULL;
  for (int i = 0; i < 30; i++) {
    curr = array[i].data;
    if (curr == NULL) {
      continue;
    } else {
      free(curr);
    }
  }
  free(array);
}
int main() {
  // declarare si initializare variabile
  struct ht_item *array;
  char str[100];
  unsigned int indx = 0;
  array = (struct ht_item *)calloc(30, sizeof(struct ht_item));
  // se citesc stringurile pana la sfarsitul fisierului
  while (!feof(stdin)) {
    scanf("%s ", str);
    // se aplica functia de hashing pe fiecare string si se insereaza in
    // hashtable
    indx = string_hash(str);
    indx = indx % 30;
    insert_ht(array, str, indx);
  }
  display(array);
  free_ht(array);
  return 0;
}
