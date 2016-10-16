#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "list.h"

typedef struct library{
  song_node * table[26];
}library;

//'a' is 97

void addSong( library * lib, char * songName, char * artistName){
  strcpy( lowerString(artistName), artistName);
  char firstChar = artistName[0];
  if( firstChar < 97 || firstChar > 122){
    printf("INVALID artistName\n");
    return;
  }
  insert( (*lib).table[ firstChar - 97 ], songName, artistName);
}

song_node * searchSong( library * lib, char * songName){
  int i = 0;
  for(;i<26;i++){
    song_node * searchResult = findSong( (*lib).table[i], songName);
    if( searchResult != 0){
      return searchResult;
    }
  }
  printf("Song Not Found in Library\n");
  return 0;
}

song_node * searchArtist( library * lib, char * artistName ){
  strcpy( lowerString(artistName), artistName);
  char firstChar = artistName[0];
  if( firstChar < 97 || firstChar > 122){
    printf("INVALID artistName\n");
    return;
  }
  song_node * searchResult = findArtist( (*lib).table[ firstChar - 97 ], artistName );
  //return searchResult;
  if(searchResult == 0){
    printf("Artist Not Found in Library\n");
  }
  return searchResult;
  
}

