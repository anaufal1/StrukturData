#include<bits/stdc++.h>
using namespace std;
struct Node
{
int data;
struct Node *next;
};
Node *newNode(int data)
{
Node *temp = new Node;//buat node dengan isi data dan next
temp->data = data;//mengisi nilai data dengan int data
temp->next = temp;//temp selanjutnya menunjuk ke temp sendiri,jadi bukan NULL

}
int orangterakhir(int m, int n)
{
Node *head = newNode(1);//head diisi dengan new node yang nilainya 1
Node *prev = head;//membuat node pointer prev yang menunjuk head
for (int i = 2; i <= m; i++)//looping hingga ada berpa jumlah orang
{
prev->next = newNode(i);//prev->nextdiisi oleh node baru yang nilainya sama dengan i
prev = prev->next;//prev menunjuk ke prev->next
}
prev->next = head;//untuk prev->next terakhir menunjuk ke head
Node *ptr1 = head, *ptr2 = head;//membuat 2 pointer baru yang menunjuk ke head
while (ptr1->next != ptr1)//jika pointer1 next tidak ketemu dengan pointer 1 snddiri
{
int count = 1;//membuat integer count dengan nilai 1
while (count != n)//jika count tidak sama dengan n
{
ptr2 = ptr1;//pointer 2 menunjuk pointer 1
ptr1 = ptr1->next;//pointer 1 menunjuk ke pointer 1 next
count++;//count++
}
ptr2->next = ptr1->next;//pointer2->next menunjuk ke pointer 1 next
ptr1 = ptr2->next;//pointer 1 menunjuk ke pointer 2 next
}
printf ("%d\n",
ptr1->data);//akan mengeprint data yang paling terakhir sesuai dengan cara yang dilakukan diatas
}
int main(){
	int a,b,c,t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&a);
		scanf("%d",&b);
		orangterakhir(a,b);
	}
	return 0;
}
