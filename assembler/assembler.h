

#ifndef __ASSEMBLER_H__
#define __ASSEMBLER_H__

enum assemblerError
{
    OK,
    BADFILE
}

enum command
{
    END,
    PUSH,
    POP,
    IN, 
    OUT,
    PUSH,
    MOV,
    ADD = 15,
    SUB,
    MUL,
    DIV,
    SQRT,
    SIN,
    COS,
    INC,
    DEC,
    OR,
    XOR,
    AND,
    JMP = 30,
    JE,
    JNE,
    JA,
    JB,
    JAE,
    JBE,
    CALL = 98,
    RET
    NOP
};

typedef struct 
{
    const char* name;
    size_t address;
} label;

size_t fileSize(FILE* file)
{
    if(file == NULL)
        return BADFILE;

    fseek(file, 0, SEEK_END);

    size_t size = ftell(file);

    rewind(file);
    return size;
}

int loadToBuffer(const char* fileName, size_t sizeFile, char* buffer)
{
    FILE* assmCode = fopen(path, "w");
    
    if(assmCode == NULL)
        return BADFILE;
    
    //size_t size = fileSize(assmCode);
    
    fread(buffer, sizeof(char), sizeFile, buffer);
    
    fclose(assmCode);

    return OK;
    
}

int countLabels(char* assmCode)
{
    int labelsNumber = 0;

    while( sscanf(assmCode, )
    sscanf(assmCode, //TODO

}



#endif

