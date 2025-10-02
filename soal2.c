#include <stdio.h>

int main() {
    // --- Variabel untuk menyimpan input dan biaya ---
    int jumlah_komputer, jumlah_peripheral = 0;
    int jam_servis;
    char antar_jemput; // 'y' untuk ya, 'n' untuk tidak

    double base_fee = 0;
    double additional_fee = 0;
    double total_biaya = 0;

    // --- Mengumpulkan Input dari Pengguna ---
    printf("--- Kalkulator Biaya Servis Komputer ---\n");
    printf("Masukkan jumlah komputer: ");
    scanf("%d", &jumlah_komputer);

    // Hanya tanya jumlah peripheral jika komputer 3 atau lebih
    if (jumlah_komputer >= 3) {
        printf("Masukkan jumlah peripheral (keyboard, mouse, dll.): ");
        scanf("%d", &jumlah_peripheral);
    }

    printf("Masukkan jam servis (format 24 jam, misal: 14 untuk jam 2 siang): ");
    scanf("%d", &jam_servis);

    printf("Apakah pelanggan bersedia antar-jemput sendiri? (y/n): ");
    scanf(" %c", &antar_jemput); // Spasi sebelum %c untuk menghindari masalah buffer

    // --- Langkah 1: Tentukan Biaya Dasar dan Tambahan ---
    if (jumlah_komputer >= 1 && jumlah_komputer <= 2) {
        base_fee = 50;
        additional_fee = 0;
    } else if (jumlah_komputer >= 3 && jumlah_komputer <= 10) {
        base_fee = 100;
        additional_fee = 10 * jumlah_peripheral;
    } else if (jumlah_komputer > 10) {
        base_fee = 500;
        additional_fee = 10 * jumlah_peripheral;
    }

    // --- Langkah 2: Sesuaikan Biaya Dasar Berdasarkan Jam Servis ---
    // Asumsi jam kerja adalah 09:00 - 17:00
    if (jam_servis < 9 || jam_servis > 17) {
        printf("\n-> Biaya dasar digandakan karena di luar jam kerja.\n");
        base_fee = base_fee * 2;
    }

    // --- Langkah 3: Hitung Total Biaya Sementara ---
    total_biaya = base_fee + additional_fee;

    // --- Langkah 4: Berikan Diskon Antar-Jemput ---
    if (antar_jemput == 'y' || antar_jemput == 'Y') {
        printf("-> Total biaya dipotong setengah karena antar-jemput mandiri.\n");
        total_biaya = total_biaya / 2;
    }

    // --- Menampilkan Hasil Akhir ---
    printf("\n------------------------------------------\n");
    printf("Total Biaya Servis Akhir: $%.2f\n", total_biaya);
    printf("------------------------------------------\n");

    return 0;
}
