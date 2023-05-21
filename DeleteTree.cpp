#include "Tree.h"
#include<stdlib.h>

void DeleteTree(address* root1,addressBin* root2,addressBin* root3){
	int pilihan;
	system("cls");
	printf("1. delete all\n");
	printf("2. hanya non binary tree\n");
	printf("3. hanya binary tree\n");
	printf("4. hanya AVL\n");
	printf("masukan pilihan = ");scanf("%d",&pilihan);
	getchar();
	switch(pilihan){
		case 1:
			deleteNB(root1);
			DeleteB(root2);
			DeleteB(root3);
			printf("berhasil menghapus semua tree...");
			getchar();
			break;
		case 2:
			deleteNB(root1);
			printf("berhasil menghapus non-binary tree...");
			getchar();
			break;
		case 3:
			DeleteB(root2);
			printf("berhasil menghapus binary tree...");
			getchar();
			break;
		case 4:
			DeleteB(root3);
			printf("berhasil menghapus AVL tree...");
			getchar();
			break;
		default:
			printf("masukan pilihan dengan benar !!\n");
			getchar();
			break;
	}
}

//delete non binary
void deleteNB(address* root) {
	if (*root == NULL){
	    return;
	}
	deleteNB(&((*root)->fs)); // Hapus subtree left secara rekursif
	deleteNB(&((*root)->nb)); // Hapus subtree right secara rekursif
	free(*root); // Hapus node saat ini
	*root = NULL; // Mengatur pointer root ke NULL
}



//delete binary
void DeleteB(addressBin* root) {
	if (*root == NULL){
	    return;
	}
	DeleteB(&((*root)->left)); // Hapus subtree left secara rekursif
	DeleteB(&((*root)->right)); // Hapus subtree right secara rekursif
	free(*root); // Hapus node saat ini
	*root = NULL; // Mengatur pointer root ke NULL
}


