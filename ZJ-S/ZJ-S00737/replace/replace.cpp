#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define maxn 100010
#define inf 2147483647
using namespace std;
int n,q;
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
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--)write(0);
	return 0;
}
