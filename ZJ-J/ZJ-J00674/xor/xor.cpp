#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 2147483647
#define maxn 500010
using namespace std;
int n,k,ans=0,poi=1;
int a[maxn],s[maxn];
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
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();s[0]=0;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i]==k){
			++ans,poi=i+1;
//			write(i);
			continue;
		}
		int xxo=a[i];
		if(xxo==0)continue;
		for(int j=i-1;j>=poi;--j){
			xxo^=a[j];
			if(xxo==k){
				++ans,poi=i+1;
//				print(j),putchar(' '),write(i);
				break;
			}
		}
	}
	write(ans);
	return 0;
}
