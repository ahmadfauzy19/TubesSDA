#ifndef UI_H
#define UI_H

#include "tree.h"
#include <stdio.h>
#include <windows.h>
#include<stdio.h>

struct Trunk
{
    struct Trunk *prev;
    const STRING str;
 
    Trunk(struct Trunk *prev, const STRING str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p);

void bPrintTree(addressBin root, Trunk *prev, bool isLeft);

void gotoxy(int x, int y);

/**
 * Deskripsi 	: Modul ini bertujuan untuk mengubah karakter tertentu menjadi ASCII.
 * IS 			: Karakter belum diubah menjadi ASCII.
 * FS 			: Karakter telah diubah menjadi ASCII.
 */	
void charToASCII(char c);
/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan splash screen
 */	
void splashScreen();

void nbPrintTree(address root, char tab[]);

int getLoading();

#endif
