#include <time.h>

#include "mytunez.h"
/* Suwamik Paul
   Fortune Soliel
   Period 5
*/

int main() {
    srand(time(NULL));
    song_node *table[26];
    int i;
    for (i = 0; i < 26; i++) {
        table[i] = 0;
    }

    add_song(table, "Demons", "Imagine Dragons");
    add_song(table, "I Bet My Life", "Imagine Dragons");
    add_song(table, "Pompeii", "Bastille");
    add_song(table, "Over", "Drake");
    add_song(table, "Headlines", "Drake");

    printf("Printing entire library:\n");
    print_library(table);

    printf("\nTesting print letter:\n");
    print_letter(table, 'i');

    printf("\nTesting search song:\n");
    song_node *song = search_song(table, "Demons");
    if (song){
        printf("Song found\n");
    }
    song = search_song(table, "Shots");
    if (!song){
        printf("Song not found.\n");
    }

    printf("\nTesting print artist:\n");
    print_artist(table, "Imagine Dragons");

    printf("\nTesting shuffle:\n");
    shuffle(table);

    printf("\nTesting remove song:\n");
    delete_song(table, "Demons", "Imagine Dragons");
    print_library(table);

    free_library(table);
}
