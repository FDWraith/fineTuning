#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

char * lowerString(char * str){
  int i = 0;
  for(;i<strlen(str);i++){
    str[i] = tolower(str[i]);
  }
  return str;
}

song_node * insert_front( song_node *current, char *n, char *art){
  strcpy(lowerString(n), n);
  strcpy(lowerString(art), art);
  song_node * newNode = (song_node *)calloc(1, sizeof(song_node) );
  //(*newNode).name = *n;
  strcpy( (*newNode).name, n);
  //(*newNode).artist = *art;
  strcpy( (*newNode).artist, art);
  (*newNode).next = current;
  return newNode;
}

song_node * insert( song_node *current, char *n, char *art){
  strcpy(lowerString(n), n);
  strcpy(lowerString(art), art);
  song_node * newNode = (song_node *)calloc(1, sizeof(song_node) );
  //(*newNode).name = *n;
  strcpy( (*newNode).name, n);
  //(*newNode).artist = *art;
  strcpy( (*newNode).artist, art);
  if(current == 0){
    return newNode;
  }
  song_node * frs = current;
  while( (*current).next && strcmp( (*current).artist, (*newNode).artist ) <= 0 ){
    current = (*current).next;
  }
  
  if( (*current).next && strcmp( (*current).artist, (*newNode).artist ) == 0){
    while( (*current).next && strcmp( (*current).name, (*newNode).name) <= 0 ){
      current = (*current).next;
    }
  }
  if(current){
    song_node * temp = (*current).next;
    (*current).next = newNode;
    (*newNode).next = temp;
  }else{
    (*current).next = newNode;
  }
  return frs;
}

void print_list( song_node * head){
  printf("List of Songs:\n");
  while(head){
    printf("\t[%s] by %s,\n", (*head).name, (*head).artist);
    //printf("Next:[%p]\n",(*head).next);
    head = (*head).next;
    //printf("hi%lu\n", head);
  }
  
}

song_node * findSong( song_node * head, char * songName){
  strcpy( lowerString(songName), songName);
  while( head != 0){
    if( strcmp( songName, (*head).name ) == 0){
      return head;
    }else{
      head = (*head).next;
    }
  }
  printf("Song Not Found in List\n");
  return 0;//Cannot be found.
}

song_node * findArtist( song_node * head, char * artistName ){
  strcpy( lowerString(artistName), artistName);
  while( head != 0){
    if( strcmp( artistName, (*head).artist ) == 0){
      return head;
    }else{
      head = (*head).next;
    }
  }
  printf("Artist Not Found in List\n");
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
  //sranddev();
  srand(time(NULL));
  int r = (int)(rand() % len);
  //  int r = (int)(rand() % len);
  //printf("R is:[%d]\n",r);
  //printf("Len is [%d]\n",len);
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

song_node * removeSong( song_node * head, char * songName, char * artistName ){
  if( head == 0){
    //printf("You're in the wrong neighborhood, kid\n");
    return 0;
  }else{
    strcpy(lowerString(songName), songName);
    strcpy(lowerString(artistName), artistName);
    if( (*head).next == 0){
      if( (strcmp( (*head).name, songName) == 0) && (strcmp( (*head).artist, artistName) == 0 ) ){
        song_node * temp = head;
        head = 0;
        return temp;
      }else{
        return 0;
      }
    }else{
      if( (strcmp( (*((*head).next)).name, songName) == 0) && (strcmp( (*(*head).next).artist, artistName) == 0 ) ){
        song_node *temp = (*head).next;
        (*head).next = (*temp).next;
        return temp;
      }else{
        return removeSong( (*head).next, songName, artistName );
      }
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

