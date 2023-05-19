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

int getX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}

int getY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
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

void nbPrint(address root, int x, int i, int y) {
    gotoxy(x, y);
    char infoShort[4]; // Menyimpan 3 huruf pertama dari info
    strncpy(infoShort, root->info, 3);
    infoShort[3] = '\0'; // Menambahkan karakter null terminator pada akhir string
    printf("%s", infoShort);
    if (root->fs != NULL) {
        if (root->fs->nb != NULL) {
            nbPrint(root->fs, x - i / 2, i / 2, y + 1);
        } else {
            nbPrint(root->fs, x - 1, i, y + 1);
        }
    }

    if (root->nb != NULL) {
        nbPrint(root->nb, x + i, i, y);
    }
}

void bPrint(addressBin t, int x, int i, int y) {
    if (t != NULL) {
        gotoxy(x, y);
        char infoShort[4]; // Menyimpan 3 huruf pertama dari info
	    strncpy(infoShort, t->infoB, 3);
	    infoShort[3] = '\0'; // Menambahkan karakter null terminator pada akhir string
	    printf("%s", infoShort);

        i = i / 2;
        if (t->right != NULL) {
            gotoxy(x-1, y + 1);
            printf("_|_");
            gotoxy(x + i, y + 2);
            printf("|"); // Garis anak kanan
            bPrint(t->right, x + i, i, y + 3);
        }
        if (t->left != NULL) {
            gotoxy(x-1, y + 1);
            printf("_|_");
            gotoxy(x - i, y + 2);
            printf("|"); // Garis anak kiri
            bPrint(t->left, x - i, i, y + 3);
        }
    }
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

void showTrunks(Trunk *p)
{
    if (p == Nil) {
        return;
    }
 
    showTrunks(p->prev);
    printf("%s", p->str);
}

void bPrintTree(addressBin root, Trunk *prev, bool isLeft){
	if (root == Nil) {
        return;
    }
    const STRING prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    bPrintTree(root->right, trunk, true);
 
    if (!prev) {
        trunk->str = "---";
    }
    else if (isLeft)
    {
        trunk->str = "#---";
        prev_str = "   |";
    }
    else {
        trunk->str = "*---";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    printf(" %s\n", root->infoB);
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    bPrintTree(root->left, trunk, false);
}

