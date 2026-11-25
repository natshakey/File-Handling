#include <stdio.h>
#include <errno.h>
#include <string.h>

// Nama: Anggita Natasya Christy
// NIM: 21114012610016
// Tugas Praktik: Program Pencatat Nilai 

int main() {

    FILE *fptr;

    int pilihan, n;
    int nilai, jumlah = 0;
    float total = 0;

    do{
        printf("\t\tProgram Pencatat Nilai\t\t\n");
        printf("1. Tulis data nilai\n");
        printf("2. Tambah data nilai\n");
        printf("3. Baca data nilai\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan){
            case 1:
                printf("Jumlah data: ");
                scanf("%d", &n);

                fptr = fopen("nilai.txt", "w");

                if (fptr == NULL){
                    printf("Error opening file: %s\n", strerror(errno));
                    break;
                }
                
                for (int i = 0; i < n; i++){
                    printf("Nilai ke-%d: ", i+1);
                    scanf("%d", &nilai);
                    fprintf(fptr, "%d\n", nilai);
                }

                fclose(fptr);
                printf("Data berhasil disimpan\n");
                break;

            case 2:
                // Tambah Data
                printf("Nilai yang ditambahkan: ");
                scanf("%d", &nilai);

                fptr = fopen("nilai.txt", "a");

                if (fptr == NULL){
                    printf("Error opening file: %s\n", strerror(errno));
                    break;
                }

                fprintf(fptr, "%d\n", nilai);
                fclose(fptr);
                printf("Data berhasil ditambahkan\n");
                break;

            case 3:
                // Baca Data
                jumlah, total = 0;

                fptr = fopen("nilai.txt", "r");

                if (fptr == NULL){
                    printf("Error opening file: %s\n", strerror(errno));
                    break;
                }

                printf("\nIsi file:\n");
                while (fscanf(fptr, "%d", &nilai) == 1){
                    printf("%d\n", nilai);
                    total += nilai;
                    jumlah++;
                }

                fclose(fptr);

                if (jumlah == 0){
                    printf("File kosong\n");
                } else{
                    printf("Jumlah data : %d\n", jumlah);
                    printf("Rata-rata   : %.2f\n", total / jumlah);
                }
                break;
            
            case 4:
                printf("Program selesai\n");
                break;

            default:
                printf("Pilihan tidak valid\n");
        }
    } while (pilihan != 4);
   
    return 0;
}