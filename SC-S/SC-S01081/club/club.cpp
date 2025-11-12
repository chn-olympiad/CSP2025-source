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
#define N 33
int n,a[N][4],dp[N][N>>1][N>>1][N>>1];
inline void gmax(int &a,int b){if(a<b) a=b;}
inline void work(){
	memset(dp,0,sizeof dp);
	read(n);
	for(int i=1;i<=n;++i) for(int j=1;j<=3;++j) read(a[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=0;j<=n>>1&&j<=i;++j){
			for(int k=0;k<=n>>1&&j+k<=i;++k){
				int Limit(min(n>>1,i-j-k));
				for(int x=0;x<=Limit;++x){
					int &kk=dp[i][j][k][x];
					if(j) kk=dp[i-1][j-1][k][x]+a[i][1];
					if(k) gmax(kk,dp[i-1][j][k-1][x]+a[i][2]);
					if(x) gmax(kk,dp[i-1][j][k][x-1]+a[i][3]);
				}
			}
		}
	}
	int ans(0);
	for(int i=1;i<=n>>1;++i){
		for(int j=1;j<=n>>1;++j) gmax(ans,dp[n][i][j][n-i-j]);
	}
	write(ans,'\n');
}
signed main(){
	#ifndef NoFreopen
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	int t;
	read(t);
	for(int i=1;i<=t;++i) work();
	return 0;
}
