#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <stdio.h>

typedef struct Client
{
    unsigned int cod;
    char name[50];
    char birth[15];
} Client;

Client* client_loadFromFile(FILE* file);
void client_saveInFile(FILE* file, Client* client);
void client_saveInFileN(FILE* file, unsigned int cod, const char* name, const char* birth);

#endif // CLIENT_H_INCLUDED
