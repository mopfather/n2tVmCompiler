#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
size_t max_length = 128;

string_ll* tokenizer(FILE* source) 
{
    string_ll* tokens = malloc(sizeof(string_ll));
    memset(tokens->string, 0, max_length);
    tokens->next = NULL;
    string_ll* tail = tokens;

    while (!feof(source))
    {
        char c = getc(source);    
        while (!feof(source) && (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '/'))
        {
            c = getc(source);
            if (c == '/')
            {
                while (!feof(source) && c != '\n')
                {
                    c = getc(source);
                }
            }
        }

        if (feof(source))
        {
            return tokens;
        }

        char* token = malloc(max_length);
        memset(token, 0, max_length);
        
        //assuming max word length = 128
        int i = 0;
        while (!feof(source) && (c != ' ' && c != '\n' && c != '\t' && c != '\r'))
        {
            token[i] = c;
            c = getc(source);
            i++;
        }

        strcpy(tail->string, token);
        tail->next = malloc(sizeof(string_ll));
        tail = tail->next;
        memset(tail->string, 0, max_length);
        tail->next = NULL; 
    }
    return tokens;
}