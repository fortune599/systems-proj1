#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytunez.h"

void add_song(song_node* table[26], char n[256], char a[256]){
  int i = (a[0]|0x20)- 'a';
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
  int i = (a[0]|0x20) - 'a';
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

void shuffle(song_node *table[26]){
    int i;
    for (i = 0; i < 26; i++){
        if (table[i]){
            song_node *new = random_node(table[i]);
            if (new){
                printf("Name: %s\n", new -> name);
                printf("Artist: %s\n\n", new -> artist);
            }
        }
    }
}


void delete_song(song_node *table[26], char n[256], char a[256]){
  int index = (a[0]|0x20) - 'a';
  table[index] = remove_node(n, table[index]);
}

void print_letter(song_node *table[26], char c){
    printf("Printing %c:\n", c);
    int i = c - 'a';
    print_list(table[i]);
}

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
