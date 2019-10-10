#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void selection_sort(int arr[], int a);
void insertion_sort(int arr[], int a);
void bubble_sort(int arr[], int a);
void cetak(int arr[], int a);
void swap(int x, int y, int arr[]);

int main()
{
	int arr_s[1000], a, i, arr_i[1000], arr_b[1000];
	printf("\nASCENDING SORTING PROGRAM\n\n");
	printf("Masukkan jumlah data yang diinginkan : ");
	scanf("%d",&a);
	printf("Masukkan data yang ingin diurutkan\n");
	for(i=0; i<a; i++){
		scanf("%d",&arr_s[i]);
		arr_i[i]=arr_s[i];
		arr_b[i]=arr_s[i];
	}
	bubble_sort(arr_b, a);
	printf("\n");
	selection_sort(arr_s, a);
	printf("\n");
	insertion_sort(arr_i, a);
	return 0;
}
void bubble_sort(int arr[], int a){
	int i, j, count=0;
	printf("\nBUBBLE SORT\n");
	bool swapped;
	for(i=0; i<a; i++){
		swapped=false;
		for(j=a-1; j>i; j--)
		 if(arr[j]<arr[j-1]){
		 	swap(j, j-1, arr);
		 	count++;
		 	swapped=true;
		 }
		 if(!swapped) break;
	}
	printf(" Data terurut:\t");
	for(i=0; i<a; i++){
		printf("%d ", arr[i]);
	}
	printf("\n Butuh %d langkah\n", count);
}
void selection_sort(int arr[], int a){
	int i, j, x, temp, c, count;
	count=0;
	printf("\nSELECTION SORT\n");
	for(i=0;i<a;i++){
		temp=arr[i];
		c=i;
		for(j=i+1;j<a;j++){
			if(temp>arr[j]){
				temp=arr[j];
				c=j;
				count++;
			}
		}
		arr[c]=arr[i];
		arr[i]=temp;
	}
	printf(" Data terurut:\t");
	for(i=0; i<a; i++){
		printf("%d ", arr[i]);
	}
	printf("\n Butuh %d langkah\n", count);
}
void insertion_sort(int arr[], int a){
	int i, j, k, l, temp, count;
	printf("\nINSERTION SORT\n");
	count=0;
	for(i=0; i<a-1; i++){
		temp=arr[i+1];
		for(j=i; j>=0; j--){
			if(arr[j]>temp) {	
				arr[j+1]=arr[j];
				count++;
			}
			else break;
		}
		arr[j+1]=temp;
	}
	printf(" Data terurut:\t");
	for(i=0; i<a; i++){
		printf("%d ", arr[i]);
	}
	printf("\n Butuh %d langkah", count);
}
void swap(int x, int y, int arr[]){
	int temp;
	temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
