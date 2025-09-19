#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sizeMahasiswa 5

typedef char string[100]; 

typedef struct{
	string nama; 
	string npm;	
}Mahasiswa;

void inisialisasi(Mahasiswa m[]); 
int getEmptyMahasiswa(Mahasiswa m[]); 
Mahasiswa createMahasiswa(string nama, string npm); 
bool isEmptyMahasiswa(Mahasiswa m[]); 
void printAll(Mahasiswa m[]); 

int main(int argc, char *argv[]) {
	Mahasiswa m[5]; 
	int menu, index; 
	string nama, npm; 
	
	inisialisasi(m);
	do{
		system("cls"); 
		printf("\n\t==== Kampus UAJY ======\n"); 
		printf("\n[1]. Insert Data Mahasiswa"); 
		printf("\n[2]. Tampilkan Semua Data"); 
		printf("\n>> ");scanf("%d", &menu); 

		switch(menu){
			case 1: 
				index = getEmptyMahasiswa(m); 
				if(index!=-1){
					do{
						printf("\nNama Lengkap	: ");fflush(stdin);gets(nama); 
						
						if(strcmpi(nama, "-") == 0 || strlen(nama) == 0){
							printf("\n\t[!] Nama Mahasiswa Tidak Boleh Kosong [!]\n"); 
						}	
					}while(strcmpi(nama, "-") == 0 || strlen(nama) == 0); 
					
					do{
						printf("\nNPM	: ");fflush(stdin);gets(npm); 
						
						if(strlen(npm)<5){
							printf("\n\t[!] NPM Harus Lebih dari 4 digit  [!]\n"); 
						}
					}while(strlen(npm)<5); 
					
					printf("\n\t[+] Nama %s Telah Ditambahkan [+]", nama); 
					
					m[index] = createMahasiswa(nama, npm); 
				}else{
					printf("\n\t[!] Data Mahasiswa Full [!]"); 
				}
			break; 
			
			case 2: 
				if(isEmptyMahasiswa){
					printf("\n\t=== Tampilan Data Mahasiswa ==="); 
					printAll(m); 
				}else{
					printf("\n\t[!] Data Mahasiswa Kosong [!]"); 
				}
			break; 	
		}
		getch(); 
	}while(menu!=0); 
	
	return 0;
}

void inisialisasi(Mahasiswa m[]){
	int i; 
	
	for(i=0; i<sizeMahasiswa; i++){
		strcpy(m[i].nama, " ");
		strcpy(m[i].npm, " ");
	}
}

int getEmptyMahasiswa(Mahasiswa m[]){
	int i; 
	
	for(i=0; i<sizeMahasiswa; i++){
		if(strcmpi(m[i].npm, " ") == 0){
			return i; 
		}
	}
	return -1; 
}

Mahasiswa createMahasiswa(string nama, string npm){
	Mahasiswa m; 
	
	strcpy(m.nama, nama); 
	strcpy(m.npm, npm); 
	
	return m; 
}

bool isEmptyMahasiswa(Mahasiswa m[]){
	int i; 
	
	for(i=0; i<sizeMahasiswa; i++){
		if( strcmpi(m[i].npm, " ") != 0){
			return false; 
		}
	}
	return true; 
}

void printAll(Mahasiswa m[]){
	int i; 
	int angka = 1; 
	
	for(i=0; i<sizeMahasiswa; i++){
		if(strcmpi(m[i].npm, " ") != 0){
			printf("\nMahasiswa ke-%d", angka++);
			printf("\nNama Mahasiswa 	: %s", m[i].nama); 
			printf("\nNPM		: %s", m[i].npm);  
		}
	}
}
