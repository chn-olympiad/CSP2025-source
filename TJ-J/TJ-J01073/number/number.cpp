#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int b[1000010];
int k=0;
int c[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	/*for(int i=1;i<=len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			k++;
			b[k]=a[i]-48;
		}
	}
	if(k==1){
		printf("%d",b[k]);
	}
	for(int j=1;j<=k;j++){
		for(int i=1;i<=k-1;i++){
			if(b[i]<b[i+1]){
				int h=b[i];
				b[i]=b[i+1];
				b[i+1]=h;
			}
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d",b[i]);
	}*/
	for(int i=1;i<=len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			k++;
			b[k]=a[i]-48;
			if(b[k]==9){
				c[9]++;
			}else if(b[k]==8){
				c[8]++;
			}else if(b[k]==7){
				c[7]++;
			}else if(b[k]==6){
				c[6]++;
			}else if(b[k]==5){
				c[5]++;
			}else if(b[k]==4){
				c[4]++;
			}else if(b[k]==3){
				c[3]++;
			}else if(b[k]==2){
				c[2]++;
			}else if(b[k]==1){
				c[1]++;
			}else{
				c[10]++;
			}
		}
	}
	for(int i=1;i<=c[9];i++){
		printf("9");
	}
	for(int i=1;i<=c[8];i++){
		printf("8");
	}
	for(int i=1;i<=c[7];i++){
		printf("7");
	}
	for(int i=1;i<=c[6];i++){
		printf("6");
	}
	for(int i=1;i<=c[5];i++){
		printf("5");
	}
	for(int i=1;i<=c[4];i++){
		printf("4");
	}
	for(int i=1;i<=c[3];i++){
		printf("3");
	}
	for(int i=1;i<=c[2];i++){
		printf("2");
	}
	for(int i=1;i<=c[1];i++){
		printf("1");
	}
	for(int i=1;i<=c[10];i++){
		printf("0");
	}
	//printf("%d",len);
	//printf("Time:%d",clock());
	return 0;
}








