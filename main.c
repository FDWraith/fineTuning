#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
  //testing insert_front
  char s1[256], s2[256], s3[256], s4[256], a1[256], a2[256], a3[256], a4[256];
  strcpy(s1, "Shards of Light");
  strcpy(s2, "Fluquor");
  strcpy(s3, "Alive");
  strcpy(s4, "Biotonic");
  strcpy(a1, "Arn Andersson");
  strcpy(a2, "Onoken");
  strcpy(a3, "Philip Lober");
  strcpy(a4, "Ani");

  //strcpy(t1->name, s1);
  //strcpy(t1->artist, a1);
  song_node * t1 = insert_front(0, s1, a1);
  t1 = insert_front(t1, s2, a2);
  t1 = insert_front(t1, s3, a3);
  print_list(t1);
  printf("print t1 complete\n");
  //testing insert
  printf("Testing Insert\n");
  t1 = insert(t1, s3, a3);
  print_list(t1);
  t1 = insert(t1, s4, a4);
  print_list(t1);

  //testing 

  //testing

  return 21;
}
