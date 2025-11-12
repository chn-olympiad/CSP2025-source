#include<bits/stdc++.h>
using namespace std;
int a[11]={};
bool flag=1;
char b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	b=getchar();
	while(b!='\n'){
		if(b>='0'&&b<='9'){
			int c=b-'0';
			a[c]+=1;
			if(b!='0'){
				flag=0;
			}
		}
		b=getchar();
	}
	if(flag){
		printf("0");
	}else{
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}