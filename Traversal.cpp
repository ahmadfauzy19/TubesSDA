#include "tree.h"

//non-binary tree
void nbPreOrder(address root){
	if (root == NULL) {
	    return;
	}
	printf("%s ", root->info);
	nbPreOrder(root->fs);
	nbPreOrder(root->nb);
}
	
void nbInOrder(address root) {
	if (root == NULL) {
        return;
    }
    
    nbInOrder(root->fs);
    printf("%s ", root->info);
    address pcur = root->nb;
    while (pcur != NULL) {
        nbInOrder(pcur->fs);
        printf("%s ", pcur->info);
        pcur = pcur->nb;
    }
}
	
void nbPostOrder(address root) {
	if (root == NULL) {
	    return;
	}
	address pcur = root->fs;
	while (pcur != NULL) {
	    nbPostOrder(pcur);
	    pcur = pcur->nb;
	}
	printf("%s ", root->info);
}

void nbLevelOrder(address root, int curLevel, int desLevel) {
    if (root == NULL) {
        return;
    }
    
    if (curLevel == desLevel) {
        printf("%s ", root->info);
        return;
    }
    
    address pcur = root->fs;
    while (pcur != NULL) {
        nbLevelOrder(pcur, curLevel + 1, desLevel);
        pcur = pcur->nb;
    }
}

int nbDepth(address root){
	int maxDepth = 0, currentDepth = 0;
	address currentNode;
	
	if (root == NULL) {
        return 0;
    }
    
    currentNode = root->fs;
    while (currentNode != NULL) {
        currentDepth = nbDepth(currentNode);
        if (currentDepth > maxDepth) {
            maxDepth = currentDepth;
        }
        currentNode = currentNode->nb;
    }
    return maxDepth + 1;	// saat print depth tree di main kurangi 1
}

//binary tree
void bPreOrder(addressBin root) {
	if (root == NULL){
	    return;
	}
	printf("%s ", root->infoB);
	bPreOrder(root->left);
	bPreOrder(root->right);
}

void bPostOrder(addressBin root) {
	if (root == NULL) {
	    return;
	}
	bPostOrder(root->left);
	bPostOrder(root->right);
	printf("%s ", root->infoB);
}
	
void bInOrder(addressBin root) {
	if (root == NULL) {
	    return;
	}
	bInOrder(root->left);
	printf("%s ", root->infoB);
	bInOrder(root->right);
}

void bLevelOrder(addressBin root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%s ", root->infoB);
    } else if (level > 1) {
        bLevelOrder(root->left, level - 1);
        bLevelOrder(root->right, level - 1);
    }
}

int bDepth(addressBin root) {
    if (root == NULL) {
        return 0;
    } else {
        int ldepth = bDepth(root->left);
        int rdepth = bDepth(root->right);
        if (ldepth > rdepth) {
            return (ldepth + 1);
        } else {
            return (rdepth + 1);
        }
    }
}
