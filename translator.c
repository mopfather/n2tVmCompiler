#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "translator.h"
#include "tokenizer.h"

extern struct n_instr* thing;

void initialize(FILE* dest, char isdir)
{
    fprintf(dest, "@256\n"
                  "D=A\n"
                  "@SP\n"
                  "M=D\n");    
    if (isdir) 
    {
     
        fprintf(dest,   "@_RETURN$ADDRESS0\n"
                        "D=A\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@LCL\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@ARG\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@THIS\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@THAT\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@SP\n"
                        "D=M\n"
                        "@5\n"
                        "D=D-A\n"
                        "@ARG\n"
                        "M=D\n"
                        "@SP\n"
                        "D=M\n"
                        "@LCL\n"
                        "M=D\n"
                        "@Sys.init\n"  
                        "0;JMP\n"
                        "(_RETURN$ADDRESS0)\n");
      
        fprintf(dest,   "(RETURN$INSTRUCTION)\n"
                        "@5\n"
                        "D=A\n"
                        "@LCL\n"
                        "A=M-D\n"
                        "D=M\n"
                        "@R15\n"
                        "M=D\n"
                        "@SP\n"
                        "M=M-1\n"
                        "A=M\n"
                        "D=M\n"
                        "@ARG\n"
                        "A=M\n"
                        "M=D\n"
                        "@ARG\n"
                        "D=M\n"
                        "@SP\n"
                        "M=D+1\n"
                        "@LCL\n"
                        "A=M-1\n"
                        "D=M\n"
                        "@THAT\n"
                        "M=D\n"
                        "@2\n"
                        "D=A\n"
                        "@LCL\n"
                        "A=M-D\n"
                        "D=M\n"
                        "@THIS\n"
                        "M=D\n"
                        "@3\n"
                        "D=A\n"
                        "@LCL\n"
                        "A=M-D\n"
                        "D=M\n"
                        "@ARG\n"
                        "M=D\n"
                        "@4\n"
                        "D=A\n"
                        "@LCL\n"
                        "A=M-D\n"
                        "D=M\n"
                        "@LCL\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(GT$INSTRUCTION)\n"
                        "@SP\n"
                        "AM=M-1\n"
                        "D=M\n"
                        "A=A-1\n"
                        "D=M-D\n"
                        "@__TRUE$GT\n"
                        "D;JGT\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=0\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n"
                        "(__TRUE$GT)\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=-1\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(LT$INSTRUCTION)\n"
                        "@SP\n"
                        "AM=M-1\n"
                        "D=M\n"
                        "A=A-1\n"
                        "D=M-D\n"
                        "@__TRUE$LT\n"
                        "D;JLT\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=0\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n"
                        "(__TRUE$LT)\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=-1\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(EQ$INSTRUCTION)\n"
                        "@SP\n"
                        "AM=M-1\n"
                        "D=M\n"
                        "A=A-1\n"
                        "D=M-D\n"
                        "@__TRUE$EQ\n"
                        "D;JEQ\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=0\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n"
                        "(__TRUE$EQ)\n"
                        "@SP\n"
                        "A=M-1\n"
                        "M=-1\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
    
        fprintf(dest,   "(CALL$INSTRUCTION)\n"
                        "@R13\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@LCL\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@ARG\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@THIS\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@THAT\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@SP\n"
                        "D=M\n"
                        "@5\n"
                        "D=D-A\n"
                        "@R14\n"
                        "D=D-M\n"
                        "@ARG\n"
                        "M=D\n"
                        "@SP\n"
                        "D=M\n"
                        "@LCL\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(POP$INSTRUCTION)\n"
                        "@SP\n"
                        "M=M-1\n"
                        "A=M+1\n"
                        "M=D\n"
                        "A=A-1\n"
                        "D=M\n"
                        "A=A+1\n"
                        "A=M\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(PUSH$ARG_OFFSET0)\n"
                        "@ARG\n"
                        "A=M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(PUSH$ARG_OFFSET1)\n"
                        "@ARG\n"
                        "A=M+1\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(PUSH$ARG_OFFSETN)\n"
                        "@ARG\n"
                        "A=D+M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(PUSH$LCL_OFFSET0)\n"
                        "@LCL\n"
                        "A=M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$LCL_OFFSET1)\n"
                        "@LCL\n"
                        "A=M+1\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$LCL_OFFSETN)\n"
                        "@LCL\n"
                        "A=D+M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");

        fprintf(dest,   "(PUSH$THIS_OFFSET0)\n"
                        "@THIS\n"
                        "A=M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$THIS_OFFSET1)\n"
                        "@THIS\n"
                        "A=M+1\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$THIS_OFFSETN)\n"
                        "@THIS\n"
                        "A=D+M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
    
        fprintf(dest,   "(PUSH$THAT_OFFSET0)\n"
                        "@THAT\n"
                        "A=M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$THAT_OFFSET1)\n"
                        "@THAT\n"
                        "A=M+1\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
        
        fprintf(dest,   "(PUSH$THAT_OFFSETN)\n"
                        "@THAT\n"
                        "A=D+M\n"
                        "D=M\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n"
                        "@R15\n"
                        "A=M\n"
                        "0;JMP\n");
    }
}

string_ll* translate_push(FILE* dest, string_ll* tokens, char* filename, char isdir, int callcount)
{
    char* segment = tokens->string;
    tokens = tokens->next;
    int offset = atoi(tokens->string);
    tokens = tokens->next;

    if (isdir)
    {
        if (!strcmp(segment, "constant"))
        {
            fprintf(dest, "@%d\n"        
                        "D=A\n"
                        "@SP\n"
                        "M=M+1\n"
                        "A=M-1\n"
                        "M=D\n", offset);
            thing->push += 6;
        }

        else if (!strcmp(segment, "argument"))
        {
            if (offset == 0)
            {    
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$ARG_OFFSET0\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;
            }
            else if (offset == 1)
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$ARG_OFFSET1\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;
            }
            else 
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@%d\n"
                                "D=A\n"
                                "@PUSH$ARG_OFFSETN\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount, offset,
                                                              filename, callcount);
                thing->push += 8;
            }
        }

        else if (!strcmp(segment, "local"))
        {
            if (offset == 0)
            {    
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$LCL_OFFSET0\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;
            }
            else if (offset == 1)
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$LCL_OFFSET1\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;
            }
            else 
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@%d\n"
                                "D=A\n"
                                "@PUSH$LCL_OFFSETN\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount, offset,
                                                              filename, callcount);
                thing->push += 8;
            }
        }

        else if (!strcmp(segment, "static"))
        {
            fprintf(dest, "@%s.%d\n"
                          "D=M\n"
                          "@SP\n"
                          "M=M+1\n"
                          "A=M-1\n"
                          "M=D\n", filename, offset);
            thing->push += 6;
        }

        else if (!strcmp(segment, "pointer"))
        {
            if (offset == 0)
            {    
                fprintf(dest, "@THIS\n"
                              "D=M\n"
                              "@SP\n"
                                "M=M+1\n"
                                "A=M-1\n"
                                "M=D\n");
                thing->push += 6;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n"
                            "@SP\n"
                            "M=M+1\n"
                            "A=M-1\n"
                            "M=D\n");
                thing->push += 6;
            }
        }

        else if (!strcmp(segment, "this"))
        {
            if (offset == 0)
            {       
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$THIS_OFFSET0\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;
            }
            else if (offset == 1)
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$THIS_OFFSET1\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;    
            }
            else 
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@%d\n"
                                "D=A\n"
                                "@PUSH$THIS_OFFSETN\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount, offset,
                                                              filename, callcount);
                thing->push += 8;
            }
        }

        else if (!strcmp(segment, "that"))
        {
            if (offset == 0)
            {    
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$THAT_OFFSET0\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;  
            }
            else if (offset == 1)
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@PUSH$THAT_OFFSET1\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount,
                                                              filename, callcount);
                thing->push += 6;  
            }
            else 
            {
                fprintf(dest,   "@%sINSTRUCTION$RETURN%d\n"
                                "D=A\n"
                                "@R15\n"
                                "M=D\n"
                                "@%d\n"
                                "D=A\n"
                                "@PUSH$THIS_OFFSETN\n"
                                "0;JMP\n"
                                "(%sINSTRUCTION$RETURN%d)\n", filename, callcount, offset,
                                                              filename, callcount);
                thing->push += 8;  
            }
        } 

        else if (!strcmp(segment, "temp"))
        {
            fprintf(dest, "@%d\n"
                          "D=M\n"
                          "@SP\n"
                          "M=M+1\n"
                          "A=M-1\n"
                          "M=D\n", (offset + 5));
            thing->push += 6;
        }
    }

    else
    {
        if (!strcmp(segment, "constant"))
        {
            fprintf(dest, "@%d\n"        
                        "D=A\n", offset);
            thing->push += 2;
        }

        else if (!strcmp(segment, "argument"))
        {
            if (offset == 0)
            {    
                fprintf(dest, "@ARG\n"
                            "A=M\n"
                            "D=M\n");
                thing->push += 3;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@ARG\n"
                            "A=M+1\n"
                            "D=M\n");
                thing->push += 3;
            }
            else 
            {
                fprintf(dest, "@%d\n"
                            "D=A\n"
                            "@ARG\n"
                            "A=D+M\n"
                            "D=M\n", offset);
                thing->push += 5;
            }
        }

        else if (!strcmp(segment, "local"))
        {
            if (offset == 0)
            {    
                fprintf(dest, "@LCL\n"
                            "A=M\n"
                            "D=M\n");
                thing->push += 3;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@LCL\n"
                            "A=M+1\n"
                            "D=M\n");
                thing->push += 3;
            }
            else 
            {
                fprintf(dest, "@%d\n"
                            "D=A\n"
                            "@LCL\n"
                            "A=D+M\n"
                            "D=M\n", offset);
                thing->push += 5;
            }
        }

        else if (!strcmp(segment, "static"))
        {
            fprintf(dest, "@%s.%d\n"
                        "D=M\n", filename, offset);
            thing->push += 2;
        }

        else if (!strcmp(segment, "pointer"))
        {
            if (offset == 0)
            {    
                fprintf(dest, "@THIS\n"
                            "D=M\n");
                thing->push += 3;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n");
                thing->push += 2;
            }
        }

        else if (!strcmp(segment, "this"))
        {
            if (offset == 0)
            {       
                fprintf(dest, "@THIS\n"
                            "A=M\n"
                            "D=M\n");
                thing->push += 3;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THIS\n"
                            "A=M+1\n"
                            "D=M\n");
                thing->push += 3;    
            }
            else 
            {
                fprintf(dest, "@%d\n"
                            "D=A\n"
                            "@THIS\n"
                            "A=D+M\n"
                            "D=M\n", offset);
                thing->push += 5;
            }
        }

        else if (!strcmp(segment, "that"))
        {
            if (offset == 0)
            {    
                fprintf(dest, "@THAT\n"
                            "A=M\n"
                            "D=M\n");
                thing->push += 3;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "A=M+1\n"
                            "D=M\n");
                thing->push += 3;
            }
            else 
            {
                fprintf(dest, "@%d\n"
                            "D=A\n"
                            "@ARG\n"
                            "A=D+M\n"
                            "D=M\n", offset);
                thing->push += 5;
            }
        } 

        else if (!strcmp(segment, "temp"))
        {
            fprintf(dest, "@%d\n"
                        "D=M\n", (offset + 5));
            thing->push += 2;
        }

        fprintf(dest, "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n");
        thing->push += 4;
    }

    return tokens;
}

string_ll* translate_pop(FILE* dest, string_ll* tokens, char* filename, char isdir, int callcount)
{
    char* segment = tokens->string;
    tokens = tokens->next;
    int offset = atoi(tokens->string);
    tokens = tokens->next;

    if (isdir)
    {
        fprintf(dest, "@%sINSTRUCTION$RETURN%d\n"
                      "D=A\n"
                      "@R15\n"
                      "M=D\n", filename, callcount);
        thing->pop += 2;

        if (!strcmp(segment, "argument"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@ARG\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@ARG\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@ARG\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "local"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@LCL\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@LCL\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@LCL\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "static"))
        {
            fprintf(dest, "@%s.%d\n"
                        "D=A\n", filename, offset);
            thing->pop += 2;
        }

        else if (!strcmp(segment, "pointer"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THIS\n"
                            "D=A\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=A\n");
                thing->pop += 2;
            }
        }

        else if (!strcmp(segment, "this"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THIS\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THIS\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@THIS\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "that"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=M+1\n");
                
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "temp"))
        {
            fprintf(dest, "@%d\n"
                        "D=A\n", (offset + 5));
            thing->pop += 2;
        }

        fprintf(dest, "@POP$INSTRUCTION\n"
                      "0;JMP\n"
                      "(%sINSTRUCTION$RETURN%d)\n", filename, callcount);
        thing->pop += 2;
    }

    else
    {
        if (!strcmp(segment, "argument"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@ARG\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@ARG\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@ARG\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "local"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@LCL\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@LCL\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@LCL\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "static"))
        {
            fprintf(dest, "@%s.%d\n"
                        "D=A\n", filename, offset);
            thing->pop += 2;
        }

        else if (!strcmp(segment, "pointer"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THIS\n"
                            "D=A\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=A\n");
                thing->pop += 2;
            }
        }

        else if (!strcmp(segment, "this"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THIS\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THIS\n"
                            "D=M+1\n");
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@THIS\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "that"))
        {
            if (offset == 0)
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n");
                thing->pop += 2;
            }
            else if (offset == 1)
            {
                fprintf(dest, "@THAT\n"
                            "D=M+1\n");
                
                thing->pop += 2;
            }
            else
            {
                fprintf(dest, "@THAT\n"
                            "D=M\n"
                            "@%d\n"
                            "D=D+A\n", offset);
                thing->pop += 4;
            }
        }

        else if (!strcmp(segment, "temp"))
        {
            fprintf(dest, "@%d\n"
                        "D=A\n", (offset + 5));
            thing->pop += 2;
        }


        fprintf(dest, "@SP\n"
                    "M=M-1\n"
                    "A=M+1\n"
                    "M=D\n"
                    "A=A-1\n"
                    "D=M\n"
                    "A=A+1\n"
                    "A=M\n"
                    "M=D\n");
        thing->pop += 9;
    }

    return tokens;
}

void translate_add(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "M=D+M\n");
    thing->add += 5;
} 

void translate_sub(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "M=M-D\n");
    thing->sub += 5;
}

void translate_neg(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "A=M-1\n"
                  "M=-M\n");
    thing->neg += 3;
}

void translate_eq(FILE* dest, char* filename, int labelcount)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "D=M-D\n"
                  "@__%s.TRUE%d\n"
                  "D;JEQ\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=0\n"
                  "@__%s.END%d\n"
                  "0;JMP\n"
                  "(__%s.TRUE%d)\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=-1\n"
                  "(__%s.END%d)\n",
            filename, labelcount, filename, labelcount, filename, labelcount, filename, labelcount);
    thing->eq += 15;
}

void translate_gt(FILE* dest, char* filename, int labelcount)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "D=M-D\n"
                  "@__%s.TRUE%d\n"
                  "D;JGT\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=0\n"
                  "@__%s.END%d\n"
                  "0;JMP\n"
                  "(__%s.TRUE%d)\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=-1\n"
                  "(__%s.END%d)\n",
            filename, labelcount, filename, labelcount, filename, labelcount, filename, labelcount);
    thing->gt += 15;
}

void translate_lt(FILE* dest, char* filename, int labelcount)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "D=M-D\n"
                  "@__%s.TRUE%d\n"
                  "D;JLT\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=0\n"
                  "@__%s.END%d\n"
                  "0;JMP\n"
                  "(__%s.TRUE%d)\n"
                  "@SP\n"
                  "A=M-1\n"
                  "M=-1\n"
                  "(__%s.END%d)\n",
            filename, labelcount, filename, labelcount, filename, labelcount, filename, labelcount);
    thing->lt += 15;
}

void translate_and(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "M=D&M\n");
    thing->and += 5;
}

void translate_or(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "A=A-1\n"
                  "M=D|M\n");
    thing->or += 5;
}

void translate_not(FILE* dest)
{
    fprintf(dest, "@SP\n"
                  "A=M-1\n"
                  "M=!M\n");
    thing->not += 3;
}

string_ll* translate_label(FILE* dest, string_ll* tokens, char* filename, char* labelscope)
{
    char* label = tokens->string;
    tokens = tokens->next;

    fprintf(dest, "(%s$%s.%s)\n", labelscope, filename, label);
    return tokens;
}

string_ll* translate_goto(FILE* dest, string_ll* tokens, char* filename, char* labelscope)
{
    char* label = tokens->string;
    tokens = tokens->next;

    fprintf(dest, "@%s$%s.%s\n"
                  "0;JMP\n", labelscope, filename, label);
    return tokens;
}

string_ll* translate_ifgoto(FILE* dest, string_ll* tokens, char* filename, char* labelscope)
{
    char* label = tokens->string;
    tokens = tokens->next;

    fprintf(dest, "@SP\n"
                  "AM=M-1\n"
                  "D=M\n"
                  "@%s$%s.%s\n"
                  "D;JNE\n", labelscope, filename, label);
    thing->ifgoto += 6; 
    return tokens;
}

string_ll* translate_function(FILE* dest, string_ll* tokens, char* funcname)
{
    int nvar = atoi(tokens->string);
    tokens = tokens->next;

    fprintf(dest, "(%s)\n", funcname);
    
    if (nvar == 0)
    {
        return tokens;
    }
    else if (nvar == 1)
    {
        fprintf(dest, "@SP\n"
                      "M=M+1\n"
                      "A=M-1\n"
                      "M=0\n");
        thing->function += 4;
    }
    else
    {
        fprintf(dest, "@SP\n"
                    "A=M\n");
        for (int i = 0; i < nvar; i++)
        {
            fprintf(dest, "M=0\n"
                        "A=A+1\n");
        }
        fprintf(dest, "D=A\n"
                    "@SP\n"
                    "M=D\n");
        thing->function += 5 + nvar*2;
    }

    return tokens;
}

string_ll* translate_call(FILE* dest, string_ll* tokens, int callcount, char* filename, char isdir)
{
    char* namefun = tokens->string;
    tokens = tokens->next;
    int nargs = atoi(tokens->string);
    tokens = tokens->next;

    if (isdir)
    {
        fprintf(dest, "@%sRETURN$ADDRESS%d\n"
                      "D=A\n"
                      "@R13\n"
                      "M=D\n"
                      "@%d\n"
                      "D=A\n"
                      "@R14\n"
                      "M=D\n"
                      "@%s\n"
                      "D=A\n"
                      "@R15\n"
                      "M=D\n"
                      "@CALL$INSTRUCTION\n"
                      "0;JMP\n"
                      "(%sRETURN$ADDRESS%d)\n", filename, callcount, nargs, namefun,
                                                filename, callcount);
        thing->call += 14;
                
    }
    else
    {
        fprintf(dest, "@%sRETURN$ADDRESS%d\n"
                    "D=A\n"
                    "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n"
                    "@LCL\n"
                    "D=M\n"
                    "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n"
                    "@ARG\n"
                    "D=M\n"
                    "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n"
                    "@THIS\n"
                    "D=M\n"
                    "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n"
                    "@THAT\n"
                    "D=M\n"
                    "@SP\n"
                    "M=M+1\n"
                    "A=M-1\n"
                    "M=D\n"
                    "@SP\n"
                    "D=M\n"
                    "@5\n"
                    "D=D-A\n"
                    "@%d\n"
                    "D=D-A\n"
                    "@ARG\n"
                    "M=D\n"
                    "@SP\n"
                    "D=M\n"
                    "@LCL\n"
                    "M=D\n"
                    "@%s\n"
                    "0;JMP\n"
                    "(%sRETURN$ADDRESS%d)\n", filename, callcount, nargs, namefun, filename, callcount);
    }
    return tokens;
}


void translate_return(FILE* dest)
{
    fprintf(dest, "@5\n"
                  "D=A\n"
                  "@LCL\n"
                  "A=M-D\n"
                  "D=M\n"
                  "@R15\n"
                  "M=D\n"
                  "@SP\n"
                  "M=M-1\n"
                  "A=M\n"
                  "D=M\n"
                  "@ARG\n"
                  "A=M\n"
                  "M=D\n"
                  "@ARG\n"
                  "D=M\n"
                  "@SP\n"
                  "M=D+1\n"
                  "@LCL\n"
                  "A=M-1\n"
                  "D=M\n"
                  "@THAT\n"
                  "M=D\n"
                  "@2\n"
                  "D=A\n"
                  "@LCL\n"
                  "A=M-D\n"
                  "D=M\n"
                  "@THIS\n"
                  "M=D\n"
                  "@3\n"
                  "D=A\n"
                  "@LCL\n"
                  "A=M-D\n"
                  "D=M\n"
                  "@ARG\n"
                  "M=D\n"
                  "@4\n"
                  "D=A\n"
                  "@LCL\n"
                  "A=M-D\n"
                  "D=M\n"
                  "@LCL\n"
                  "M=D\n"
                  "@R15\n"
                  "A=M\n"
                  "0;JMP\n");
}

void translator(FILE* dest, string_ll* tokens, char* filename, char isdir)
{
    int labelcount = 1;
    int callcount = 1;
    char* labelscope = malloc(200);
    memset(labelscope, 0, 200);

    while (*tokens->string)
    {
        if (!strcmp(tokens->string, "push"))
        {
            tokens = tokens->next;
            tokens = translate_push(dest, tokens, filename, isdir, callcount);
            callcount++;
        }

        else if (!strcmp(tokens->string, "pop"))
        {
            tokens = tokens->next;
            tokens = translate_pop(dest, tokens, filename, isdir, callcount);
            callcount++;
        }

        else if (!strcmp(tokens->string, "label"))
        {
            tokens = tokens->next;
            tokens = translate_label(dest, tokens, filename, labelscope);
        }

        else if (!strcmp(tokens->string, "goto"))
        {
            tokens = tokens->next;
            tokens = translate_goto(dest, tokens, filename, labelscope);
        }
        
        else if (!strcmp(tokens->string, "if-goto"))
        {
            tokens = tokens->next;
            tokens = translate_ifgoto(dest, tokens, filename, labelscope);
        }

        else if (!strcmp(tokens->string, "function"))
        {
            tokens = tokens->next;
            strcpy(labelscope, tokens->string);
            tokens = tokens->next;
            tokens = translate_function(dest, tokens, labelscope);
        }

        else if (!strcmp(tokens->string, "call"))
        {
            tokens = tokens->next;
            tokens = translate_call(dest, tokens, callcount, filename, isdir);
            callcount++;
        }

        else if (!strcmp(tokens->string, "return"))
        {
            tokens = tokens->next;
            if (isdir)
            {
                fprintf(dest, "@RETURN$INSTRUCTION\n"
                              "0;JMP\n");
                thing->ret += 2;
            }
            else
            {
                translate_return(dest);
            }
        }

        else if (!strcmp(tokens->string, "add"))
        {
            tokens = tokens->next;
            translate_add(dest);
        }

        else if (!strcmp(tokens->string, "sub"))
        {
            tokens = tokens->next;
            translate_sub(dest);
        }

        else if (!strcmp(tokens->string, "neg"))
        {
            tokens = tokens->next;
            translate_neg(dest);
        }

        else if (!strcmp(tokens->string, "eq"))
        {
            tokens = tokens->next;
            if (isdir) 
            {
                fprintf(dest, "@%sINSTR$RETURN%d\n"
                              "D=A\n"   
                              "@R15\n"
                              "M=D\n"
                              "@EQ$INSTRUCTION\n"
                              "0;JMP\n"
                              "(%sINSTR$RETURN%d)\n", filename, callcount, filename, callcount);
                callcount++;
                thing->eq += 6;
            }
            else 
            {
                translate_eq(dest, filename, labelcount);
                labelcount += 1;
            }
        }
        
        else if (!strcmp(tokens->string, "gt"))
        {
            tokens = tokens->next;
            if (isdir) 
            {
                fprintf(dest, "@%sINSTR$RETURN%d\n"
                              "D=A\n"
                              "@R15\n"
                              "M=D\n"
                              "@GT$INSTRUCTION\n"
                              "0;JMP\n"
                              "(%sINSTR$RETURN%d)\n", filename, callcount, filename, callcount);
                callcount++;
                thing->gt += 6;
            }
            else 
            {
                translate_gt(dest, filename, labelcount);
                labelcount += 1;
            }
        }

        else if (!strcmp(tokens->string, "lt"))
        {
            tokens = tokens->next;
            if (isdir) 
            {
                fprintf(dest, "@%sINSTR$RETURN%d\n"
                              "D=A\n"
                              "@R15\n"
                              "M=D\n"
                              "@LT$INSTRUCTION\n"
                              "0;JMP\n"
                              "(%sINSTR$RETURN%d)\n", filename, callcount, filename, callcount);
                callcount++;
                thing->lt += 6;
            }
            else 
            {
                translate_lt(dest, filename, labelcount);
                labelcount += 1;
            }
        }


        else if (!strcmp(tokens->string, "and"))
        {
            tokens = tokens->next;
            translate_and(dest);
        }
        
        else if (!strcmp(tokens->string, "or"))
        {
            tokens = tokens->next;
            translate_or(dest);
        }
        
        else if (!strcmp(tokens->string, "not"))
        {
            tokens = tokens->next;
            translate_not(dest);
        }
    }
}   
        
        
