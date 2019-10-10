#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void urutin(int arr[], int jumlah);
void bin_search(int arr[], int cari, int jumlah);
void inter_search(int arr[], int cari, int jumlah);

int main(void){
	printf("\nBINARY SEARCH\n\n");
	int i, cari, jumlah_data;
	printf("Masukkan jumlah data : ");
	scanf("%d", &jumlah_data);
	int arr[jumlah_data];
	printf("generating sorted %d random number...\n", jumlah_data);
	for(i = 0; i < jumlah_data; i++){
		arr[i] = rand()/(RAND_MAX/jumlah_data)+1;
	}
	urutin(arr, jumlah_data);
	for(i = 0; i < jumlah_data; i++){
		printf("%d ", arr[i]);
	}
	printf("\ndone.\n\nMasukkan data yang ingin dicari : ");
	scanf("%d", &cari);
	bin_search(arr, cari, jumlah_data);
	
}

void urutin(int arr[], int jumlah){
	int i, j, temp;
	for(i = 0; i < jumlah; i++){
		for(j = i+1; j < jumlah; j++){
			if(arr[j] < arr[i]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

void bin_search(int arr[], int cari, int jumlah){
	int awal, akhir, tengah, cek, count, i;
	awal = 0;
	akhir = jumlah-1;
	cek = 0;
	count = 0;
	for(i = 0;; i++){
		tengah = (awal + akhir) / 2;
		count++;
		printf("\n%d %d %d\n", awal, tengah, akhir);
		if(arr[awal] == cari || arr[tengah] == cari || arr[akhir] == cari){
			cek = 1;
			break;
		}
		else if(arr[tengah] < cari){
			awal = tengah+1;
		}
		else{
			akhir = tengah-1;
		}
		if(awal == akhir && cek == 0){
			break;
		}
	}
	if(cek == 1){
		printf("\nBinary Search\nData %d ketemu ! Butuh %d langkah", cari, count);
	}
	else{
		printf("\nBinary Search\nData %d tidak ketemu ! Butuh %d langkah", cari, count);
	}
}
