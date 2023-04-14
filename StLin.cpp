#include <stdlib.h>
#include "spnrsll.h"
#include <stdio.h>



//typedef STRING infotype;
//typedef struct tElmtList *address;
//typedef struct tElmtList {
//	 infotype info;
//	 address  next;
//	 } ElmtList;
	 
//typedef struct {
//	address First;
//} List;

int main()
{
	/* Kamus Lokal */
		List MyList[5];
		int i,j;
		char Kota[50];
//		infotype isi;
		address P, Prec;

	/* Program */
	for(i=0;i<5;i++){
	CreateList (&MyList[i]);
	}
//masukan nama kota
	printf("masukan nama kota \n");
	for(i=0;i<5;i++){
	scanf("%s",Kota);
/* Menambah List di awal */
	InsVLast (&MyList[i],Kota);
	}
	printf ("Hasil InsVFirst 5 x adalah : "); PrintInfo (MyList[i]);
}

	


