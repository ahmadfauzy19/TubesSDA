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

void awal();
void TampilanAwal();
void tentang();

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

addressBin transformToBin(address nbRoot);
addressBin AlokasiBin (infotype nama);

bool IsEmpty (Tree L);

int countNodes(address root);

int countSubtreeNodes(address node);

void CreateTree (Tree * L);

address Alokasi (infotype nama);

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

//file
void serializeTree(address root, FILE *fp);
int deSerializeTree(address &root, FILE *fp);
bool fileExists(const char *file_name);
void fixName(const char *file_name, char *new_name);
bool has_txt_extension(char const *name);

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
void connectAVL(addressStack *nextnode, addressBin *node);
void levelafterRotate(addressBin *head);
addressBin AlokasiAVL(infotype nama);
void balancing(ListS *MyStack, addressBin *root);
addressBin SingleRotasiKiri(addressBin *node);
addressBin DoubleRotateKananKiri(addressBin *node);
addressBin SingleRotasiKanan(addressBin *node);
addressBin DoubleRotateKiriKanan(addressBin *node);

//delete
void DeleteTree(address* root1,addressBin* root2,addressBin* root3);
void deleteNB(address *root);
void DeleteB(addressBin *root);

#endif
