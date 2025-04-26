// input_validation.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/utils.h"

// Format currency with thousands separator
void formatCurrency(char *buffer, long amount) {
    char temp[30];
    sprintf(temp, "%ld", amount);
    
    int length = strlen(temp);
    int bufferIndex = 0;
    
    for (int i = 0; i < length; i++) {
        // Add dot as thousands separator
        if ((length - i) % 3 == 0 && i > 0) {
            buffer[bufferIndex++] = '.';
        }
        buffer[bufferIndex++] = temp[i];
    }
    buffer[bufferIndex] = '\0';
}

// ONLY DIGITS VALIDATION
int isNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// VALIDATE INPUT CHOICE
int getValidChoice() {
    char input[10];
    int choice;

    while (1) {
        printf("\nPilih opsi: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (isNumber(input)) {
            sscanf(input, "%d", &choice);
            return choice;
        } else {
            printf("⛔️ERROR: Pilihan tidak valid, Harap masukkan nomor yang valid\n");
        }
    }
}

