#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#define MAX_LINE_LEN 60

struct word {
    char *word;
    struct word *next;
};
struct word *tail, *head;

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    //while(get_word());
    //write_line();
}


void add_word(const char *word)
{
    struct word *new = malloc(sizeof(struct word));
    //new->word = malloc(strlen(word)+1);
    new->word = malloc(sizeof(struct word));
    if (tail != NULL)
        tail->next = new;
    tail = new;
    if (head == NULL)
        head = new;
    strcpy(new->word, word);
    line_len += strlen(new->word);
    num_words++;
    
}

int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    struct word *curr = head;
    int extra_spaces, spaces_to_insert, i , j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (*curr->word != ' '){
            printf("%s",curr->word);
            curr = curr->next;
        }
        else {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }

    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0)
        puts(line);
}
