#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {

    // FILE HANDLING
    //syntax = *fptr
    // fptr = fopen(filename, mode);

    //w - writes to a file
    //a - appends new data to a file
    //r - read a file

    FILE *fptr;

    //create a file
    // fptr = fopen("myfile.txt", "w");
    fptr = fopen("D:\\nat\\coolyeah\\Semester 1\\Tugas\\Konsep Pemrograman\\SinauKP\\filehandling\\teksku.txt", "r");

    // GOOD PRACTICE -> untuk mengecek apakah file itu ada atau tidak
    if (fptr == NULL) {
        // printf("File gagal dibuka");
        // perror("Error: "); --> mengetahui alasan file tidak muncul
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    } 

    printf("File berhasil dibuka\n");

    // char string[100];
    // char ch;

    // while((ch = fgetc(fptr)) != EOF){ // fgetc() untuk membaca isi file character by character
    //     putchar(ch);
    // }

    // if (feof(fptr)){ // feof() untuk mengecek jika sudah sampai akhir file
    //     printf("\nEnd of file reached\n");
    // } else{
    //     printf("Error reading file");
    // }
        
    // while(fgets(string, sizeof(string), fptr)){
    //     printf("%s", string);
    // }; // hanya membaca baris pertama pada file, kalau mau semua terbaca pakainya loop
    

    //printf("%s", string);
    

    // write some text to the file
    // akan menimpa teks yang sudah ada
    // fprintf(fptr, "\nHalo");

    // read file with "r"
    
    //close the file
    fclose(fptr);

    int result = rename("teksku.txt", "renamed_file.txt");

    if (result == 0){
        perror("Nama file gagal diubah");
    } else {
        printf("Nama file berhasil diubah");
    }

    // GOOD PRACTICE -> untuk mengecek apakah file itu ada atau tidak
 
    return 0;
}