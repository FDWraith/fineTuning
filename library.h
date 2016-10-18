#include "list.h"

typedef struct library{
  song_node * table[26];
} library;
void addSong( library * lib, char * songName, char * artistName);//adds a song to the library.
song_node * searchSong( library * lib, char * songName);//finds the first match given a song name
song_node * searchArtist( library * lib, char * artistName);//finds the first match given an artist name.
void printLetter( library * lib, char letter);//prints the list of artists given the first letter.
void printArtist( library * lib, char * artistName);//prints out the list of songs that the artist produced.
void printLibrary(library * lib);//prints out the library.
void shuffleList( library * lib);//prints out a series of random songs chosen from the library.
void deleteSong( library * lib, char * songName, char * artistName);//deletes a song from the library.
void deleteLibrary( library * lib);//deletes the whole library.

