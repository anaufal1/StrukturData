#include<stdio.h>
#include<stdlib.h>
#define new(lul) (lul*) malloc (sizeof(lul))
#define judul printf("-------------------------TOWER OF HANOI-------------------------\n---------------------------LUL VERSION--------------------------\n\n");

int counter = 0;

typedef struct node{
	int value;
	struct node *down;
}node_t;

typedef struct{
	node_t *top;
}stack;

void Push(int val, stack* s){
	node_t *temp = (node_t*) malloc (sizeof(node_t));
	temp->value = val;
	temp->down = s->top;
	s->top = temp;
}

void Print(stack *s){
	node_t *temp;
	int i;
	temp = s->top;
	i = 0;
	while(temp != NULL){
		if(i != 0){
			printf("->");
		}
		printf("%d", temp->value);
		temp = temp->down;
		i++;
	}
	printf("\n");
}

void Pop(stack *s){
	if(!s->top) return;
	node_t* temp;
	temp = s->top;
	s->top = s->top->down;
	free(temp);
}

int SearchMax(stack *s){
	if(!s->top) return -1;
	node_t *temp;
	temp = s->top;
	int max = -1;
	while(temp){
		if(temp->value >= max){
			max = temp->value;
		}
		temp = temp->down;
	}
	return max;
}

void pindah(stack *dari, stack *perantara, stack *ke, int max, char namaDari, char namaPerantara, char namaKe){
	node_t *temp;
	temp = dari->top;
	while(temp->value != max){
		printf("->Pindahkan Blok %d dari Stack %c ke Stack %c\n", temp->value, namaDari, namaPerantara);
		Push(temp->value, perantara);
		temp = temp->down;
		Pop(dari);
		counter++;
	}
	printf("->Pindahkan Blok %d dari Stack %c ke Stack %c\n", temp->value, namaDari, namaKe);
	Push(temp->value, ke);
	Pop(dari);
	counter++;
}

int main(){
	judul;
	printf("Program ini memindahkan blok cari stack A ke stack C dengan bantuan stack B\n-Pengambilan hanya boleh mengambil blok teratas dari stack\n-Hasilnya adalah stack C dengan blok sudah terurut\n\n");
	stack *a = new(stack);
	stack *b = new(stack);
	stack *c = new(stack);
	a->top = NULL;
	b->top = NULL;
	c->top = NULL;
	char i = 'A', j = 'B', k = 'C';
	
	int n, val, maxA, maxB;
	
	printf("Masukkan jumlah blok yang ingin dimasukkan ke stack A : ");
	scanf("%d", &n);
	printf("Masukkan blok yang ingin dimasukkan ke stack A (input dari bawah ke atas) :\n");
	while(n != 0){
		scanf("%d", &val);
		Push(val, a);
		n--;
	}
	
	printf("\nKeadaan Stack saat ini (dari atas ke bawah):\n");
		printf("Stack A : ");
		Print(a);
		printf("Stack B : ");
		Print(b);
		printf("Stack C : ");
		Print(c);
		printf("\n");
	
	while(1){
		if(!a->top && !b->top){
			break;
		}
		maxA = SearchMax(a);
		maxB = SearchMax(b);
		if(maxA >= maxB){
			pindah(a, b, c, maxA, i, j, k);
		}
		else if(maxA < maxB){
			pindah(b, a, c, maxB, j, i, k);
		}
		printf("\nKeadaan Stack saat ini (dari atas ke bawah):\n");
		printf("Stack A : ");
		Print(a);
		printf("Stack B : ");
		Print(b);
		printf("Stack C : ");
		Print(c);
		printf("\n");
	}
	
	return 0;
}
