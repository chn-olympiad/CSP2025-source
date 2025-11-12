#include<bits/stdc++.h>
#define N 1000500
#define ed puts("")
//#define mod 1000000007
#define p_ putchar(' ')
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar(45);
		x=~x+1;
	}
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top) putchar(sta[--top]+48);
	return;
}
int n,m,x,num;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		x=read();
		if(x==0) ++num;
	}
	write(num);
	return 0;
}
