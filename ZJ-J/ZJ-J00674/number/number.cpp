#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 2147483647
#define maxn 100010
using namespace std;
int a[20];
char v;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(int x){print(x);putchar('\n');}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=9;++i)a[i]=0;
	while(cin>>v)if(isdigit(v))a[v-48]++;
	for(int i=9;i>=0;--i)
		for(int j=1;j<=a[i];++j)putchar(i+48);
	return 0;
}
