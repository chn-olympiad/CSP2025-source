#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define inf 2147483647
#define maxn 100010
using namespace std;
int n,m,mine,now,uper=0;
int line,row,mod;
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
void write(int x){print(x);putchar(' ');}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;++i){
		now=read();if(i==1)mine=now;
		if(now>mine)++uper;
	}
	++uper;
	line=uper/n;mod=uper%n;
	if(mod==0)mod=n;
	else ++line;
	if(line%2==1)row=mod;
	else row=n-mod+1;
	write(line),write(row);
	return 0;
}
