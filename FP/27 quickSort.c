#include<stdio.h>

void qSort(int L, int R, int arr[]);
void swap(int *a, int *b);

int main(void){
	int arr[1000];
	int i, j, k, a, b, c;
	printf("\n------------------------QUICK SORT------------------------\n\n");
	printf("Masukkan Jumlah Data Yang Diinginkan : \n");
	scanf("%d", &a);
	printf("Masukkan Data Yang Diinginkan : \n");
	for(i = 0; i < a; i++){
		scanf("%d", &arr[i]);
	}
	qSort(0, a - 1, arr);
	printf("\nData Hasil Sorting Ascending :\n");
	for(i = 0; i < a; i++){
		printf("%d ", arr[i]);
	}
}

void swap(int *a, int *b){
	int temp;
	temp = *a; 
	*a = *b;
	*b = temp;
}

void qSort(int L, int R, int arr[]){
	int x, j, i, k, temp;
	x = arr[(L + R) / 2];
	i = L;
	j = R;
	while(i <= j){
		while(arr[i] < x){
			i++;
		}
		while(arr[j] > x){
			j--;
		}
		if(i <= j){
			swap(&arr[i], &arr[j]);
			j--;
			i++;
		}
	}
	if(L < j){
		qSort(L, j, arr);
	}
	if(i < R){
		qSort(i, R, arr);
	}
}
