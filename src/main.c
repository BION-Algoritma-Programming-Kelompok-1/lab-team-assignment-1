#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/employee.h"
#include "../include/utils.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidMenuChoice() {
    int choice;
    char buffer[100];
    int valid = 0;
    
    do {
        printf("\nPilih opsi: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &choice) == 1) {
                if (choice >= 0 && choice <= 3) {
                    valid = 1;
                } else {
                    printf("⛔️ERROR: Pilihan tidak valid, silahkan masukkan angka antara 0 dan 3.\n");
                }
            } else {
                printf("⛔️ERROR: Input tidak valid, harap masukkan angka.\n");
            }
        }
    } while (!valid);
    
    return choice;
}

int main() {
    struct Employee emp;
    int choice;
    
    do {
        printf("\n================================================\n");
        printf("              Aplikasi Pegawai - Tim 1         \n");
        printf("================================================\n");
        printf("1. Input Data Pegawai\n");
        printf("2. Input Lembur\n");
        printf("3. Daftar Pegawai\n");
        printf("0. Keluar\n");
        
        choice = getValidMenuChoice();
        
        switch(choice) {
            case 1:
                system("clear");
                inputEmployee(&emp);
                clearInputBuffer();
                break;
            case 2:
                system("clear");
                inputOvertime(&emp);
                clearInputBuffer();
                break;
            case 3:
                system("clear");
                listEmployees();
                break;
            case 0:
                printf("\n🙏Terima kasih telah menggunakan Program Aplikasi Pegawai - Tim 1\n");
                printf("Keluar dari program...\n\n");
                break;
            default:
                printf("⛔️ERROR: Terjadi kesalahan dalam pemilihan menu.\n");
        }

    } while(choice != 0);
    return 0;
}