#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"


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

BinTree* createWinnerBinTree(int numPart);

int main()
{
    FILE* partsToRead = fopen("filesToRead.txt", "r");
    if (partsToRead == NULL) return 1;

    int num = 0;
    char line[20];

    while ((fscanf(partsToRead, "%s", line)) != EOF)
    {
        printf("%s\n", line);

        FILE* test = fopen(line, "wb");
        if (test != NULL) fclose(test);

        num++;
    }

    printf("%d\n", num);

    fclose(partsToRead);

    return 0;
}

BinTree* createWinnerBinTree(int numPart)
{
    BinTree* t = (BinTree*)malloc(sizeof(BinTree));
    if (t != NULL)
    {

    }
}
