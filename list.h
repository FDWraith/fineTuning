typedef struct song_node{ char name[256]; char artist[256]; struct song_node * next;} song_node;
char * lowerString( char * str);//Lowercases all the characters in a string
song_node * insert_front( song_node * current, char * name, char * art);//Creates a new node and inserts it in the front. Returns the resultant list.
song_node * insert( song_node * current, char * name, char * art);//Creates a new node and inserts it in the proper place (sorted by alphabeta according to artist). Returns resultant list.
void print_list( song_node * head);//Prints out the list
song_node * findSong( song_node * head, char * songName);//Finds the first match for the songName. Returns null if not found.
song_node * findArtist( song_node * head, char * artistName);//Finds the first match for the artistName. Returns null if not found.
int listLength( song_node * head );//Computes the length of the linked list. Helper function for randomNode.
song_node * randomNode( song_node * head );//Returns a random node from the list.
song_node * removeSong( song_node * head, char * songName);//Removes a song and returns the node. Note: The node is not freed as a result of this function.
song_node * freeNodes( song_node * head );//Frees all the node in the list.
