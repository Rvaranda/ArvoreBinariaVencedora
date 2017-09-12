#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


/*typedef struct Node
{
    Client* data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct BinTree
{
    Node* root;
    int totalNodes;
}BinTree;*/


int main()
{
    /*Client* rafael = (Client*)malloc(sizeof(Client));

    rafael->cod = 7586;
    strcpy(rafael->name, "Rafael");
    strcpy(rafael->birth, "18/06/1996");*/

    FILE* fileWrite = fopen("arquivos/clients.bat", "wb");

    client_saveInFileN(fileWrite, 1389654, "Jubileu Araujo Delgado", "23/08/1979");
    client_saveInFileN(fileWrite, 7586, "Rafael Andrade Varanda", "18/06/1996");

    fclose(fileWrite);

    FILE* fileRead = fopen("arquivos/clients.bat", "rb");

    Client* client = client_loadFromFile(fileRead);
    Client* rafael = client_loadFromFile(fileRead);

    fclose(fileRead);

    if (client != NULL && rafael != NULL)
    {
        client_print(client);
        client_print(rafael);
    }

    free(rafael);
    free(client);

    return 0;
}
