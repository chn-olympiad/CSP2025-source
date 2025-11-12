#include<bits/stdc++.h>
using namespace std;
#ifdef __unix
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
inline int read(){return 0;}
template<typename A,typename ...B>
int read(A &x,B&...y){
	x=0;int f=1,c=gc();
	for(;!isdigit(c);c=gc()){
		if(!(~c)) return 0;
		if(c=='-') f=-1;
	}
	for(;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^48);
	return x*=f,read(y...)+1;
}
inline void Write(char c){pc(c);}
inline void Write(const char *a){
	for(int i=0;a[i];++i) pc(a[i]);
}
template<typename T>
void Write(T x){
	if(x<0) pc('-'),x=-x;
	if(x<10) return pc(x^48),void(0);
	Write(x/10),pc((x%10)^48);
}
inline int write(){return 0;}
template<typename A,typename ...B>
int write(A x,B...y){
	Write(x);
	return write(y...)+1;
}
#define int long long
//#define NoFreopen
#define N 10015
#define M 1000010
int fa[N],c[N],a[11][N],n,m,k;
struct Edge{
	int u,v,w;
	inline void read(){::read(u,v,w);}
	inline bool operator<(const Edge &b)const{return w<b.w;}
}e[M];
int Find(int x){return fa[x]==x?x:fa[x]=Find(fa[x]);}
inline bool merge(int x,int y){
	x=Find(x),y=Find(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}
inline void krustra(){
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i) fa[i]=i;
	int cnt(0),ans(0);
	for(int i=1;i<=m;++i){
		if(merge(e[i].u,e[i].v)){
			ans+=e[i].w;
			++cnt;
			if(cnt==n-1) return write(ans),void(0);
		}
	}
}
signed main(){
	#ifndef NoFreopen
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	read(n,m,k);
	for(int i=1;i<=m;++i){
		e[i].read();
	}
	if(!k) return krustra(),0;
	bool f(0);
	for(int i=1;i<=k;++i){
		read(c[i]);
		f|=c[i];
		for(int j=1;j<=n;++j) read(a[i][j]),f|=a[i][j];
	}
	if(!f) return puts("0"),0;
	return 0;
}
