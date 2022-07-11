#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main() {
   	Buku * b1 = (Buku *)calloc(1,sizeof(Buku));
   	Buku * b2 = (Buku *)calloc(1,sizeof(Buku));
   	Buku * b3 = (Buku *)calloc(1,sizeof(Buku));
   	Buku * b4 = (Buku *)calloc(1,sizeof(Buku));
   	Buku * b5 = (Buku *)calloc(1,sizeof(Buku));
   	Buku * b6 = (Buku *)calloc(1,sizeof(Buku));

    strcpy(b1->ISBN, "100");
    strcpy(b1->JudulBuku, "Laskar Pelangi");
    strcpy(b1->JenisBuku, "Novel");
    strcpy(b1->Author, "Andrea Hirata");
	strcpy(b1->Donatur, "1132004");
	strcpy(b1->Nama, "Rut Ferwati");
	strcpy(b1->NoTelp, "082292328819");
    b1->ptrNextBuku = b2;

    strcpy(b2->ISBN, "101");
    strcpy(b2->JudulBuku, "Perancangan Perangkat Lunak");
    strcpy(b2->JenisBuku, "Buku Perkuliahan");
    strcpy(b2->Author, "Andi");
	strcpy(b2->Donatur, "1132005");
	strcpy(b2->Nama, "Bryan");
	strcpy(b2->NoTelp, "08229232789");
    b2->ptrNextBuku = b3;

    strcpy(b3->ISBN, "102");
    strcpy(b3->JudulBuku, "Antara Ada dan Tiada");
    strcpy(b3->JenisBuku, "Cerita Pendek");
    strcpy(b3->Author, "Andrea Hirata");
	strcpy(b3->Donatur, "1132004");
	strcpy(b3->Nama, "Rut Ferwati");
	strcpy(b3->NoTelp, "082292328819");
    b3->ptrNextBuku = b4;

    strcpy(b4->ISBN, "103");
    strcpy(b4->JudulBuku, "Zelova");
    strcpy(b4->JenisBuku, "Majalah");
    strcpy(b4->Author, "NextFlix");
	strcpy(b4->Donatur, "1132006");
	strcpy(b4->Nama, "Shopee");
	strcpy(b4->NoTelp, "12886777567");
    b4->ptrNextBuku = b5;
    
    strcpy(b5->ISBN, "104");
    strcpy(b5->JudulBuku, "Mengenal Struct");
    strcpy(b5->JenisBuku, "Buku Perkuliahan");
    strcpy(b5->Author, "Nivily A.S");
	strcpy(b5->Donatur, "1132005");
	strcpy(b5->Nama, "Bryan");
	strcpy(b5->NoTelp, "08229232789");
    b5->ptrNextBuku = b6;
    
    strcpy(b6->ISBN, "105");
    strcpy(b6->JudulBuku, "Basis Data");
    strcpy(b6->JenisBuku, "Buku Perkuliahan");
    strcpy(b6->Author, "Rini M.V");
	strcpy(b6->Donatur, "1132007");
	strcpy(b6->Nama, "Scintya Tobing");
	strcpy(b6->NoTelp, "082291128819");
    b6->ptrNextBuku = NULL;
    

	menu: 
	printf("=====Menu Pencarian Buku=====\n");
	printf("1. Tambahkan Buku\n");
	printf("2. Tampilkan Semua Buku\n");
	printf("3. Cari Buku Berdasarkan ISBN\n");
	printf("4. Cari Buku Berdasarkan Donatur\n");
	printf("5. Keluar\n\n");

	int pil;	
	printf("Masukkan Pilihan Menu : ");
	scanf("%d", &pil);
	
	if(pil==1){
		char ISBN[20];
	    char JudulBuku[20];
	    char JenisBuku[20];
	    char Author[20];
	    char Donatur[20];
	    char Nama[50];
	    char NoTelp[20];
	    printf("\nMasukkan Data Buku\n");
		printf("ISBN\t: ");
		scanf("%s", &ISBN);
		printf("Judul Buku\t: ");
		scanf("%s", &JudulBuku);
		printf("Jenis Buku\t: ");
		scanf("%s", &JenisBuku);
		printf("Author\t: ");
		scanf("%s", &Author);
		printf("\nMasukkan Data Donatur\n");
		printf("Donatur\t: ");
		scanf("%s", &Donatur);
		printf("Nama\t: ");
		scanf("%s", &Nama);
		printf("Nomor telepon\t: ");
		scanf("%s", &NoTelp);
		tambahBook(&b1,ISBN,JudulBuku,JenisBuku,Author,Donatur,Nama,NoTelp);
		goto menu;	
	}else if(pil==2){
		CetakBuku(b1);
		goto menu;
	}else if(pil==3){
    	char cari[100];
    	printf("Cari berdasarkan ISBN buku : ");
    	scanf(" %[^\t\n]s", &cari);
    	SearchBook(b1, cari);
    	goto menu;
	}else if(pil==4){
		char donat[100];
		printf("Masukkan NIDN Donatur : ");
		scanf(" %[^\t\n]s", &donat);
		cariBuku(b1, donat);
		goto menu;
	}else if(pil==5){
		printf("Terimakasih Sudah Berkunjung!!");
	}else{
		exit(0);
	}

    return 0;
}
