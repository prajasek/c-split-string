#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOKENS 100
#define WORDSIZE 50

int main(int argc, char* argv[]) {
    char* DELIMITER = " ";
    char* str = "This is a test string. Please enter string and delimiter in the command line.";
    if (argc==3) {
        str = argv[1];
        DELIMITER = argv[2]; 
    } 
    
    printf("\nString: %s\n", str);
    printf("Delimiter: %s\n\n", DELIMITER);

    int counter=0, counter_tokens =0;
    char* tokens[TOKENS];
    char token[WORDSIZE]; 
    memset(tokens, 0, TOKENS);
    memset(token, '\0', WORDSIZE);

    for (char* s=str;; s++){
        if (*s == *DELIMITER || *s=='\0'){
            if (token[0]!='\0') {               // empty string between delimiters OR delimiter at beginning or end.
                tokens[counter_tokens] = (char*) malloc(WORDSIZE*sizeof(char));
                strcpy(tokens[counter_tokens++], token);
            }
            if (*s=='\0') {                     // end of string
                tokens[counter_tokens] = NULL;
                break;
            }
            memset(token, '\0', WORDSIZE);
            counter=0;
        }
        else {
            token[counter++]=*s;
        }
    }

    // Find last element @last_token
    char* last_token;
    int i=0;
    while(tokens[i]!=NULL) {
        last_token = tokens[i++];
    }

    // Display tokens
    printf("Number of words: %d\n", counter_tokens);
    printf("Words:           [ ");
    for (int i=0;; i++){
        if (tokens[i]==NULL) {
            printf(" ]\n");
            break;
        }
        if (i) printf(", ");      // no comma at the start before elements
        printf("'%s'", tokens[i]);
    }
    printf("Last token:      %s\n\n", last_token);

    /* 
    Another way of iterating 
    -----------------------------
    char** word = tokens; 
    while (*word != NULL) {
        printf("TOKEN :%s\n", *word);
        word++;
    }
    */

    // free memory
    for (int index=0; index<counter_tokens; index++ ) {
        free(tokens[index]);
    }

}