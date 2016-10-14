typedef struct { char name[256]; char artist[256]; struct song_node * next;} song_node;
song_node * insert_front( song_node * current, char * name, char * art);
song_node * insert( song_node * current, char * name, char * art);
void print_list( song_node * head);
