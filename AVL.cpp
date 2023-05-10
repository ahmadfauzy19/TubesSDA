#include "tree.h"
//#include <string.h>

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
		printf("tree AVL sementara");
		bPreOrder(Pointer(*root));
	}
	else {
		curr = (*root).pointer;
		while(curr != Nil) {
			EnStack (&MyStack, curr);
			if(cmprAVL( InfoB(curr) , InfoB(newnode))){
				if(curr->left == Nil) {
					printf("%s > %s\n",InfoB(curr),InfoB(newnode));
					curr->left = newnode;
					updatelevel(&MyStack.First);
					printf("tree AVL sementara : ");
					bPreOrder((*root).pointer);
					system("pause");
					break;
				}
				else {
					curr = curr->left;
				}
			}
			else {
				if(curr->right == Nil) {
					printf("%s < %s\n",InfoB(curr),InfoB(newnode));
					curr->right = newnode;
					updatelevel(&MyStack.First);
					printf("tree AVL sementara : ");
					bPreOrder((*root).pointer);
					system("\npause");
					break;
				}
				else {
					curr = curr->right;
				}
			}
		}
	}
	balancing(&MyStack, &((*root).pointer));
	printf("\ntree AVL setelah balancing : ");
	bPreOrder(Pointer(*root));
	system("pause");
	return;
}



void balancing(ListS *MyStack, addressBin *root) {
	if(MyStack->First != Nil) {
		addressBin node,temp, updatenode,nextnode,othernode;
		char Rotate;
		while(MyStack->First != Nil){
			printf("Isi Stack\n");
			PrintInfo (*MyStack);
			node = MyStack->First->infoS;
			if(MyStack->First->next != Nil) {
				nextnode = MyStack->First->next->infoS;
			}
			if(node->left != Nil && node->right != Nil) {
				if(node->left->lvl - node->right->lvl > 1) {
					printf("tidak balance");
					othernode = node->right;
					if(othernode->right == Nil || othernode->left->lvl > othernode->right->right->lvl) {
						printf("single rotasi RR\n");
						updatenode = SingleRotasiKanan(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else{
							*root = updatenode;
						}
					}
					else {
						printf("double rotasi LR\n");
						updatenode = DoubleRotateKiriKanan(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
				}
				else if(((node->left->lvl)-(node->right->lvl)) < -1) {
					othernode = node->right;
					if(othernode->left == Nil || othernode->left->lvl < othernode->right->lvl) {
						printf("single rotasi LL\n");
						updatenode = SingleRotasiKiri(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
					else {
						printf("double rotasi RL 1\n");
						updatenode = DoubleRotateKananKiri(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
				}
				else {
					printf("balance\n");
					levelafterRotate(&node);
				}
			}
			else if(node->left != Nil ) {
				printf("salah satu anak\n");
				if(node->left->lvl > 1) {
					othernode = node->left;
					if(othernode->left != Nil) {
						printf("single rotasi kanan\n");
						updatenode = SingleRotasiKanan(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
					else {
						printf("double rotasi LR\n");
						updatenode = DoubleRotateKiriKanan(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
				}
			}
			else if(node->right != Nil) {
				if(node->right->lvl > 1) {
					othernode = node->right;
					if(othernode->right != Nil){
						printf("single rotasi kiri\n");
						updatenode = SingleRotasiKiri(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
					else {
						printf("double rotasi RL 2\n");
						updatenode = DoubleRotateKananKiri(&node);
						if(MyStack->First->next != Nil) {
							if(nextnode->left->infoB == node->infoB) {
								nextnode->left=updatenode;
							}
							else {
								nextnode->right=updatenode;
							}
						}
						else {
							*root = updatenode;
						}
					}
				}
			}
			else {
				printf(" gapunya anak\n");
			}
			DelStack (MyStack, &MyStack->First);
			
		}
	}
}


addressBin SingleRotasiKiri(addressBin *node) {
	addressBin partner,othernode;
	partner = (*node)->right;
	(*node)->right = partner->left;
	partner->left = (*node);
	*node = partner;
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
	*node=SingleRotasiKiri(node);
	return *node;
}

addressBin SingleRotasiKanan(addressBin *node) {
	addressBin partner,othernode;
	partner = (*node)->left;
	(*node)->left = partner->right;
	partner->right = (*node);
	*node = partner;
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
	*node=SingleRotasiKanan(node);
	return *node;
}




