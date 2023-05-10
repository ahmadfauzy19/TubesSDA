#include "tree.h"
#include <malloc.h>

// List Stack
bool ListEmpty (ListS L){
	 return (L.First == Nil);
}

void CreateList (ListS * L){
	First(*L) = NULL;
}

addressStack AlokasiS(addressBin X){
	/* Kamus Lokal */
	addressStack P;
	/* Algoritma */
	P = (addressStack) malloc (sizeof(ElmStack));
	if (P != Nil){ 	/* Alokasi berhasil */
		P->infoS = X;
		P->next = Nil;
	}else{
		printf("gagall");
	}
	return (P);
}

void EnStack (ListS * L, addressBin X)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	addressStack P;
	 /* Aloritma */
	P = AlokasiS (X);
	if (P != Nil){
		printf("alokasi stack berhasil \n");
		if((*L).First==Nil){ //belum ada root
			P->next = Nil;	
			L->First = P;
		}else{
			P->next = (*L).First;	
			L->First = P;
		}
	}
}

void PrintInfo (ListS L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	addressStack P;
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
			
			 printf("\n");
			 break;
		}
		else	/* Belum berada di akhir List */
		{
			 printf ("%s ", P->infoS->infoB);
			 P = next(P);
		}
		 }
	}
}

void DelStack (ListS * L, addressStack * P)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	printf("\nmasuk delete stack bos\n");
	addressBin X;
	 /* Kamus Lokal */
	addressStack PDel;
	 /* Algoritma */
	PDel = First(*L);
	X = PDel->infoS;
	if (next(PDel)==Nil) /* Hanya 1 elemen */
	{	
		First(*L) = Nil;
	}else {	/* List Lebih dari 1 elemen */	
		First(*L) = next(First(*L));	
	}
//	DeAlokasi (PDel);
	if (PDel != Nil){
		free (PDel);
	}
}

