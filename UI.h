#ifndef UI_H
#define UI_H

#include "tree.h"
#include <stdio.h>
#include <windows.h>
#include<stdio.h>

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

void printTree(address root);

void nbPrintTree(address root, char tab[]);

void bPrintTree(addressBin root, char tab[], int isLeft);

int getLoading();
//
//void printSpaces(int spaces) {
//
//void printNode(node* root, int spaces);

#endif
