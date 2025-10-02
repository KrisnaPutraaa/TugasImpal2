#include <stdio.h>

void determineTriangle(int a, int b, int c) {
    // 1. Validasi Input
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Tidak ada segitiga dapat dibangun (sisi tidak boleh 0 atau negatif).\n");
        return;
    }

    // Mengurutkan sisi untuk mempermudah pengecekan
    int s1, s2, s_terbesar;
    if (a >= b && a >= c) {
        s_terbesar = a; s1 = b; s2 = c;
    } else if (b >= a && b >= c) {
        s_terbesar = b; s1 = a; s2 = c;
    } else {
        s_terbesar = c; s1 = a; s2 = b;
    }

    // 2. Cek Dalil Pertidaksamaan Segitiga
    if (s_terbesar >= (s1 + s2)) {
        printf("Tidak ada segitiga dapat dibangun (sisi terpanjang lebih besar dari jumlah dua sisi lainnya).\n");
        return;
    }

    // 3. Klasifikasi Segitiga
    printf("Segitiga yang terbentuk adalah: ");
    if (a == b && b == c) {
        printf("SEGITIGA SAMA SISI (EQUILATERAL)\n");
    } else if (s_terbesar*s_terbesar == (s1*s1 + s2*s2)) {
        // Cek siku-siku bisa didahulukan
        printf("SEGITIGA SIKU-SIKU (RIGHT TRIANGLE)\n");
    } else if (a == b || b == c || a == c) {
        printf("SEGITIGA SAMA KAKI (ISOSCELES)\n");
    } else {
        printf("SEGITIGA BEBAS (SCALENE)\n");
    }
}

int main() {
    int s_a, s_b, s_c;
    printf("Masukkan 3 sisi segitiga (bilangan bulat), pisahkan dengan spasi: ");
    scanf("%d %d %d", &s_a, &s_b, &s_c);
    determineTriangle(s_a, s_b, s_c);
    
    // Contoh lain
    printf("\nContoh lain:\n");
    printf("Input (5 5 5): "); determineTriangle(5, 5, 5);
    printf("Input (5 12 13): "); determineTriangle(5, 12, 13);
    printf("Input (7 7 10): "); determineTriangle(7, 7, 10);
    printf("Input (4 5 6): "); determineTriangle(4, 5, 6);
    printf("Input (1 2 4): "); determineTriangle(1, 2, 4);

    return 0;
}