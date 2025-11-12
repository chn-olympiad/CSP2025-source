#include<cstdio>
#include<cstring>
int tong[10];
char x[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",x);
	int len=strlen(x);
	for(int i=0;i<len;i++){
		if(x[i]>='0'&&x[i]<='9'){
			tong[x[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(tong[i]>0){
			tong[i]--;
			printf("%d",i);
		}
	}
	
	
	
	return 0;
}
