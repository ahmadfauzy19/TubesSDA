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
<<<<<<< HEAD
	address newnode, temp, parent_node,root;
=======
	address newnode, temp, parent_node, root = (*L).head;
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
	infotype parent;
	root=Head(*L);
	newnode = Alokasi (X); //menampung alokasi node ke newnode
	if(newnode == Nil){
		printf("Alokasi gagal\n");
		return;
	}
	if(Head(*L) != Nil){ //cek tree sudah ada root atau belum
		for(;;){
			printf("## Daftar yang bisa dijadikan Parent ## \n");
<<<<<<< HEAD
			PreOrder(L,root);
=======
			nbPreOrder(root);
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
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

<<<<<<< HEAD
void PreOrder(Tree *P, address root){
	if(IsEmpty(*P)==true){
		printf("tree kosong...\n");
		return;
	}
=======
void nbPreOrder(address root){
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
	if (root!=NULL){
		printf("%s ", root->info);
		nbPreOrder(root->fs);
		nbPreOrder(root->nb);
	}
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
}



// List Queue
boolean ListEmpty (ListQ L){
	 return (L.First == Nil);
}

void CreateList (ListQ * L){
	First(*L) = NULL;
	Rear(*L) = NULL;
}

addressQueue AlokasiQ (address X){
	/* Kamus Lokal */
	addressQueue P;
	/* Algoritma */
	P = (addressQueue) malloc (sizeof (ElmQueue));
	if (P != Nil){ 	/* Alokasi berhasil */
		P->infoQ = X;
		P->next = Nil;
	}
	return (P);
}

void DeAlokasi (addressQueue P){
	if (P != Nil){
	free (P);
	}
}

void Enqueue (ListQ * L, address X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	addressQueue P;
	 /* Aloritma */
	P = AlokasiQ (X);
	if (P != Nil){
		printf("alokasi berhasil \n");
		if((*L).First==Nil){ //belum ada root
			P->next = Nil;	
			L->First = P;
			L->Rear= P;
		}else{
			P->next = Nil;	
			L->Rear = P;
		}
	}
}

void DelQueue (ListQ * L, addressQueue * P)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	address X;
	 /* Kamus Lokal */
	addressQueue PDel;
	 /* Algoritma */
	PDel = First(*L);
	X = PDel->infoQ;
	if (Next(PDel)==Nil) /* Hanya 1 elemen */
	{	
		First(*L) = Nil;
		Rear(*L) = Nil;
	}else {	/* List Lebih dari 1 elemen */	
		First(*L) = Next(First(*L));	
	}
	DeAlokasi (PDel);
}





//void LevelOrderTraversal(Tree L) {
//    ListQ Q;
//    address curr;
//    addressQueue current;
//    if (IsEmpty(L)) {
//        printf("tree kosong...");
//        return;
//    }
//    curr = Head(L);
//    CreateList(&Q);
//    Enqueue(&Q, Info(curr));
//    while (!ListEmpty(Q)) {
//        current = Dequeue(&Q);
//        printf(" %s ", Info(curr));
//        if (Fs(curr) != Nil) {
//            Enqueue(&Q, Fs(curr));
//            address sibling = Nb(Fs(curr));
//            while (sibling != Nil) {
//                Enqueue(&Q, sibling);
//                sibling = Nb(sibling);
//            }
//        }
//    }
//}

//tranformasi non binary ke binary
void CreateBTree (BinTree * L){
	(*L).rootBin = Nil;
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
		printf("alokasi binary berhasil..");
	}else{
		printf("alokasi gagal");
		return Nil;
	}
	return (P);
}

<<<<<<< HEAD

//void insBTree(BinTree * L, infotype nama){
//	addressBin newnode;
//	newnode = AlokasiBin (nama);
//	if(newnode == Nil){
//		printf("Alokasi gagal..");
//		return;
//	}
//	if(((*L).rootBin != Nil)){
//		
//	}
//}


void transformToBin(Tree L, BinTree *B){
	address curr,temp; 
	int cek=0;
	addressBin nodeBin, currBin;
	ListQ queue;
	addressQueue Awal;
	infotype item;
	if(IsEmpty(L)==true){
		printf("tree kosong...\n");
		return;
	}
	curr = Head(L);
	CreateBTree (B);
	CreateList (&queue);
	Enqueue (&queue, curr);
	Awal = First(queue);
	curr = InfoQ(Awal);
	while(curr != Nil){
		printf(" loop ke %d \n",cek++);
//		if(B->rootBin!=Nil){
			if(Fs(curr)!=Nil){ //mempunyai first son
				printf("cek fs \n");
				printf(" loop fs ke %d \n",cek);
				curr = Fs(curr);
				Enqueue (&queue, curr);
//				nodeBin = AlokasiBin (queue.Rear->infoQ->info);
//				currBin->left=nodeBin;
//				DelQueue (&queue,  &Awal);
				printf("cek aja \n");
				if(Nb(curr) != Nil){ // mempunyai next brother
					printf(" loop nb ke %d \n",cek);
					printf("cek nb \n");
					temp = Nb(curr);
					while(temp != Nil){
						Enqueue (&queue, temp );
						temp = Nb(temp);
					}
//					nodeBin = AlokasiBin (queue.Rear->infoQ->info);
//					currBin->right=nodeBin;
//					DelQueue (&queue,  &Awal);
				}
			}
			PrintInfo (queue);
			printf("%s",Awal->infoQ->info);
			Awal = Awal->next;
			printf("%s",Awal->infoQ->info);
			curr = 	InfoQ(Awal);
			printf("%s",Awal->infoQ->info);
//		}else{
//			printf("cek \n");
////			nodeBin = AlokasiBin (queue.Rear->infoQ->info);
////			B->rootBin = nodeBin;
////			currBin = B->rootBin;
//			Awal = queue.First;
//			printf("root binary telah dibuat yaitu %s",B->rootBin->infoB);
//			if(queue.First.next==Nil){
//				DelQueue (&queue,  &Awal);
//			}
//		}
	}
	PrintInfo (queue);
}

//void transformToBin(Tree L, BinTree *B){
//    address curr,temp;
//    addressBin nodeBin, currBin;
//    ListQ queue;
//    addressQueue Awal;
//    infotype item;
//    if(IsEmpty(L)==true){
//        printf("tree kosong...\n");
//        return;
//    }
//    curr = Head(L);
//    CreateBTree(B);
//    CreateList(&queue);
//    Enqueue(&queue, curr);
//    while(ListEmpty(queue) != Nil){
//    	Awal = queue.First;	
//        temp = queue.First->infoQ;
//        DelQueue(&queue,&Awal);
//        if(B->rootBin == Nil){
//            nodeBin = AlokasiBin(Info(temp));
//            B->rootBin = nodeBin;
//            currBin = B->rootBin;
//            Awal = queue.First;
//        }
//        else{
//            if(Fs(temp) != Nil){ //mempunyai first son
//                curr = Fs(temp);
//                Enqueue(&queue, curr);
//                nodeBin = AlokasiBin(Info(curr));
//                currBin->left = nodeBin;
//                currBin = nodeBin;
//                if(Nb(curr) != Nil){ // mempunyai next brother
//                    curr = Nb(curr);
//                    while(curr != Nil){
//                        Enqueue(&queue, curr);
//                        nodeBin = AlokasiBin(Info(curr));
//                        currBin->right = nodeBin;
//                        currBin = nodeBin;
//                        curr = Nb(curr);
//                    }
//                }
//            }
//        }
//    }
//    printf("periksa preorder bin tree\n");
//    preOrder(B->rootBin);
//}


void preOrder(addressBin B) {
=======
addressBin transformToBin(address nbRoot){
    if(nbRoot == NULL) return NULL;

    addressBin bRoot = AlokasiBin(nbRoot->info);

    if(nbRoot->fs != NULL){
        bRoot->left = transformToBin(nbRoot->fs);
        address nbChild = nbRoot->fs;
        addressBin bChild = bRoot->left;

        while(nbChild->nb != NULL){
            bChild->right = transformToBin(nbChild->nb);
            nbChild = nbChild->nb;
            bChild = bChild->right;
        }
    }
    return bRoot;
}

void bPreOrder(addressBin B) {
>>>>>>> 140138136719b682505eafb85527c48ba46cb144
    if (B == NULL){
    	printf("binary tree kosong...");
        return;
    }
    printf("%s ", B->infoB);
    bPreOrder(B->left);
    bPreOrder(B->right);
}

void PrintInfo (ListQ L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	addressQueue P;
	 /* Algoritma */
	if (First(L) == Nil)
	{
		 printf ("List Kosong .... \a\n");
	}
	else	/* List memiliki elemen */
	{
		 P = First(L);
		 for (;;)
		 {
		if (P==Nil)
		{
			
			 printf("berakhir \n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("%s ", P->infoQ->info);
			 P = Next(P);
		}
		 }
	}
}

