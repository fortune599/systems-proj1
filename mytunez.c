#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mytunez.h"

void add_song(song_node* table[26], char n[256], char a[256]){
  int i = a[0] - 'a';
  table[i] = insert_order(n, a, table[i]);
}

song_node* search_song(song_node* table[26], char n[256]){
  int i;
  for (i = 0; i < 26; i++) {
    song_node *song = find_song(n, table[i]);
    if (song){
      return song;
    }
  }
  return 0;
}

song_node* search_by_artist(song_node *table[26], char a[256]){
  int i = a[0] - 'a';
  return find_artist(a, table[i]);
}

void print_artist(song_node* table[26], char a[256]){
  int i;
  printf("Songs by %s:\n", a);
  for (i = 0; i < 26; i++)
    for (song_node* s = table[i]; s; s = s -> next)
      if (strncmp(a, s -> artist, 256) == 0)
	printf("%s\n", s -> name);              
}

//void shuffle(song_node *table[26]){

//void delete_song(song_node *table[26], char n[256], char a[256]){

void print_library(song_node *table[26]){
  int i;
  for (i = 0; i < 26; i++) {
    if (table[i]) {
      printf("%c library:\n", i+'a');
      print_list(table[i]);
    }  
  }
}

void free_library(song_node *table[26]){
  int i;
  for (i = 0; i < 26; i++)
    free_list(table[i]);

}
