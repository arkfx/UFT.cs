#include "TCircList.h"
#include <stdio.h>
int main(void) {
  TCircList *list = TCircList_create();
  for (int i = 0; i < 10; i++)
    if (!TCircList_insert(list, i + 1))
      printf("Erro ao inserir o valor %d\n", i + 1);
  TCircList_print(list);
  return 0;
}