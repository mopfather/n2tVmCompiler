#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "tokenizer.h"
#include "translator.h"

#ifdef _WIN32
#include <Windows.h>
#define DIR_SEPARATOR_C '\\'
#define DIR_SEPARATOR_S "\\"

#elif __linux
#include <sys/stat.h>
#define DIR_SEPARATOR_C '/'
#define DIR_SEPARATOR_S "/"

#endif



void getpath(char* source, char* dest)
{
    #ifdef _WIN32
    GetFullPathNameA(source, MAX_PATH, dest, NULL);

    #elif __linux__
    realpath(source, dest);

    #endif
}


char isdir(char* path) 
{
    #ifdef _WIN32
    int attr = GetFileAttributesA(path);
    char isDir = attr & 0x10;
    
    #elif __linux__
    struct stat info;
    stat(path, &info);
    char isDir = S_ISDIR(info.st_mode);

    #endif

    return isDir;
}

char* sourceFileName(char* path)
{    
    char* ret_path = malloc(300);
    int i = 0;
    int j = 0;
    int last_dot = 0;
    while (path[j])
    {
        ret_path[i] = path[j];
        
        if (path[j] == '.')
        {
            last_dot = i;
        }
        i++;

        if (path[j] == DIR_SEPARATOR_C)
        {
            i = 0;
        }

        j++;
    }
    ret_path[last_dot] = 0;

    return ret_path;
}

char* outpath(char* fullpath, char isDir)       //TODO: maybe use OS API instead
{
    char* ret_path = malloc(300);

    if (isDir)
    {
        int last_char = strlen(fullpath) - 1;
        strcpy(ret_path, fullpath);
        while (ret_path[last_char] == DIR_SEPARATOR_C)
        {
            ret_path[last_char] = 0;
            last_char--;
        }
        strcat(ret_path, ".asm");
    }

    else
    {
        int i = 0;
        int last_dot = 0;
        while (fullpath[i])
        {
            ret_path[i] = fullpath[i];

            if (fullpath[i] == '.')
            {
                last_dot = i;
            }

            i++;
        }
        ret_path[last_dot] = 0;
        strcat(ret_path, ".asm");
    }

    return ret_path;
}

char* dirpath_append_filename(char* fullpath, char* filename)
{
    char* ret_path = malloc(300);
    strcpy(ret_path, fullpath);
    strcat(ret_path, DIR_SEPARATOR_S);
    strcat(ret_path, filename);

}


struct n_instr idk = {0};
struct n_instr* thing = &idk;

int main(int argc, char* argv[])
{
    if (argc > 1) 
    {
        char* fullpath = malloc(300);
        getpath(argv[1], fullpath);
        char isDir = isdir(fullpath);
        char* output_path = outpath(fullpath, isDir);

        FILE* output = fopen(output_path, "w");
        initialize(output, isDir);
        
        if (isDir)
        {
            DIR* source = opendir(fullpath);
            struct dirent* vm_file;

            while (vm_file = readdir(source))
            {
                if (strcmp(vm_file->d_name, ".") && strcmp(vm_file->d_name, ".."))
                {
                    char* cur_filename = vm_file->d_name;
                    char* cur_sourcefile_path = dirpath_append_filename(fullpath, cur_filename); 
                    FILE* source = fopen(cur_sourcefile_path, "r");
                    string_ll* tokens = tokenizer(source);
                    translator(output, tokens, cur_filename, isDir);
                }
            }

            printf("ifgoto: %d\npush: %d\npop: %d\n function: %d\n"
                   "call: %d\nret: %d\n lt: %d\n"
                   "gt: %d\neq: %d\n eq: %d\n"
                   "neg: %d\n and: %d\n or: %d\n not: %d\n"
                   "add: %d\n sub: %d\n", thing->ifgoto, thing->push, thing->pop, thing->function,
                   thing->call, thing->ret, thing->lt, thing->gt, thing->gt,
                   thing->eq, thing->neg, thing->and, thing->or, thing->not, thing->add,
                   thing->sub);
                
        }

        else 
        {
            char* filename_nopath = sourceFileName(fullpath);
            FILE* source = fopen(fullpath, "r");
            string_ll* tokens = tokenizer(source);
            translator(output, tokens, filename_nopath, isDir);
        }
    }
    return 0;
}