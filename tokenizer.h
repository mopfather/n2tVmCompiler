#pragma once

typedef struct string_ll_tag
{
    char string[128];
    struct string_ll_tag* next;
} string_ll;

string_ll* tokenizer(FILE* source);
//takes a FILE* object and returns the linked list of tokens
//reads the text of the object
//removes all comments
//each word then becomes a token
//the last token is the empty string