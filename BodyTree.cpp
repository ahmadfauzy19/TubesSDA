#include <limits.h>
#include <malloc.h>
#include "tree.h"
#include <string.h>



void CreateTree (Tree * L){ //membuat tree baru
	 Head(*L) = Nil;
}

boolean IsEmpty (Tree L){
	if(Head(L)==Nil){
		return true;
	}else{
		return false;
	}	
}

address Alokasi (infotype nama){
	 /* Kamus Lokal */
	address P;
	/* Algoritma */
	P = (address) malloc (sizeof (ElmTree)); //memesan tempat untuk node yang akan dimasukan ke tree
	if (P != Nil)		/* Alokasi berhasil */
	{
		P->info = nama;
		P->nb = Nil;
		P->fs = Nil;
		P->pr = Nil;
	}else{
		printf("alokasi gagal");
		return Nil;
	}
	return (P);
}


void insTree(Tree *L, infotype X){ 
	address newnode, temp, parent_node;
	infotype parent;
	newnode = Alokasi (X); //menampung alokasi node ke newnode
	if(newnode == Nil){
		printf("Alokasi gagal\n");
		return;
	}
	if(Head(*L) != Nil){ //cek tree sudah ada root atau belum
		for(;;){
			printf("## Daftar yang bisa dijadikan Parent ## \n");
//			PreOrder(L);
			parent = (STRING) malloc(10 * sizeof(char)); //alokasi tempat untuk parent
			printf("\nMasukkan parent: ");
			scanf("%10s", parent);
			parent_node = Search(Head(*L), parent); //mencari parent tersedia atau ngga
			if(parent_node != Nil){ //kondisi parent tersedia
				if(Fs(parent_node) != Nil){ //cek mempunyai first son atau ngga
					temp = Fs(parent_node); //menampung sementara first son pada temp
					while(Nb(temp) != Nil){ //loop mencapai next brader terakhir
						temp = Nb(temp);
					}
					Nb(temp) = newnode; //assighment node baru ke next brader
					Pr(newnode)=parent_node; //mengaitkan subvar pointer of parent dari newnode ke parent 
					free(parent); //menghapus alokasi parent untuk menghemat memori
					return;
				}else{ //jika belum mempunyai first son
					Fs(parent_node) = newnode;  //memasukan newnode ke fs dari parent
					Pr(newnode)=parent_node;
					free(parent);
					return;
				}
			}else{
				printf("Parent tidak tersedia\n");
				free(parent);
			}
		}
	}else{
		Head(*L) = newnode;
	}
}




address Search(address P, infotype item){
	address search;
	
	if (P!=Nil){ //jika tree tidak null
		if (strcmp(Info(P),item)==0){ //membandingkan apakah item ketemu atau ngga
			return P; //jika ketemu kembalikan node yang dicari
		}else{ 
			search=Search(Fs(P),item); //pemanggilan rekkursif dengan passing parameter First son
			if (search==Nil){ //jika tidak memiliki Fs dan belum ketemu, maka akan memanggil rekursif dengan passing parameter Nb
				return Search(Nb(P), item); 
			}else{
				return search; //jika tidak memiliki Fs dan tidak memiliki next brader , mengembalikan nilai search
			}
		}
	}
	return Nil; //jika tidak ketemu mengembalikan nilai Nil
}

void PreOrder(Tree P, address root){
	if (root!=NULL){
		printf("%s ", root->info);
		PreOrder(P,root->fs);
		PreOrder(P,root->nb);
	}
//	address curr= Head(*L);
//	boolean Resmi = true;
//	if(IsEmpty(*L)==true){
//		printf("tree kosong...\n");
//		return;
//	}
//	printf(" %s",Info(curr));
//	if(Fs(curr) != Nil) {
//		curr=Fs(curr);
//		printf(" %s",Info(curr));
//		Resmi=true;
//	} else {
//		return;
//	}
//	do{
//		if(Fs(curr) != Nil && Resmi==true){
//			curr=Fs(curr);
//			printf(" %s",Info(curr));
//			Resmi=true;
//		}else if(Nb(curr) != Nil){
//			curr=Nb(curr);
//			printf(" %s",Info(curr));
//			Resmi=true;
//		}else{
//			curr=Pr(curr);
//			Resmi=false;
//		}
//	}while(Pr(curr)!=Nil || Nb(curr)!=Nil);
}

addressBin AlokasiBin (infotype nama){
	 /* Kamus Lokal */
	addressBin P;
	/* Algoritma */
	P = (addressBin) malloc (sizeof (ElmBinTree)); //memesan tempat untuk node yang akan dimasukan ke tree
	if (P != Nil)		/* Alokasi berhasil */
	{
		P->infoB = nama;
		P->left = Nil;
		P->right = Nil;
	}else{
		printf("alokasi gagal");
		return Nil;
	}
	return (P);
}

void transformToBin(Tree L, BinTree *B, address root){
//	addressBin , parent, brother;
	if(!IsEmpty(L)){
//		address curr= Head(*L);
//		boolean Resmi = true;
//		printf(" %s",Info(curr));
//		P = AlokasiBin(Info(curr));
//		if(Fs(curr) != Nil) {
//			curr=Fs(curr);
//			printf(" %s",Info(curr));
//			parent = (addressBin) malloc (sizeof (ElmBinTree));
//			parent = P;
//			P = AlokasiBin(Info(curr));
//			temp->left = P; 
//			free(P);
//			free(parent);
//			Resmi=true;
//		} else {
//			return;
//		}
//		do{
//			if(Fs(curr) != Nil && Resmi==true){
//				curr=Fs(curr);
//				printf(" %s",Info(curr));
//				parent = (addressBin) malloc (sizeof (ElmBinTree));
//				parent = P;
//				P = AlokasiBin(Info(curr));
//				parent->left = P; 
//				free(P);
////				free(temp);
//				Resmi=true;
//			}else if(Nb(curr) != Nil){
//				curr=Nb(curr);
//				printf(" %s",Info(curr));
//				P = AlokasiBin(Info(curr));
//				temp->right = P;
//				temp = P;
//				free(P);
//				Resmi=true;
//			}else{
//				curr=Pr(curr);
//				Resmi=false;
//			}
//		}while(Pr(curr)!=Nil || Nb(curr)!=Nil);

        addressBin P = (addressBin) malloc(sizeof(ElmBinTree));
        P->infoB = root->info;
        P->left = NULL;
        P->right = NULL;

        if (root->fs != NULL) {
            // konversi tipe data dari address menjadi addressBin
            addressBin child = (addressBin) malloc(sizeof(ElmBinTree));
            child->infoB = root->fs->info;
            child->left = NULL;
            child->right = NULL;

            P->left = child;
            // rekursif memproses child pertama
            transformToBin(L, B, root->fs);
        }

        if (root->nb != NULL) {
            // konversi tipe data dari address menjadi addressBin
            addressBin sibling = (addressBin) malloc(sizeof(ElmBinTree));
            sibling->infoB = root->nb->info;
            sibling->left = NULL;
            sibling->right = NULL;

            P->right = sibling;
            // rekursif memproses sibling berikutnya
            transformToBin(L, B, root->nb);
        }

        // mengubah pointer pada B menjadi P
        (*B).pointer = P;
	}
	else{
		printf("Tree Kosong\n");
	}
}

void preOrder(addressBin B) {
    if (B == NULL){
        return;
    }
    printf("%s ", B->infoB);
    preOrder(B->left);
    preOrder(B->right);
}




