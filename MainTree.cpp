#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main(){
	/* Kamus Lokal */
	address P,*Q, Pre;
	Tree Mytree;
	BinTree Btree;
	infotype nama,buku;
	int pilihan;
	char ask;
		
	/* Program */
	CreateTree (&Mytree);
	do{
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
//					PreOrder(&Mytree);
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
				Pre = Mytree.head;
				PreOrder(Mytree, Pre);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
//				printf("Transform ke binary ...\n");
//				Pre = Mytree.head;
//				transformToBin(Mytree, &Btree, Pre);
//				preOrder(Btree.pointer);
//				system("Pause");
				break;
			case 7:
				break;
			case 8:
				break;
		}
	}while(pilihan != 9);
	 
	return 0;
}




