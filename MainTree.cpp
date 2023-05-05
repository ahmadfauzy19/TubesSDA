#include "Tree.h"
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	/* Kamus Lokal */
	address P,*Q, nbRoot = NULL;
	addressBin rootBin = NULL;
	Tree Mytree;
	BinTree Btree;
	infotype nama,buku;
	int pilihan, i;
	char ask;
		
	/* Program */
	splashScreen();
	CreateTree (&Mytree);
	do{
		system("cls");
		printf("\nMenu :\n");
		printf(" 1. Insert Tree Non-Binary\n");
		printf(" 2. Pre Order\n");
		printf(" 3. Post Order\n");
		printf(" 4. In Order\n");
		printf(" 5. Level Order\n");
		printf(" 6. Transform to Binary\n");
		printf(" 7. AVL\n");
		printf(" 8. Print Tree\n");
		printf(" 9. Exit\n");
		printf("masukan pilihan :");scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				do{
					system("cls");
					printf("**tampilan preorder **\n");
					nbRoot = Mytree.head;
					nbPreOrder(nbRoot);
					Q=&Mytree.head;
					nama=(STRING)malloc(10*sizeof(char));
					printf("\nmasukan nama :");scanf("%s", nama);
					P=Search(Head(Mytree), nama);
					if(P == Nil){
						insTree(&Mytree, nama);
					}else{
						printf("nama sudah ada\n");
					}
				getchar();
				printf("apakah ingin insert lagi (y/n) ?");scanf("%c",&ask);
				}while(ask == 'y' || ask == 'Y');
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
				printf("\n");
				system("pause");
				break;
			case 6:
				printf("Transform ke binary ...\n");
				rootBin = transformToBin(nbRoot);
				system("Pause");
				break;
			case 7:
				break;
			case 8:
				system("cls");
				char tab[]="";
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("Print Tree : \nNon Binary Tree :\n ");
					nbPrintTree(nbRoot, tab); 
				}
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("Binary Tree : \n+: Kanan, -Kiri\n ");
					bPrintTree(rootBin, tab, -1);
				}
				system("pause");
				break;
		}
	}while(pilihan != 9);
	 
	return 0;
}



