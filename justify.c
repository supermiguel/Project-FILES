#include <string.h>
#include <stdio.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);
        //printf("THIS RAN 1 \n");
        if (word_len == 0) {
          //  printf("THIS RAN 2 \n");
            flush_line();
            return 0;
        }
        //printf("THIS RAN 11 \n");
        
        if (word_len > MAX_WORD_LEN){
            //printf("THIS RAN 3 \n");
            
            word[MAX_WORD_LEN] = '*';
        }
        //printf("THIS RAN 13 \n");
        
        if (word_len + 1 > space_remaining()) {
            printf("THIS RAN 4 \n");
            
            write_line();
            printf("THIS RAN 5 \n");
                
            clear_line();
            printf("THIS RAN 7 \n");
            
        }
        //printf("THIS RAN 18 \n");
        
        add_word(word);
        //printf("THIS RAN 8 \n");
        
    }
}

