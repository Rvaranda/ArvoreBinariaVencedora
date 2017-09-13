#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#define MAX_OPEN_FILES 4


typedef struct Node
{
    Client* data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BinTree
{
    Node* root;
    int totalNodes;
} BinTree;

BinTree* createWinnerBinTree(Node* n[], int numPart);

int main()
{
    FILE* partsToRead = fopen("filesToRead.txt", "r");
    if (partsToRead == NULL) return 1;

    int i;
    int num = 0;
    char line[20];

    while ((fscanf(partsToRead, "%s", line)) != EOF && num <= MAX_OPEN_FILES) num++;
    rewind(partsToRead);

    Node* leafNodes[num];
    FILE* files[num];

    for (i = 0; i < num; i++)
    {
        fscanf(partsToRead, "%s", line);
        files[i] = fopen(line, "rb");
        if (files[i] == NULL)
        {
            printf("Error in opennig file %s\n", line);
            return 1;
        }
    }

    for (i = 0; i < num; i++)
    {
        fclose(files[i]);
    }

    fclose(partsToRead);

    return 0;
}

BinTree* createWinnerBinTree(Node* n[], int numPart)
{
    BinTree* t = (BinTree*)malloc(sizeof(BinTree));
    if (t != NULL)
    {

    }
}
