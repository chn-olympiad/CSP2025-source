#include<bits/stdc++.h>
#define maxn 10000005
using namespace std; 
int n,num[maxn],f;
char s1[maxn];
int find_num(char a){
	a-='0';
	if (a>=0&&a<=9)return a;
	else return -1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s1);
	int len =strlen(s1);
	for (int i=0;i<len;i++){
		int temp=find_num(s1[i]);
		if (temp!=-1)num[temp]++;
	}
	for (int i=9;i>=0;i--){
		if (f==0&&i==0){
			printf("0");
			break;
		}
		for (int j=1;j<=num[i];j++){
			printf("%d",i);
			f=1;
		}
	}
	return 0;
}
