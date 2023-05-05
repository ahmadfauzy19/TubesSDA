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
	address newnode, temp, parent_node, root = (*L).head;
	infotype parent;
	newnode = Alokasi (X); //menampung alokasi node ke newnode
	if(newnode == Nil){
		printf("Alokasi gagal\n");
		return;
	}
	if(Head(*L) != Nil){ //cek tree sudah ada root atau belum
		for(;;){
			printf("## Daftar yang bisa dijadikan Parent ## \n");
			nbPreOrder(root);
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

//void nbPreOrder(address root){
//	if (root!=NULL){
//		printf("%s ", root->info);
//		nbPreOrder(root->fs);
//		nbPreOrder(root->nb);
//	}
//		address curr= Head(*L);
//		boolean Resmi = true;
//		if(IsEmpty(*L)==true){
//			printf("tree kosong...\n");
//			return;
//		}
//		printf(" %s",Info(curr));
//		if(Fs(curr) != Nil) {
//			curr=Fs(curr);
//			printf(" %s",Info(curr));
//			Resmi=true;
//		} else {
//			return;
//		}
//		do{
//			if(Fs(curr) != Nil && Resmi==true){
//				curr=Fs(curr);
//				printf(" %s",Info(curr));
//				Resmi=true;
//			}else if(Nb(curr) != Nil){
//				curr=Nb(curr);
//				printf(" %s",Info(curr));
//				Resmi=true;
//			}else{
//				curr=Pr(curr);
//				Resmi=false;
//			}
//		}while(Pr(curr)!=Nil || Nb(curr)!=Nil);
//}



