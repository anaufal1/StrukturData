
#include<stdio.h>
#include<string.h>
#define table_size 1001

char hash_table[101][table_size][101];
int i, count;
char input[105], perintah[4], data[101];

int HashColl(int hashKey){
	int j;
	int temp = hashKey;
	int index = -1;
	for(j = 1; j <= 20; j++){
		hashKey += j * j + 23 * j ;
		if(strcmp(data, hash_table[i][hashKey]) == 0){
			return -1;
		}
		if(hash_table[i][hashKey][0] == '\0' && index == -1){
			index = hashKey;
		}
		hashKey = temp;
	}
	return index;
}

int HashCollDel(int hashKey){
	int j;
	for(j = 1; j <= 20; j++){
		hashKey += j * j + 23 * j;
		if(strcmp(data, hash_table[i][hashKey]) == 0){
			return hashKey;
		}
	}
	return -1;
}

int Hash(){
	int len = strlen(data);
	int z, sum = 0;
	
	for(z = 0; z < len; z++){
		sum += (z + 1) * data[z];
	}
	
	sum *= 19;
	sum %= 101;
	
	if(hash_table[i][sum][0] == '\0'){
		return sum;
	}
	else{
		if(strcmp(data, hash_table[i][sum]) == 0){
			return -1;
		}
		return HashColl(sum);
	}
}

int HashDelete(){
	int len = strlen(data);
	int z, sum = 0;
	
	for(z = 0; z < len; z++){
		sum += (z + 1) * data[z];
	}
	
	sum *= 19;
	sum %= 101;
	
	if(strcmp(data, hash_table[i][sum]) == 0){
		return sum;
	}
	else{
		return HashCollDel(sum);
	}
}

void Insert(){
	int index = Hash(data);
	if(index == -1){
		return;
	}
	strcpy(hash_table[i][index], data);
	count++;
}

void Delete(){
	int index = HashDelete(data);
	if(hash_table[i][index][0] != '\0') count--;
	hash_table[i][index][0] = '\0';
}

void Check(){
	strncpy(perintah, input, 3);
	strcpy(data, &input[4]);
}

void Print(){
	int n;
	for(n = 0; n < 1001; n++){
		if(hash_table[i][n][0] != '\0'){
			printf("%d:%s\n", n, hash_table[i][n]);
		}
	}
}

int main(){
	int q, n, k;
	
	scanf("%d", &q);
	
	for(i = 0; i < q; i++){
		count = 0;
		scanf("%d", &n);
		for(k = 0; k < n; k++){
			scanf("%s", input);
			Check();
			if(strcmp(perintah, "ADD") == 0){
				Insert(data);
			}
			else if(strcmp(perintah, "DEL") == 0){
				Delete(data);
			}
		}
		printf("%d\n", count);
		Print();
	}
	
	return 0;
}
