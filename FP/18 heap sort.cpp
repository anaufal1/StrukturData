#include<cstdio>
#include<vector>
#define judul printf("=====================================================================\n||                             HEAP SORT                           ||\n=====================================================================\n\n");
					  
using namespace std;

void Print(vector <int> *vec){
	for(int i = 0; i < (*vec).size(); i++){
		printf("%d ", (*vec)[i]);
	}
	printf("\n");
}

void Swap(vector <int> *vec, int a, int b){
	int temp = (*vec)[a];
	(*vec)[a] = (*vec)[b];
	(*vec)[b] = temp;
}

void HeapIt(vector <int> (*vec), int n, int i){
	int largest = i;
	int leftChild = (2 * i) + 1;
	int rightChild = (2 * i) + 2;
	
	if(leftChild < n && (*vec)[leftChild] > (*vec)[largest]){
		largest = leftChild;
	}
	if(rightChild < n && (*vec)[rightChild] > (*vec)[largest]){
		largest = rightChild;
	}
	if(largest != i){
		Swap(vec, i, largest);
		Print(vec);
		HeapIt(vec, n, largest);
	}
}

void HeapSort(vector <int> *vec, int n){
	printf("\nMengubah array menjadi Heap :\n");
	for(int i = n / 2; i >= 0; i--){
		HeapIt(vec, n, i);
	}
	for(int i = n - 1; i >= 0; i--){
		Swap(vec, 0, i);
		printf("\nSwap data terakhir menjadi root : ");
		Print(vec);
		printf("\nReHeap :\n");
		HeapIt(vec, i, 0);
	}
}

int main(){
	judul;
	vector <int> vec;
	int n, val;
	
	printf("Masukkan jumlah data yang ingin di uturkan (ascending) : ");
	scanf("%d", &n);
	printf("Masukkan data yang ingin di urutkan :\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		vec.push_back(val);
	}
	printf("\nProses pengurutan...\n");
	
	HeapSort(&vec, n);
	
	printf("\nData setelah diurutkan (ascending) :\n");
	Print(&vec);
	
}
