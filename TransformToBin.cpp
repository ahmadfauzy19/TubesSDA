#include "tree.h"
#include <malloc.h>

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
