#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

void awal(){
	char i;
	int menu;
	ulang:
		system("cls");
		printf("\t=================================================================\n");
    	printf("\t|       ***Transformasi Non Binary to Binary & AVL***  \t\t|\n");
    	printf("\t|===============================================================|\n");
		printf("\t| 1. Masuk program                                              |\n");
		printf("\t| 2. Tentang                                                    |\n");
		printf("\t| 3. Exit                                                       |\n");	
		printf("\t|                                                               |\n");
		printf("\t ===============================================================");
		printf("\n\n\tMasukan Input : ");
		scanf("%d", &menu);
	
	
	switch(menu){
		case 1:
			break;
		case 2:
			system("cls");
			tentang();
			break;
		case 3:
			printf("apakah yakin ?(Y/T)"); 
			i = getche();
			fflush(stdin);
			if(i=='t' || i=='T'){
				printf("tidak jadi keluar aplikasi");
				system("pause");
				goto ulang;
			}
			exit(1);
		default:
			printf("\n!!! masukan pilihan dengan benar !!!\n\n");
			system("pause");
		 	awal();
			break;
	}	
}

void tentang(){
	char hotel[500];
	FILE *tentang;
	
	if ( (tentang=fopen("tentang.txt","r")) == NULL ){
	    printf("File tidak dapat dibuka!\r\n");
		awal();
	}
	// Ambil isi file menggunakan fungsi fgets(),

	while (fgets(hotel, sizeof(hotel), tentang)){
	printf("%s", hotel);	
	}
	printf("\n");
	getchar();
	getchar();
	awal();
	fclose(tentang); /* Tutup file */
}



void TampilanAwal(){
	printf(" ======================================\n");
	printf(" |             Daftar Menu :          |\n");
	printf(" ======================================\n");
	printf(" | 1. Insert Tree Non-Binary          |\n");
	printf(" | 2. Pre Order                       |\n");
	printf(" | 3. Post Order                      |\n");
	printf(" | 4. In Order                        |\n");
	printf(" | 5. Level Order                     |\n");
	printf(" | 6. Transform to Binary             |\n");
	printf(" | 7. AVL                             |\n");
	printf(" | 8. Print Tree                      |\n");
	printf(" | 9. Load Tree                       |\n");
	printf(" | 10. delete file                    |\n");
	printf(" | 11. delete Tree                    |\n");
	printf(" | 12. Exit                           |\n");
	printf(" ======================================\n");
}

