#include<bits/stdc++.h>
//#define DBG

#ifdef DBG
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#else
#define dbg(...) void()
#endif

#define il inline __attribute((always_inline))

using u32=unsigned int;
using i64=long long;
using u64=unsigned long long;

template<typename T=int>
T read(){
	T x=0;char c=getchar(),f=0;
	while(c<'0'||'9'<c) f=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=x*10+(c&15),c=getchar();
	return f?-x:x;
}

template<typename T>
void print(T x){
	if(x==0) return putchar('0'),void();
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10),x%=10;
	putchar(x|'0');
}

int c[1000],p[1000];
char s[1000];

int main(){
#ifndef ZIGAO
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
#endif
	
	int i,now,cnt,res=0;
	int n=read();
	int m=read();
	scanf("%s",s);
	for(i=0;i<n;++i) c[i]=read(),p[i]=i;
	do{
		now=cnt=0;
		for(i=0;i<n;++i){
			if(s[i]=='1'&&now<c[p[i]]) ++cnt;
			else ++now;
		}
		if(cnt>=m) ++res;
	}while(std::next_permutation(p,p+n));
	
	print(res);
	
	return 0;
}