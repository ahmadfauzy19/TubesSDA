#include <malloc.h>
#include "tree.h"
#include <string.h>
#define MAX_LINE_LENGTH 100

void serializeTree(address root, FILE *fp) {
    // Base case
    if (root == NULL) {
        fprintf(fp, "%s ", "NULL");
        return;
    }

    // Store current node and recur for its children
    fprintf(fp, "%s ", root->info);
    serializeTree(root->fs, fp);
    serializeTree(root->nb, fp);
}

int deSerializeTree(address &root, FILE *fp) {
    // Read next item from file
    char* val = new char[MAX_LINE_LENGTH];
    if (fscanf(fp, "%s", val) == 0) {
        return 1;
    }

    // If next item is "NULL", then return 1 to indicate same
    if (strcmp(val, "NULL") == 0) {
        root = NULL;
        return 1;
    }

    // Create node with this item and recur for its children
    root = Alokasi(val);
    deSerializeTree(root->fs, fp);
    deSerializeTree(root->nb, fp);

    // Finally return 0 for successful finish
    return 0;
}
