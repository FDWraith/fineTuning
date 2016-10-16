#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

char * lowerString(char * str){
  int i = 0;
  for(;i<strlen(str);i++){
    str[i] = toLower(str[i]);
  }
  return str;
}

song_node * insert_front( song_node *current, char *n, char *art){
  n = lowerString(n);
  art = lowerString(art);
  song_node * newNode = (song_node *)malloc( sizeof(song_node) );
  //(*newNode).name = *n;
  strcpy( (*newNode).name, n);
  //(*newNode).artist = *art;
  strcpy( (*newNode).artist, art);
  (*newNode).next = current;
  return newNode;
}

song_node * insert( song_node *current, char *n, char *art){
  n = lowerString(n);
  art = lowerString(art);
  song_node * newNode = (song_node *)malloc( sizeof(song_node) );
  //(*newNode).name = *n;
  strcpy( (*newNode).name, n);
  //(*newNode).artist = *art;
  strcpy( (*newNode).artist, art);
  song_node * frs = current;
  while( strcmr( (*current).artist, (*newNode).artist ) <= 0 ){
    current = (*current).next;
  }
  song_node * temp = (*current).next;
  (*current).next = newNode;
  (*newNode).next = temp;
  return frs;
}

void print_list( song_node * head){
  printf("Begin: ");
  while(head != 0){
    printf("[%s] by %s;", (*head).name, (*head).artist);
    head = (*head).next;
  }
  printf(":End\n");
}

song_node * findSong( song_node * head, char * songName){
  songName = lowerString(songName);
  while( head != 0){
    if( strcmr( songName, (*head).name ) == 0){
      return head;
    }else{
      head = (*head).next;
    }
  }
  printf("Song Not Found\n");
  return 0;//Cannot be found.
}

song_node * findArtist( song_node * head, char * artistName ){
  artistName = lowerString(artistName);
  while( head != 0){
    if( strcmr( artistName, (*head).artist ) == 0){
      return head;
    }else{
      head = (*head).next;
    }
  }
  printf("Artist Not Found\n");
  return 0;
}

int listLength( song_node * head){
  int n = 0;
  while( head != 0){
    n++;
    head = (*head).next;
  }
  return n;
} 

song_node * randomNode( song_node * head){
  int len = listLength(head);
  int r = (int)(rand()) * len;
  while( r != 0 && head != 0){
    r--;
    head = (*head).next;
  }//while loop ends, r must be 0

  if(head == 0){
    printf("You have an error on your hands\n");
    return 0;
  }else{
    return head;
  }
}

void removeNode( song_node * chosen ){
  //not sure how to do this one.
}

song_node * removeSong( song_node * head, char * songName ){
  if( head == 0){
    printf("You're in the wrong neighborhood, kid\n");
    return 0;
  }else{
    songName = lowerString(songName);
    if( strcmr( (*((*head).next)).name, songName) == 0 ){
      song_node temp = (*head).next;
      (*head).next = (*temp).next;
      return temp;
    }else{
      return removeSong( (*head).next, songName );
    }
  }
}

song_node * freeNodes( song_node * head ){
  if( head != 0){
    free(head);
    head = freeNodes( (*head).next );
  }else{
    free(head);
  }
  return head;
}

