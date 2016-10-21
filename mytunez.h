#include "linkedlist.h"

void add_song(song_node* table[26], char n[256], char a[256]);

song_node* search_song(song_node* table[26], char n[256]);

song_node* search_by_artist(song_node *table[26], char a[256]);

void print_artist(song_node* table[26], char a[256]);

void shuffle(song_node *table[26]);

void delete_song(song_node *table[26], char n[256], char a[256]);

void print_library(song_node *table[26]);

void free_library(song_node *table[26]);

void print_letter(song_node *table[26], char c);
