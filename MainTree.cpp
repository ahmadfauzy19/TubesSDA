#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "UI.h"
#include <time.h>
#include <dirent.h>

int main(){
	/* Kamus Lokal */
	address P,*Q, nbRoot = NULL;
	addressBin rootBin = NULL;
	BinTree treeAvl;
	treeAvl.pointer = NULL;
	Tree Mytree;
	BinTree Btree;
	infotype nama;
	int pilihan, i, hasFile, a, chooseFile=0, x, y, x2, y2;
	char ask;
	char tab[]="", nameFile[20], newName[20], listFile[100][20];
	FILE* fp;
    DIR *dir;
    struct dirent *ent;
	
	/* Program */
	awal();
	system("cls");
	splashScreen();
	CreateTree (&Mytree);
	do{
		system("cls");
		TampilanAwal();
		printf("masukan pilihan :");scanf("%d",&pilihan);
		getchar();
		switch(pilihan){
			case 1:
				hasFile = 0;
				if (nbRoot == Nil){
					do{
						system("cls");
						printf("--Insert Tree pada File Baru--\n");
						if (hasFile != 0){
							printf("!File %s telah ada. Lakukan load tree pada menu untuk menggunakan file tersebut!\n", newName);	
						}
						printf("masukan nama file (0. untuk kembali): "); scanf("%s", nameFile);
						if(strcmp(nameFile, "0") != 0){
							fixName(nameFile, newName);
							if(fileExists(newName)){
								hasFile = 1;
							}else{
								hasFile = 0;
							}	
						}
					}while(hasFile == 1 && strcmp(nameFile, "0"));
				}
				if(strcmp(nameFile, "0") != 0){
					do{
						if (nbRoot == Nil){
							nbRoot = Mytree.head;
						}else{
							Mytree.head = nbRoot;
						}
						system("cls");
						printf("**tampilan preorder **\n");
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
						fp = fopen(newName, "w");
						serializeTree(nbRoot, fp);
						fclose(fp);
						getchar();
						printf("apakah ingin insert lagi (y/n) ?");scanf("%c",&ask);
					}
					while(ask == 'y' || ask == 'Y');
				}
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
				if(nbRoot == NULL){
					printf("\n\t\t\t\t\t\t * Tree Kosong *\n\n");
					getchar();
					getchar();
					break;
				}
				system("cls");
				printf("\n\n     *Transform To Binary berhasil *\n");
				rootBin = transformToBin(nbRoot);
				printf(" ======================================\n");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf(" sebelum transform \n");
					printf("Print Tree : \nNon Binary Tree :\n ");
					nbPrintTree(nbRoot, tab); 
				}
				printf("\n ======================================\n");
				if(nbRoot==NULL){
					printf("Tree Kosong\n");
				}else{
					printf(" setelah transform \n");
					printf("Binary Tree : \n+: Kanan, -Kiri\n ");
					bPrintTree(rootBin, Nil, false);
				}
				printf(" ======================================\n");
    			printf("enter untuk kembali ke menu...");
				getchar();
				break;
			case 7:
				getLoading();
				if(rootBin==NULL){
					printf("\n\t\t\t\t\t\t * Transform terlebih dahulu *\n\n");
					getchar();
					getchar();
					break;
				}
				system("cls");
				printf("\n\t * Balancing selesai *\n\n");
				CreateBin(&treeAvl);
				Getnode(rootBin,&treeAvl);
				printf(" ======================================\n");
				printf("\n Sebelum Balancing \n");
				printf(" ______________________________________\n");
				printf("\nBinary Tree : \n");
				bPrintTree(rootBin, Nil, false);
				printf(" ======================================\n");
				printf("\n Setelah Balancing \n");
				printf(" ______________________________________\n");
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong\n");
				}else{
					printf("\nAVL TREE : \n");
					bPrintTree(treeAvl.pointer, Nil, false);
				}
				printf(" ======================================\n");
				printf("enter untuk kembali ke menu...");
				getchar();
				break;
			case 8:
				system("cls");
				gotoxy(0,1);
				printf("\n\t TAMPILAN SEMUA TREE \n");
				gotoxy(0,3);
				printf(" ======================================");
				x=getX();
				gotoxy(0,5);
				if(nbRoot==NULL){
					printf("Tree Kosong");
				}else{
					printf("Non Binary Tree :");
					nbPrint(nbRoot, 20, countNodes(nbRoot)*2, getY()+2);
				}
				gotoxy(x+2, 3);
				printf(" ======================================");
				x2=getX();
				gotoxy(x+2, 5);
				if(rootBin==NULL){
					printf("Tree Kosong");
				}else{
					printf("Binary Tree : ");
					y = getY();
					bPrint(rootBin, x+12, 10, y+2);
				}
				y2 = getY();
				gotoxy(x2+2, 3);
				printf("======================================");
				gotoxy(x2+2,5);
				if(treeAvl.pointer==NULL){
					printf("Tree Kosong");
				}else{
					printf("AVL TREE :");
					y=getY();
					bPrint(treeAvl.pointer, x2+12 , 10, y+2);
				}
				gotoxy(0, y2+2);
				printf("enter untuk kembali ke menu...");
				getchar();
				break;
			case 9:
				a = 0;
				dir = opendir (".");
				getLoading();
				system("cls");
				//cek direktori dan mendapatkan nama file
				printf("**Daftar File**\n");
				if(dir != Nil){
					while ((ent = readdir (dir)) != NULL){
				        if(has_txt_extension(ent->d_name) && strcmp(ent->d_name, "tentang.txt")){
				        	strcpy(listFile[a], ent->d_name);
				        	printf("%d. %s\n", a+1, listFile[a]);
				        	a++;
				    	}
				    }
				    closedir(dir);
				}else {
			        printf("Tidak bisa membuka direktori");
			    }
			    printf("Pilih File (1-%d) : ", a); scanf("%d", &chooseFile);
			    getchar();
			    if (chooseFile != 0 && chooseFile <= a){
					FILE *fp = fopen(listFile[chooseFile-1], "r");
					deSerializeTree(nbRoot, fp);
					fclose(fp);
					getLoading();
					system("cls");
					printf("\n\n \t\t\t\t\t  * load file %s berhasil *\n\n", listFile[chooseFile-1]);
					printf("\t\t\t   Data yang berhasil ditambahkan = ");nbPreOrder(nbRoot);	
				}else{
					printf("!File tidak ada. Masukkan inputan yang benar!");
				}
				getchar();
				break;
			case 10:
				a = 0;
				dir = opendir (".");
				getLoading();
				system("cls");
				//cek direktori dan mendapatkan nama file
				printf("**Daftar File**\n");
				if(dir != Nil){
					while ((ent = readdir (dir)) != NULL){
				        if(has_txt_extension(ent->d_name) && strcmp(ent->d_name, "tentang.txt")){
				        	strcpy(listFile[a], ent->d_name);
				        	printf("%d. %s\n", a+1, listFile[a]);
				        	a++;
				    	}
				    }
				    closedir(dir);
				}else {
			        printf("Tidak bisa membuka direktori");
			    }
			    printf("Pilih File (1-%d) : ", a); scanf("%d", &chooseFile);
			    getchar();
			    if (chooseFile != 0 && chooseFile <= a){
					FILE *fp = fopen(listFile[chooseFile-1], "r");
					fclose(fp);
					remove(listFile[chooseFile-1]);
					getLoading();
					system("cls");
					printf("\n\n \t\t\t\t\t  * delete file %s berhasil *\n\n", listFile[chooseFile-1]);	
				}else{
					printf("!File tidak ada. Masukkan inputan yang benar!");
				}
				getchar();
				break;
				break;
			case 11:
				DeleteTree(&nbRoot, &rootBin, &treeAvl.pointer);
				break;
			default:
				printf("masukan pilihan dengan benar !!\n");
				getchar();
				break;
		}
	}while(pilihan != 12);
	return 0;
}



