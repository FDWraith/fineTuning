typedef struct library{
  song_node * table[26];
} library;
void addSong( library * lib, char * songName, char * artistName);
song_node * searchSong( library * lib, char * songName);
song_node * searchArtist( library * lib, char * artistName);

