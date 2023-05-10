#include "UI.h"



int i, j, width, height, x, y;

void charToASCII(char c) 
{
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
	switch(c)
	{
		case '=' :
			printf ("%c", 254);
			break;
		default :
			printf ("%c", c);		
	}
}

void gotoxy(int x, int y)
{
 HANDLE hConsoleOutput;
 COORD dwCursorPosition;
 dwCursorPosition.X = x;
 dwCursorPosition.Y = y;
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

int getLoading(){ 
	system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n \t\t\t\t\t               proses");
		Sleep(300);
		printf(". ");
		Sleep(300);
		printf(". ");
		Sleep(300);
		printf(". ");
		Sleep(300);
		printf(". ");
		Sleep(300);
		printf(". ");
	}

void splashScreen(){


	char loading[] = 
"\t\t\t\t\tLoading\n\
\t\t\t\t\t\t======================\n\
";



	char author[] =
 "\t              Created By :\n\
  \t\t\t\t\t\tAdrian Eka Saputra\n\
  \t\t\t\t\t\tAhmad Fauzy\n\
  \t\t\t\t\t\tAlfien Sukma P\n\
 ";
 int i;
 gotoxy(17,8);
   for (i = 0;i < strlen(loading);i++){
   		Sleep(2);
 		charToASCII(loading[i]);
 	}
  
   gotoxy(39,18);
     for (i = 0; author[i]!=0 ; i++) {
    Sleep(10);
    printf("%c", author[i]);
  }
}

void printTree(address root){
	
}

void nbPrintTree(address root, char tab[]){
	if (root == NULL) {
        return;
    }
    char tempTab[255];
    int i;
    strcpy(tempTab, tab);
	printf("%s%s\n",tab, root->info);
	if(root->fs!=NULL){
	    for(i=0;i<strlen(tab);i++){
	    	tempTab[i] = ' ';
		}
		strcat(tempTab, "|-");
		nbPrintTree(root->fs, tempTab);
	}
	if(root->nb!=NULL){
		nbPrintTree(root->nb, tab);
	}
}

void bPrintTree(addressBin root, char tab[], int isLeft){
	if (root == NULL) {
        return;
    }
    char tempTab[255];
    if(isLeft!=-1){
		printf("%s", tab);
	    printf(isLeft ? "|-" : "|+");
	    snprintf(tempTab, sizeof(tempTab), "%s%s", tab, "   ");
	}
    printf("%s\n", root->infoB);
    bPrintTree(root->left, tempTab, 1);
    bPrintTree(root->right, tempTab, 0);
}


//void bprintTree(node* root, int spaces) {
//    if (root == NULL) {
//        return;
//    }
//    printTree(root->right, spaces + 6);
//    printNode(root, spaces);
//    printTree(root->left, spaces + 6);
//}
//
//// Fungsi untuk menampilkan spasi
//void printSpaces(int spaces) {
//    int i;
//    for (i = 0; i < spaces; i++) {
//        printf(" ");
//    }
//}
//
//// Fungsi untuk menampilkan node
//void printNode(node* root, int spaces) {
//    if (root == NULL) {
//        return;
//    }
//    printSpaces(spaces);
//    printf("+-----+\n");
//    printSpaces(spaces);
//    printf("|  %s  |\n", root->data);
//    printSpaces(spaces);
//    printf("+-----+\n");
//}

