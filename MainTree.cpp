#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	/* Kamus Lokal */
<<<<<<< HEAD
	address P,Q, Pre;
=======
	address P,*Q, nbRoot = NULL;
	addressBin rootBin = NULL;
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
	Tree Mytree;
	BinTree Btree;
	infotype nama,buku;
	int pilihan, currlevel,deslevel;
	char ask;
		
	/* Program */
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
		printf(" 9. Exit\n");
		printf("masukan pilihan :");scanf("%d",&pilihan);
		switch(pilihan){
			case 1:
				do{
					system("cls");
					printf("**tampilan preorder **\n");
<<<<<<< HEAD
					Q=Mytree.head;
					PreOrder(&Mytree, Q);
=======
					nbRoot = Mytree.head;
					nbPreOrder(nbRoot);
					Q=&Mytree.head;
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
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
<<<<<<< HEAD
				Pre = Mytree.head;
				PreOrder(&Mytree, Pre);
=======
				printf("\nPre Order Non Binary Tree : ");
				nbRoot = Mytree.head;
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
				system("pause");
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
//				LevelOrderTraversal(Mytree);
				break;
			case 6:
				printf("Transform ke binary ...\n");
//				Pre = Mytree.head;
<<<<<<< HEAD
				transformToBin(Mytree, &Btree);
//				preOrder(Btree.pointer);
//				system("Pause");
=======
				nbRoot = Mytree.head;
				rootBin = transformToBin(nbRoot);
				system("Pause");
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
				break;
			case 7:
				break;
			case 8:
				break;
		}
	}while(pilihan != 9);
	 
	return 0;
}



