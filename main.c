#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
  //testing insert_front
  song_node * t1 = (song_nude *)malloc(sizeof(song_node));
  t1 = insert_front(t1, "Biotonic", "ani");
  print_list(t1);
  return 21;
}