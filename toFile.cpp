#include <malloc.h>
#include "tree.h"
#include <string.h>

void serializeTree(address root){
	address curr;
	FILE* fp = fopen("tree.txt", "a");
	
	if (root == NULL){
		fprintf(fp, "null");
		return;
	}
	
	fprintf(fp, "%s ", root->info);
	curr = root->fs;
	while (curr != NULL){
		serializeTree(curr);
		curr = curr->nb;
	}
	fprintf(fp,"# ");
	
	fclose(fp);
}

address deserializeTree(){
	char str[200];
	Tree Mytree;
	address newNode, temp_fs, temp_nb;
	
	FILE* fp = fopen("tree.txt", "r");
	fscanf(fp,"%s ", &str);
	
	if (str == "null"){
		return Nil;
	}
	
	newNode = Alokasi(str);
	temp_fs = deserializeTree();
	if(temp_fs != Nil){
		newNode->fs = temp_fs;
		temp_nb = temp_fs;
		while (fscanf(fp, "%s ", &str) == 1 && str != "#"){
			temp_nb->nb = Alokasi(str);
			temp_nb = temp_nb->nb;
			temp_nb->fs = deserializeTree();
		}
	}
	
	fclose(fp);
	
	return newNode;
}
