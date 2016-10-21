#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node* l);

struct song_node* insert_front(char n[256], char a[256], struct song_node* l);

struct song_node* insert_order(char n[256], char a[256], struct song_node* l);

song_node* find_song(char n[256], song_node *l);

song_node* find_artist(char a[256], song_node *l);

song_node *random_node(song_node *l);

song_node *remove_node(char n[256], song_node *l);

void free_list(song_node *l);
