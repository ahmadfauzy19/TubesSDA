#include "tree.h"
#include <string.h>

void CreateBin(BinTree *B) {
	Pointer(*B) = Nil;
}

bool cmprAVL(infotype A, infotype B) {
	if(A[0] >= B[0]) {
		return true;
	} else {
		return false;
	}
}

void Getnode(addressBin head, BinTree *root){
	if (head == NULL) {
		return;
	}
	insAVL(head->infoB,root);
	Getnode(head->left,root);
	Getnode(head->right,root);
}

addressBin AlokasiAVL(infotype nama) {
	addressBin P;
	P = (addressBin) malloc (sizeof (ElmBinTree));
	P->infoB = nama;
	P->left = Nil;
	P->right = Nil;
	P->lvl = 1;
	if(P==Nil) {
		printf("alokasi gagal");
	}
	return (P);
}

void updatelevel(addressStack *head) {
	if(*head==Nil) {
		return;
	}
	(*head)->infoS->lvl++;
	updatelevel(&(*head)->next);
}

void connectAVL(addressStack* nextnode, addressBin* node, addressBin* root, addressBin curr) {
    if (*nextnode != Nil) {
        if ((*nextnode)->infoS->left == curr) {
            (*nextnode)->infoS->left = *node;
        }
        else if ((*nextnode)->infoS->right == curr) {
            (*nextnode)->infoS->right = *node;
        }
    }
    else {
        *root = *node;
    }
}


void levelafterRotate(addressBin *head) {
	if((*head)->left != Nil && (*head)->right != Nil) {
		if((*head)->left->lvl >= (*head)->right->lvl ){
			(*head)->lvl = (*head)->left->lvl + 1;
		}
		else {
			(*head)->lvl = (*head)->right->lvl + 1;
		}
	}
	else if((*head)->left != Nil || (*head)->right != Nil){
		if((*head)->left != Nil){
			(*head)->lvl = (*head)->left->lvl + 1;
		}
		else {
			(*head)->lvl = (*head)->right->lvl + 1;
		}
	}
	else {
		(*head)->lvl = 1;
	}
}

addressBin SingleRotasiKiri(addressBin *node) {
	addressBin partner,othernode;
	partner = (*node)->right;
	(*node)->right = partner->left;
	partner->left = *node;
	(*node) = partner;
	levelafterRotate(&partner->left);
	return *node;
}

addressBin DoubleRotateKananKiri(addressBin *node){
	addressBin othernode,subkanan,subkiri;
	//tampung node
	subkanan=(*node)->right;
	subkiri=subkanan->left;
	
	//rotasi
	(*node)->right=subkiri;
	subkanan->left=subkiri->right;
	subkiri->right=subkanan;
	(*node)=SingleRotasiKiri(node);
	return *node;
}

addressBin SingleRotasiKanan(addressBin *node) {
	addressBin partner,othernode;
	partner = (*node)->left;
	(*node)->left = partner->right;
	partner->right = *node;
	(*node) = partner;
	levelafterRotate(&partner->right);
	return *node;
}

addressBin DoubleRotateKiriKanan(addressBin *node){
	addressBin othernode,subkanan,subkiri;
	//tampung node
	subkiri=(*node)->left;
	subkanan=subkiri->right;
	
	//rotasi
	(*node)->left=subkanan;
	subkiri->right=subkanan->left;
	subkanan->left=subkiri;
//	*node=SingleRotasiKanan(node);
	return *node;
}

void insAVL(infotype X, BinTree *root) {
	// kamus data lokal
	addressBin newnode,curr;
	ListS MyStack;
	int j=1;
	//create baru
	CreateList (&MyStack);
	//Algoritma
	newnode = AlokasiAVL (X);
	if ((*root).pointer == Nil) {
		(*root).pointer = newnode;
		(*root).pointer->lvl=j;
		EnStack (&MyStack,(*root).pointer);
	}
	else {
		curr = (*root).pointer;
		while(curr != Nil) {
			EnStack (&MyStack, curr);
			if(cmprAVL( InfoB(curr) , InfoB(newnode))){
				if(curr->left == Nil) {
					curr->left = newnode;
					updatelevel(&MyStack.First);
					break;
				}
				else {
					curr = curr->left;
				}
			}
			else {
				if(curr->right == Nil) {
					curr->right = newnode;
					updatelevel(&MyStack.First);
					break;
				}
				else {
					curr = curr->right;
				}
			}
		}
	}
	balancing(&MyStack, &((*root).pointer));
	return;
}



void balancing(ListS *MyStack, addressBin *root) {
	addressBin node,temp, updatenode,othernode;
	addressStack Nnode;
	while(MyStack->First != Nil){
		node = MyStack->First->infoS;
		Nnode = MyStack->First->next;
		if(node->left != Nil && node->right != Nil) {
			if(node->left->lvl - node->right->lvl > 1) {
				othernode = node->right;
				if(othernode->right == Nil || othernode->left->lvl > othernode->right->right->lvl) {
					updatenode = SingleRotasiKanan(&node);
					connectAVL(&Nnode, &updatenode, root, node->right);
				}
				else {
					updatenode = DoubleRotateKiriKanan(&node);
					connectAVL(&Nnode, &updatenode, root, node->right);
				}
			}
			else if(((node->left->lvl)-(node->right->lvl)) < -1) {
				othernode = node->right;
				if(othernode->left == Nil || othernode->left->lvl < othernode->right->lvl) {
					updatenode = SingleRotasiKiri(&node);
					connectAVL(&Nnode, &updatenode, root, node->left);
				}
				else {
					updatenode = DoubleRotateKananKiri(&node);
					connectAVL(&Nnode, &updatenode, root, node->left);
				}
			}
			else {
				levelafterRotate(&node);
			}
		}
		else if(node->left != Nil ) {
			if(node->left->lvl > 1) {
				othernode = node->left;
				if(othernode->left != Nil) {
					updatenode = SingleRotasiKanan(&node);
					connectAVL(&Nnode, &updatenode, root, node->right);
				}
				else {
					updatenode = DoubleRotateKiriKanan(&node);
					connectAVL(&Nnode, &updatenode, root, node->right);
				}
			}
		}
		else if(node->right != Nil) {
			if(node->right->lvl > 1) {
				othernode = node->right;
				if(othernode->right != Nil){
					updatenode = SingleRotasiKiri(&node);
					connectAVL(&Nnode, &updatenode, root, node->left);
				}
				else {
					updatenode = DoubleRotateKananKiri(&node);
					connectAVL(&Nnode, &updatenode, root, node->left);
				}
			}
		}
		DelStack (MyStack, &MyStack->First);
		
	}
}







