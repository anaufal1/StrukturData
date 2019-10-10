/* Program Untuk Mengecek Keseimbangan Tree */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define bool int

using namespace std;

/* Suatu binary tree node mempunyai data, pointer ke left child, dan pointer ke right child  */
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
 
/* Function untuk mengecek keseimbangan, dimana akan bernilai return true jika root telah seimbang.
   Dan parameter kedua (*height) berfungsi untuk menyimpan tinggi tree. 
   Untuk inisialisasi awal, diperlukan sebuah pointer dengan lokasi nilai awal = 0 */
   
bool isBalanced(struct node *root, int* height)
{
  /* h_kiri adalah tinggi dari left subtree
     h_kanan adalah tinggi dari right subtree */   
  int h_kiri = 0, h_kanan = 0; 
 
  /* l akan bernilai true jika left subtree seimbang
    and r akan bernilai true jika right subtree seimbang */
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  } 
  /* Dapatkan tinggi dari left and right subtree melalui h_kiri and h_kanan
    dan simpan pengembalian nilai di l dan r */   
  l = isBalanced(root->left, &h_kiri);
  r = isBalanced(root->right,&h_kanan);
 
  /* Tinggi dari current node adalah maksimal tinggi dari kiri and
     kanan subtree plus 1 */   
  *height = (h_kiri > h_kanan? h_kiri: h_kanan) + 1;
     
  /* Jika perbedaan tinggi antara left dan right
     subtree lebih dari 2, maka node ini dikatakan tidak seimbang
     so return 0 */
  if((h_kiri - h_kanan >= 2) || (h_kanan - h_kiri >= 2))
    return 0;
     
  /* Jika node ini telah seimbang dan left, serta right subtree
    juga seimbang, maka return bernilai true */
  else return l&&r;
}
 
/* Function Tambahan untuk mengetes fungsi isBalanced() */
 
/* Function untuk mengalokasikan sebuah newNode dengan data dan NULL left right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
    malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

/* Function Utama */
int main()
{
  int height = 0;
  /* Contoh konstruksi binary tree yang dibuat adalah
             8
           /   \
         5      7
       /  \    / \
     1    2   3   4
    
  */   
  
  cout<<"|---------------------- Apakah BST tersebut BALANCE ?---------------------|"<<endl<<endl;
 
  struct node *root = newNode(8); 
  
  //Bisa ditambahkan kondisi Tree disini
  root->left = newNode(5);
  root->right = newNode(7);
  root->left->left = newNode(1);
  root->left->right = newNode(2);
  root->right -> right = newNode(4);
  root->right -> left = newNode(3);
    
  if(isBalanced(root, &height))
    cout<<"   Kondisi BST seimbang";
  else
    cout<<"   Kondisi BST tidak seimbang";   
  getchar();
  
  return 0;
}
