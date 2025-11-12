#include<bits/stdc++.h>
using namespace std;
char st[1000005];
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",st);
	int n=strlen(st);
	for(int i=0;i<n;i++){
		if(st[i]>='0'&&st[i]<='9')a[st[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)putchar(i+48);
	}
	putchar(10);
	return 0;
}