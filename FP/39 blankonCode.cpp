#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

int convertBinaryToDecimal(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int main(){

	int tc;
	scanf("%d",&tc);
	//cin>>tc;
	//cout<<tc<<endl;
	//getchar();
	//printf("%d\n",tc);
	int binary=0;
	bool first=false;
	int decimal;
	char output[10001];
	int idx=0;
	bool sign=false;
	char string[10001];
    int j;

	for(j=1; j<=tc; j++){

		scanf("%s",&string);
		//gets(string);

			int len= strlen(string);
			first=false;
			binary=0;

			for(int i=0; i<len; i++){
				if(string[i]=='-'){

					if(first==false){
						binary+=1;
						sign=false;
					}else{
						binary*=10;
						binary+=1;
					}



					first=true;

				}else if(string[i]=='.'){

					if(first==false){
						binary+=0;
                        sign=false;
					}else{
						binary*=10;
						binary+=0;
					}


					first=true;
				}else if(string[i]=='/'&& sign==false){

					first=false;
					decimal=convertBinaryToDecimal(binary);
					decimal+=64;
					output[idx]=decimal;
					idx++;
					binary=0;

				}else if(string[i]=='#'){
					output[idx]=' ';
					idx++;
					sign=true;
				}


			}



    idx=0;
    //int j ;
	//int leno=strlen(output);

/*	for(j=0; j<leno; j++){
		printf("%c",output[j]);
	}*/
    printf("Case #%d: ",j);
    puts(output);
    //printf("\n");
    memset(output,'\0',sizeof(output));


	}




	return 0;
}
