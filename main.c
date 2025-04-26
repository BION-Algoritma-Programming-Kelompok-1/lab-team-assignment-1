#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Employee struct definition
struct Employee {
    char nip[20];
    char name[50];
    char address[100];
    char phone[20];
    char position[50];
    char grade[5];
    long baseSalary;
    int overtimeHours;
    long totalSalary;
};

// Maksimum jumlah pegawai yang dapat disimpan
#define MAX_EMPLOYEES 10

// Array untuk menyimpan data pegawai
struct Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Utility functions
int isNumber(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

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

// Employee management functions
int isValidGrade(const char grade[]) {
    if (strcasecmp(grade, "D1") == 0 || 
        strcasecmp(grade, "D2") == 0 || 
        strcasecmp(grade, "D3") == 0) {
        return 1;
    }
    return 0;
}

long getBaseSalary(const char grade[]) {
    if (strcasecmp(grade, "D1") == 0)
        return 2500000;
    else if (strcasecmp(grade, "D2") == 0)
        return 2000000;
    else if (strcasecmp(grade, "D3") == 0)
        return 1500000;
    else
        return 0;
}

long calculateTotalSalary(struct Employee *emp, int overtimeHours) {
    long overtimePay = 0;

    // Menghitung bayaran lembur berdasarkan golongan
    if (strcasecmp(emp->grade, "D1") == 0) {
        overtimePay = overtimeHours * 10000;
    } else if (strcasecmp(emp->grade, "D2") == 0) {
        overtimePay = overtimeHours * 5000;
    } else if (strcasecmp(emp->grade, "D3") == 0) {
        overtimePay = overtimeHours * 2500;
    }

    return emp->baseSalary + overtimePay;
}

void displayError(const char *message) {
    printf("⛔️ERROR: %s\n", message);
}

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

void inputEmployee(struct Employee *emp) {
    // Cek apakah sudah mencapai batas maksimum pegawai
    if (employeeCount >= MAX_EMPLOYEES) {
        displayError("Tidak dapat menambah pegawai, batas sudah tercapai.\n");
        return;
    }

    printf("\n================================================\n");
    printf("         Silakan Masukkan Data Pegawai 👤   \n");
    printf("================================================\n");

    // Input dan validasi NIP
    char nipInput[20];
    while (1) {
        printf("\nID Pegawai (NIP): ");
        scanf(" %s", nipInput);
        
        if (isNumber(nipInput) && strlen(nipInput) <= 8) {
            strcpy(emp->nip, nipInput);
            break;
        } else {
            displayError("NIP hanya boleh berisi angka dan maksimal 8 karakter.");
        }
    }

    // Input data pribadi pegawai
    printf("Nama: ");
    scanf(" %[^\n]", emp->name);
    printf("Alamat: ");
    scanf(" %[^\n]", emp->address);

    // Input dan validasi nomor telepon
    char phoneInput[20];
    while (1) {
        printf("Nomor Telepon: ");
        scanf(" %s", phoneInput);
        
        if (isNumber(phoneInput) && strlen(phoneInput) <= 14) {
            strcpy(emp->phone, phoneInput);
            break;
        } else {
            displayError("Nomor telepon hanya boleh berisi angka dan maksimal 14 karakter.\n");
        }
    }

    printf("Jabatan: ");
    scanf(" %[^\n]", emp->position);
    
    // Input dan validasi golongan
    char gradeInput[10];
    int validGrade = 0;
    
    do {
        printf("Golongan (D1/D2/D3): ");
        scanf(" %s", gradeInput);
        
        if (isValidGrade(gradeInput)) {
            if (strcasecmp(gradeInput, "D1") == 0) {
                strcpy(emp->grade, "D1");
            } else if (strcasecmp(gradeInput, "D2") == 0) {
                strcpy(emp->grade, "D2");
            } else if (strcasecmp(gradeInput, "D3") == 0) {
                strcpy(emp->grade, "D3");
            }
            validGrade = 1;
        } else {
            displayError("Golongan tidak valid! Masukkan D1, D2, atau D3.\n");
        }
    } while (!validGrade);

    // Set gaji pokok dan inisialisasi data lembur
    emp->baseSalary = getBaseSalary(emp->grade);
    emp->overtimeHours = 0;
    emp->totalSalary = emp->baseSalary; // Awalnya total gaji sama dengan gaji pokok
    
    // Tampilkan gaji pokok yang telah diformat
    char formattedSalary[30];
    formatCurrency(formattedSalary, emp->baseSalary);
    printf("\nGaji Pokok: Rp%s\n", formattedSalary);

    // Simpan data pegawai ke array
    employees[employeeCount++] = *emp;
}

void inputOvertime(struct Employee *emp) {
    char overtimeInput[10];
    int overtimeHours;
    int foundEmployee = 0;
    int empIndex = -1;
    
    printf("\n================================================\n");
    printf("          Silakan Masukkan Data Lembur       \n");
    printf("================================================\n");

    // Input dan validasi NIP
    char nipInput[20];
    while (1) {
        printf("\nID Pegawai (NIP): ");
        scanf(" %s", nipInput);
        
        if (isNumber(nipInput)) {
            strcpy(emp->nip, nipInput);
            
            // Cari pegawai berdasarkan NIP
            for (int i = 0; i < employeeCount; i++) {
                if (strcmp(employees[i].nip, nipInput) == 0) {
                    *emp = employees[i];
                    foundEmployee = 1;
                    empIndex = i;
                    break;
                }
            }
            
            break;
        } else {
            printf("⛔️ERROR: NIP hanya boleh berisi angka.\n");
        }
    }

    // Jika pegawai tidak ditemukan
    if (!foundEmployee) {
        printf("\nNama: ⛔️ERROR: (Data pegawai tidak ditemukan)\n");
        return;
    }

    // Input dan validasi golongan
    char gradeInput[10];
    int validGrade = 0;
    
    do {
        printf("Golongan (D1/D2/D3): ");
        scanf(" %s", gradeInput);
        
        if (isValidGrade(gradeInput)) {
            if (strcasecmp(gradeInput, "D1") == 0) {
                strcpy(emp->grade, "D1");
            } else if (strcasecmp(gradeInput, "D2") == 0) {
                strcpy(emp->grade, "D2");
            } else if (strcasecmp(gradeInput, "D3") == 0) {
                strcpy(emp->grade, "D3");
            }
            validGrade = 1;
        } else {
            printf("⛔️ERROR: Golongan tidak valid! Masukkan D1, D2, atau D3.\n\n");
        }
    } while (!validGrade);

    // Update gaji pokok jika golongan berubah
    emp->baseSalary = getBaseSalary(emp->grade);

    // Input dan validasi jam lembur
    while (1) {
        printf("Jumlah Jam Lembur: ");
        scanf(" %s", overtimeInput);
        
        if (!isNumber(overtimeInput)) {
            printf("⛔️ERROR: Input jam lembur harus berupa angka.\n\n");
        } else {
            overtimeHours = atoi(overtimeInput);
            if (overtimeHours < 0 || overtimeHours > 48) {
                printf("⛔️ERROR: Jumlah jam lembur harus antara 0 - 48 jam.\n\n");
            } else {
                break;
            }
        }
    }

    // Update data lembur dan hitung total gaji
    emp->overtimeHours = overtimeHours;
    emp->totalSalary = calculateTotalSalary(emp, overtimeHours);

    // Tampilkan ringkasan data
    printf("\nNIP: %s\n", emp->nip);
    printf("Nama: %s\n", emp->name);
    printf("Golongan: %s\n", emp->grade);
    printf("Lembur: %d jam\n", overtimeHours);
    
    // Tampilkan gaji pokok yang telah diformat
    char formattedBaseSalary[30];
    formatCurrency(formattedBaseSalary, emp->baseSalary);
    printf("Gaji Pokok: Rp%s\n", formattedBaseSalary);
    
    // Tampilkan total gaji yang telah diformat
    char formattedSalary[30];
    formatCurrency(formattedSalary, emp->totalSalary);
    printf("Total Gaji Bulan Ini: Rp%s\n", formattedSalary);
    
    // Update data pegawai di array
    if (empIndex >= 0) {
        employees[empIndex].overtimeHours = overtimeHours;
        strcpy(employees[empIndex].grade, emp->grade);
        employees[empIndex].baseSalary = emp->baseSalary;
        employees[empIndex].totalSalary = emp->totalSalary;
    }
}

void listEmployees() {
    printf("\n================================================\n");
    printf("            Daftar Pegawai                     \n");
    printf("================================================\n");

    // Cek apakah ada data pegawai
    if (employeeCount == 0) {
        printf("\n⛔️ERROR: Tidak ada pegawai yang ditemukan.\n");
        return;
    }

    // Tampilkan data setiap pegawai
    for (int i = 0; i < employeeCount; i++) {
        printf("\nPegawai %d\n", i + 1);
        printf("NIP: %s\n", employees[i].nip);
        printf("Nama: %s\n", employees[i].name);
        printf("Jabatan: %s\n", employees[i].position);
        printf("Golongan: %s\n", employees[i].grade);
        
        // Tampilkan gaji pokok yang telah diformat
        char formattedBaseSalary[30];
        formatCurrency(formattedBaseSalary, employees[i].baseSalary);
        printf("Gaji Pokok: Rp%s\n", formattedBaseSalary);
        
        printf("Jam Lembur: %d jam\n", employees[i].overtimeHours);
        
        // Hitung dan tampilkan total gaji
        long totalSalary = employees[i].totalSalary;
        if (totalSalary == 0) {
            // Jika tidak ada jam lembur, maka total gaji adalah gaji pokok
            totalSalary = employees[i].baseSalary;
        }
        
        // Tampilkan total gaji yang telah diformat
        char formattedTotalSalary[30];
        formatCurrency(formattedTotalSalary, totalSalary);
        printf("Total Gaji: Rp%s\n", formattedTotalSalary);
    }
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