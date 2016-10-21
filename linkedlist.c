#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linkedlist.h"

void print_list(struct song_node* l){;
  while (l){
    printf("%s - %s\n", l -> artist, l -> name);
    l = l -> next;
  }
}

struct song_node *insert_front(char n[256], char a[256], struct song_node *l){
  struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
  strncpy(new -> name, n, 256);
  strncpy(new -> artist, a, 256);
  new -> next = l;
  return new;
}

struct song_node *insert_order(char n[256], char a[256], struct song_node *l){ 
  if (!l)
    return insert_front(n, a, l);
  if (strcmp(n, l -> name) < 0)
    return insert_front(n, a, l);
    
  song_node *new = (song_node*)malloc(sizeof(song_node));
  strncpy(new -> name, n, 256);
  strncpy(new -> artist, a, 256);
  song_node *c = l;
  
  while (c){
    if (!(c -> next)){
      c -> next = new;
      new -> next = 0;
      break;
    }  
    if ((strcmp(n, c -> name) > 0) && (strcmp(n, (c -> next) -> name) < 0)){
	new -> next = c -> next;
	c -> next = new;
    }
    c = c -> next;
  }  
  return l;
}

song_node* find_song(char n[256], song_node *l){
  song_node* i;
  for (song_node* i = l; i; i = i -> next)
    if (strcmp(n, i -> name) == 0)   
	  return i;
  return NULL;
}

song_node* find_artist(char a[256], song_node *l){
  song_node* i;
  for (song_node* i = l; i; i = i -> next)
    if (strcmp(a, i -> artist) == 0)   
	  return i;
  return NULL;
}

int len(song_node *node) {
  int ans = 0;
  while (node){
    ans++;
    node = node -> next;
  }
  return ans;
}

song_node *random_node(song_node *l){
  song_node *new = l;
  while (new)
    new = new -> next;
  srand(time(NULL));
  int randi = (int)(len(l) * ((double)rand()/RAND_MAX));
  while (randi) {
    l = l -> next;
    randi--;
  }
  return l;
}

song_node* remove_node(char n[256], song_node *l){
  struct song_node* c = l;
  struct song_node* p;
  while (c){
    if (strncmp(c -> name, n, 256) == 0){
      if (c == l) 
	l = c -> next;
      else {
	p -> next = c -> next;
      }
      free(c);
      return l;
    }
    else {
      p = c;
      c = c -> next;
    }
  }
  return NULL;
}

void free_list(song_node *l){
  song_node* next = 0;
  song_node* i;
  for (song_node* i = l; i; i = next){
    next = i -> next;
    free(i);
  }
}

