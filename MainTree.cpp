#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "UI.h"

int main(){
	/* Kamus Lokal */
	address P,*Q, nbRoot = NULL;
	addressBin rootBin = NULL;
	BinTree treeAvl;
	treeAvl.pointer = NULL;
	Tree Mytree;
	BinTree Btree;
	infotype nama,buku;
	int pilihan, i;
	char ask;
	char tab[]="";
	
	/* Program */
	awal();
	system("cls");
	splashScreen();
	CreateTree (&Mytree);
	do{
		system("cls");
		TampilanAwal();
		printf("masukan pilihan :");scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				do{
					system("cls");
					printf("**tampilan preorder **\n");
					if (nbRoot == Nil){
						nbRoot = Mytree.head;
					}else{
						Mytree.head = nbRoot;
					}
					nbPreOrder(nbRoot);
					nama=(STRING)malloc(10*sizeof(char));
					printf("\nmasukan nama :");scanf("%s", nama);
					P=Search(Head(Mytree), nama);
					if(P == Nil){
						insTree(&Mytree, nama);
					}
					else{
						printf("nama sudah ada\n");
					}
					FILE* fp = fopen("tree.txt", "w");
					serializeTree(nbRoot, fp);
					fclose(fp);
					getchar();
					printf("apakah ingin insert lagi (y/n) ?");scanf("%c",&ask);
				}
				while(ask == 'y' || ask == 'Y');
				break;
			case 2:
				printf("\nPre Order Non Binary Tree : ");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					nbPreOrder(nbRoot);
				}
				printf("\n\nPre Order Binary Tree : ");
				if(rootBin==NULL){
					printf("Tree Kosong\n");
				}else{
					bPreOrder(rootBin);
				}
				printf("\n\nPre Order Tree AVL : ");
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					bPreOrder(treeAvl.pointer);
				}
				printf("\n");
				system("pause");
				break;
			case 3:
				printf("\nPost Order Non Binary Tree : ");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					nbPostOrder(nbRoot);
				}
				printf("\n\nPost Order Binary Tree : ");
				if(rootBin==NULL){
					printf("Tree Kosong\n");
				}else{
					bPostOrder(rootBin);
				}
				printf("\n\npost Order Tree AVL : ");
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					bPostOrder(treeAvl.pointer);
				}
				printf("\n");
				system("pause");
				break;
			case 4:
				printf("\nIn Order Non Binary Tree : ");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					nbInOrder(nbRoot);
				}
				printf("\n\nIn Order Binary Tree : ");
				if(rootBin==NULL){
					printf("Tree Kosong\n");
				}else{
					bInOrder(rootBin);
				}
				printf("\n\npost Order Tree AVL : ");
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					bInOrder(treeAvl.pointer);
				}
				printf("\n");
				system("pause");
				break;
			case 5:
				printf("\nLevel Order Non Binary Tree : ");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					for(i=0; i<=nbDepth(nbRoot); i++){
						nbLevelOrder(nbRoot,0,i);
					}
				}
				printf("\nLevel Order Binary Tree : ");
				if(rootBin==NULL){
					printf("Tree Kosong\n");
				}else{
					for(i=0; i<=bDepth(rootBin); i++){
						bLevelOrder(rootBin,i);
					}
				}
				printf("\nLevel Order Binary Tree : ");
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					for(i=0; i<=bDepth(treeAvl.pointer); i++){
						bLevelOrder(treeAvl.pointer,i);
					}
				}
				printf("\n");
				system("pause");
				break;
			case 6:
				getLoading();
				printf("\n\n \t\t\t\t\t     *Transform To Binary berhasil *\n");
				rootBin = transformToBin(nbRoot);
    			getchar();
    			getchar();
				break;
			case 7:
				getLoading();
				printf("\n\n \t\t\t\t\t\t  * Balancing selesai *\n");
				CreateBin(&treeAvl);
				Getnode(rootBin,&treeAvl);
				getchar();
				getchar();
				break;
			case 8:
				system("cls");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("Print Tree : \nNon Binary Tree :\n ");
					nbPrintTree(nbRoot, tab); 
				}
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("Binary Tree : \n#: Kanan, *Kiri\n ");
					bPrintTree(rootBin, Nil, false);
				}
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("AVL TREE : \n#: Kanan, *Kiri\n ");
					bPrintTree(treeAvl.pointer, Nil, false);
				}
				system("pause");
				break;
			case 9:
				FILE *fp = fopen("tree.txt", "r");
				if (access("tree.txt", F_OK) == 0){
				    deSerializeTree(nbRoot, fp);
				    fclose(fp);
				    printf("Load Tree Berhasil\n");
				}else{
					printf("File tidak ditemukan\n");
				}
			    system("pause");
				break;
		}
	}while(pilihan != 10);
	return 0;
}



