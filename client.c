#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


Client* client_loadFromFile(FILE* file)
{
    Client* client = (Client*)malloc(sizeof(Client));
    if (client == NULL) return NULL;

    if (file)
    {
        fread(&client->cod, sizeof(unsigned int), 1, file);
        fread(client->name, sizeof(char), sizeof(client->name), file);
        fread(client->birth, sizeof(char), sizeof(client->birth), file);

        return client;
    }

    return NULL;
}

void client_saveInFile(FILE* file, Client* client)
{
    if (file)
    {
        fwrite(&client->cod, sizeof(unsigned int), 1, file);
        fwrite(client->name, sizeof(char), sizeof(client->name), file);
        fwrite(client->birth, sizeof(char), sizeof(client->birth), file);
    }
}

void client_saveInFileN(FILE* file, unsigned int cod, const char* name, const char* birth)
{
    Client* tmpClient = (Client*)malloc(sizeof(Client));
    if (tmpClient == NULL) return;

    tmpClient->cod = cod;
    strcpy(tmpClient->name, name);
    strcpy(tmpClient->birth, birth);

    if (file)
    {
        fwrite(&tmpClient->cod, sizeof(unsigned int), 1, file);
        fwrite(tmpClient->name, sizeof(char), sizeof(tmpClient->name), file);
        fwrite(tmpClient->birth, sizeof(char), sizeof(tmpClient->birth), file);
    }

    free(tmpClient);
    tmpClient = NULL;
}

void client_print(Client* client)
{
    printf("Codigo: %u\n", client->cod);
    printf("Nome: %s\n", client->name);
    printf("Data de Nascimento: %s\n", client->birth);
    printf("--------------------------\n");
}
