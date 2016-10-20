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
  }else{
    //printf("Pointer to first Node:[%p]\n",(*lib).table[firstChar-97]);
    (*lib).table[firstChar - 97] = insert( (*lib).table[firstChar - 97], songName, artistName);
    //print_list( result);
    //print_list( (*lib).table[firstChar - 97] );
  }
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
  //printf("Start\n");
  //printf("ArtistName:[%s]\n",artistName);
  artistName = strcpy( artistName, lowerString(artistName) );//breaking here for some reason?
  //printf("First\n");
  char firstChar = artistName[0];
  //printf("Second\n");
  if( firstChar < 97 || firstChar > 122){
    printf("INVALID artistName[%s]\n",artistName);
  }else{
    //printf("Breakpoint\n");
    song_node * searchResult = findArtist( (*lib).table[ firstChar - 97 ], artistName );
  //returns searchResult;
    if(searchResult == 0){
      printf("Artist Not Found in Library\n");
    }
    return searchResult;
  }
}

void printLetter( library * lib, char letter ){
  if( letter < 97 || letter > 122){
    printf("INVALID letter[%c]\n",letter);
  }else{
    print_list( (*lib).table[ letter - 97 ]);
  }
}

void printArtist( library * lib, char * artistName ){
  //printf("breakpoint\n");
  song_node * searchResult = searchArtist( lib, artistName );
  //print_list(searchResult);
  if( searchResult == 0 ){
    return;//error statement in previous part.
  }else{
    printf("Songs by %s:\n",artistName);
    while( searchResult != 0 && strcmp( (*searchResult).artist, artistName ) == 0){
      printf("\t[%s],\n", (*searchResult).name );
      searchResult = (*searchResult).next;
    }
  }
}

void printLibrary( library * lib ){
  char l = 97;
  for(;l<123;l++){
    if( (*lib).table[l-97] != 0){
      printf("Letter '%c' List:\n",l);
      printLetter( lib, l);
    }
  }
}

//NOTE: May come back to this to make it more random.
void shuffleList( library * lib ){
  int i =0;
  printf("Beginning of Random Songs:");
  for(;i<26;i++){
    song_node * rndNode = randomNode( (*lib).table[ i ]);
    if( rndNode != 0) {
      printf("\t[%s] by %s\n", (*rndNode).name, (*rndNode).artist);
    }
  }
}

void deleteSong( library * lib, char * songName, char * artistName){
  int i = 0;
  for(;i<26;i++){
    //printf("Issue with letter: %c\n", i + 97);
    if( (*lib).table[i] != 0 ){
      song_node * temp = removeSong( (*lib).table[i], songName, artistName);
      //print_list(temp);
      (*lib).table[i] = temp;
    }
  }
  //printf("Completion\n");
}

void deleteLibrary( library * lib ){
  int i =0;
  for(;i<26;i++){
    freeNodes( (*lib).table[i] );
  }
}
