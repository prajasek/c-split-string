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
   
    char* tokens[TOKENS];
    int counter_tokens =0;
    memset(tokens, 0, TOKENS);

    char token[WORDSIZE]; 
    memset(token, '\0', WORDSIZE);

    int counter=0;

    for (char* s=str;; s++){

        if (*s == *DELIMITER){
            if (token[0]!='\0') {
                tokens[counter_tokens] = (char*) malloc(WORDSIZE*sizeof(char));
                strcpy(tokens[counter_tokens++], token);
                memset(token, '\0', WORDSIZE);
                counter=0;
            }
        } else if (*s == '\0')  {
            if (token[0]!='\0') {   
                    tokens[counter_tokens++] = token; 
            }
            tokens[counter_tokens] = NULL;
            break;
        } else {
            token[counter++]=*s;
        }
    }

    printf("Counter tokens: %d\n", counter_tokens);
    // Display tokens
    printf("Tokens : [ ");
    for (int i=0;; i++){
        if (tokens[i]==NULL) {
            printf("]\n");
            break;
        }
        printf("%s, ", tokens[i]);
    }

    //find number of elements
    char* t;
    int i=0;
    while(tokens[i]!=NULL) {
        t = tokens[i++];
    }
    
    // free memory
    for (int c=0; c<counter_tokens-1; c++ ) {
        free(tokens[c]);
    }

}