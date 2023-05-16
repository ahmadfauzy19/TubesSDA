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

void fixName(const char *file_name, char *new_name){
	int len;
	char nameFile[20], lastFour[5];
	
	len = strlen(file_name);
	strncpy(lastFour, file_name + len - 4, 4);
	lastFour[4] = '\0';
	if(strcmp(lastFour, ".txt") != 0){
		sprintf(new_name, "%s.txt", file_name);
	}else{
		strcpy(new_name, file_name);
	}

}

bool fileExists(const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    bool is_exist = true;
    if (fp == NULL || file_name == "tentang.txt"){
        is_exist = false;
        fclose(fp);
    }
    return is_exist;
}

bool has_txt_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".txt") == 0;
}
