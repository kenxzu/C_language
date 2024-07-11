#include<stdio.h>


int main(){
int hargaMobil, pembayaranAwal, cicilanPerbulan, sisaTagihan, bulan = 0, sisaBulan;


    printf("Masukan Harga mobil : ");
    scanf("%d", &hargaMobil);
    printf("Pembayaran Awal : ");
    scanf("%d", &pembayaranAwal);
    printf("Cicilan Perbulan  : ");
    scanf("%d", &cicilanPerbulan);

sisaTagihan = hargaMobil - pembayaranAwal;

while (sisaTagihan > 0 ){
    
    int pilih;
    do{
    printf("\n1. Lihat jumlah bulan lunas : ");
    printf("\n2. Bayar Tagihan Rp 500000 : ");
    printf("\nMasukan Pilihan ");
    scanf("%d", &pilih);
    }while(pilih > 2);
    if(pilih == 1 ){
        sisaBulan = sisaTagihan/cicilanPerbulan;
        printf("Sisa Bulan : %d", sisaBulan);
    }if(pilih == 2 ){

        sisaTagihan = sisaTagihan - cicilanPerbulan;
        bulan += 1;
        printf("\nTerimakasih telah melakukan pembayaran\n");
        printf("Jumlah bulan : %d \n\n", bulan);
        
    }

sisaBulan = sisaBulan -1;
}
    printf("\nTagihan anda lunas \n");
    printf("Jumlah Bulan : %d\n\n", bulan);  

    return 0 ;
}

