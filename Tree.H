#ifndef Tree_H
#define Tree_H
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define Nil NULL
#define Info(P) (P)->info
#define InfoB(P) (P)->infoB
#define InfoS(P) (P)->infoS
#define Nb(L) (L)->nb
#define Fs(L) (L)->fs
#define Pr(L) (L)->pr
#define First(P) (P).First
#define next(P) (P)->next
#define Head(P) (P).head
#define Pointer(P) (P).pointer
#define STRING char*

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

typedef STRING infotype;
typedef struct tElmTree *address;
typedef struct tElmTree{
	infotype info;
	address fs;
	address nb;
	address pr;
	} ElmTree;


typedef struct {
	  address head;
} Tree;

typedef struct tElmBinTree *addressBin;
typedef struct tElmBinTree{
	infotype infoB;
	addressBin left;
	addressBin right;
	int lvl;
	} ElmBinTree;


typedef struct {
	  addressBin pointer;
} BinTree;


//Adrian
addressBin transformToBin(address nbRoot);
addressBin AlokasiBin (infotype nama);
/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan Tree ****/
bool IsEmpty (Tree L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateTree (Tree * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
address Alokasi (infotype nama);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void insTree(Tree *L, infotype X);

address Search(address P, infotype item);

void bPreOrder(addressBin root);
void bInOrder(addressBin root);
void bPostOrder(addressBin root);
void nbPreOrder(address root);
void nbInOrder(address root);
void nbPostOrder(address root);
void nbLevelOrder(address root, int curLevel, int desLevel);
int nbDepth(address root);
void bLevelOrder(addressBin root, int level);
int bDepth(addressBin root);

void serializeTree(address root, FILE *fp);
int deSerializeTree(address &root, FILE *fp);

//kamus data stack
typedef struct tElmStack *addressStack;
typedef struct tElmStack{
	addressBin infoS;
	addressStack next;
}ElmStack;

typedef struct {
	addressStack First;
} ListS;

bool ListEmpty (ListS L);
void CreateList (ListS * L);
addressStack AlokasiS (addressBin X);
void EnStack (ListS * L, addressBin X);
void PrintInfo (ListS L);
void DelStack (ListS * L, addressStack *P);

//AVL
void Getnode(addressBin head, BinTree *root);
void insAVL(infotype X,BinTree *root);
void CreateBin(BinTree *B);
bool cmprAVL(infotype A, infotype B);
void updatelevel(addressStack *head);
void levelafterRotate(addressBin *head);
addressBin AlokasiAVL(infotype nama);
void balancing(ListS *MyStack, addressBin *root);
addressBin SingleRotasiKiri(addressBin *node);
addressBin DoubleRotateKananKiri(addressBin *node);
addressBin SingleRotasiKanan(addressBin *node);
addressBin DoubleRotateKiriKanan(addressBin *node);

//void DeAlokasi (address P);
///* IS : P terdefinisi */
///* FS : P dikembalikan ke sistem */
///* Melakukan dealokasi / pengembalian address P ke system */
//
///**** Pencarian sebuah elemen List ****/
//address Search (List L, infotype X);
///* Mencari apakah ada elemen list dengan Info(P) = X */
///* Jika ada, mengirimkan address elemen tsb. */
///* Jika tidak ada, mengirimkan Nil */
//
//boolean FSearch (List L, address P);
///* Mencari apakah ada elemen list yang beralamat P */
///* Mengirimkan true jika ada, false jika tidak ada */
//
//address SearchPrec (List L, infotype X);
///* Mengirimkan address elemen sebelum elemen yang nilainya = X */
///* Mencari apakah ada elemen list dengan Info(P) = X */
///* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
///* Jika tidak ada, mengirimkan Nil */
///* Jika P adalah elemen pertama, maka Prec = Nil */
///* Search dengan spesifikasi seperti ini menghindari */
///* traversal ulang jika setelah Search akan dilakukan operasi lain */
//
///**** PRIMITIF BERDASARKAN NILAI ****/
///**** Penambahan Elemen ****/
//void InsVFirst (List * L, infotype X);
///* IS : L mungkin Kosong */
///* FS : melakukan alokasi sebuah elemen dan */
///* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
//
//void InsVLast (List * L, infotype X);
///* IS : L mungkin Kosong */
///* FS : melakukan alokasi sebuah elemen dan */
///* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
///* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
//
///**** Penghapusan Elemen ****/
//void DelVFirst (List * L, infotype * X);
///* IS : L TIDAK Kosong */
///* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
///* 	dan alamat elemen pertama di dealokasi */
//
//void DelVLast (List * L, infotype * X);
///* IS : L TIDAK Kosong */
///* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
///* 	dan alamat elemen terakhir di dealokasi */
//
///**** PRIMITIF BERDASARKAN ALAMAT ****/
///**** Penambahan elemen berdasarkan alamat ****/
//void InsertFirst (List * L, address P);
///* IS : L sembarang, P sudah dialokasi */
///* FS : menambahkan elemen ber-address P sebagai elemen pertama */
//
//void InsertAfter (List * L, address P, address Prec);
///* IS : Prec pastilah elemen List dan bukan elemen terakhir */
///*	P sudah dialokasi */
///* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
//
//void InsertLast (List * L, address P);
///* IS : L sembarang, P sudah dialokasi */
///* FS : P ditambahkan sebagai elemen terakhir yang baru */
//
///**** Penghapusan sebuah elemen ****/
//void DelFirst (List * L, address * P);
///* IS : L TIDAK kosong */
///* FS : P adalah alamat elemen pertama list sebelum penghapusan */
///*	elemen list berkurang satu (mungkin menjadi kosong) */
///* First elemen yang baru adalah suksessor elemen pertama yang lama */
//
//void DelP (List * L, infotype X);
///* IS : L sembarang */
///* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
///* 	Maka P dihapus dari list dan di dealokasi */
///* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
///* List mungkin menjadi kosong karena penghapusan */
//
//void DelLast (List * L, address * P);
///* IS : L TIDAK kosong */
///* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
///*	Elemen list berkurang satu (mungkin menjadi kosong) */
///* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
//
//void DelAfter (List * L, address * Pdel, address Prec);
///* IS : L TIDAK Kosong, Prec adalah anggota List */
///* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
//
///**** PROSES SEMUA ELEMEN LIST  ****/
//void PrintInfo (List L);
///* IS : L mungkin kosong */
///* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
///*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
//
//
///***************************************/
///*******  PROSES TERHADAP LIST  ********/
///***************************************/
//
//void DelAll (List * L);
///* Delete semua elemen list dan alamat elemen di dealokasi */


#endif
