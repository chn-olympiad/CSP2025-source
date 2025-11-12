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
//#define DEBUG
#define N 510
constexpr int mod(998244353);
char s[N];
int c[N],ccnt,n,m,f[N],cnt,ans;
#ifdef DEBUG
int pos[N];
inline void print(){
	for(int i=1;i<=n;++i) write(pos[i],' ');
	pc('\n');
}
#endif
bool vis[N];
void dfs(int x=1,int pass=0){
	if(pass+n-x+1<m) return;
	if(x==n+1){
		++ans;
		#ifdef DEBUG
		print();
		#endif
		return;
	}
	for(int i=1;i<=n;++i) if(!vis[i]){
		#ifdef DEBUG
		pos[x]=i;
		#endif
		vis[i]=1;
		dfs(x+1,pass+((s[x]^48)&&((x-1-pass)<c[i])));
		vis[i]=0;
	}
}
signed main(){
	#ifndef NoFreopen
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	read(n,m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) read(c[i]);
	for(int i=1;i<=n;++i) if(c[i]) ++ccnt;
	for(int i=1;s[i];++i) cnt+=(s[i]^48);
//	f[0]=1;
//	for(int i=1;i<=n;++i) f[i]=(f[i-1]*i)%mod;
//	if(cnt==n) return write(ccnt>=m?f[n]:0),0;
	if(ccnt<m||cnt<m) return pc('0'),0;
	dfs();
	write(ans);
	return 0;
}
