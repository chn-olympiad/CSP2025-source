#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<array>
#include<tuple>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<random>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define y0 yy0
#define y1 yy1
#define yn yyn
#define j0 jj0
#define j1 jj1
#define jn jjn
#define IOS ios::sync_with_stdio(false)
#define PY puts("Yes")
#define PN puts("No")
#define PW puts("-1")
#define P0 puts("0")
#define P__ puts("")
#define PU puts("--------------------")
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
#define reprange(a,b,c,d) for(int a=(b);a<=(c);a+=(d))
#define perrange(a,b,c,d) for(int a=(b);a>=(c);a-=(d))
#define graph(i,j,k,l) for(int i=k[j];i;i=l[i].nxt)
#define mp make_pair
#define pc putchar
#define fi first
#define se second
#define pb emplace_back
#define un using namespace
#define il inline
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof x)
#define lson(p) ((p)<<1)
#define rson(p) ((p)<<1|1)
#define lowbit(p) ((p)&-(p))
//#define double long double
#define int long long
//#define int __int128
using namespace std;
un __gnu_pbds;
template<typename T1,typename T2>inline bool ckmx(T1 &x,T2 y){return x>=y?0:(x=y,1);}
template<typename T1,typename T2>inline bool ckmn(T1 &x,T2 y){return x<=y?0:(x=y,1);}
using i64=long long;
using u64=unsigned long long;
using pii=pair<int,int>;
inline auto rd(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;
}
template<typename T>inline void write(T x,char ch='\n'){
	if(x<0)putchar('-'),x=-x;
	int y=0;static char z[50];
	while(x||!y)z[y++]=x%10+48,x/=10;
	while(y--)putchar(z[y]);if(ch)putchar(ch);
}
bool Mbg;
const int mod=998244353;
template<typename T1,typename T2>inline void adder(T1 &x,T2 y){x+=y,x=x>=mod?x-mod:x;}
template<typename T1,typename T2>inline void suber(T1 &x,T2 y){x-=y,x=x<0?x+mod:x;}
const int maxn=505,inf=0x3f3f3f3f;
const long long llinf=0x3f3f3f3f3f3f3f3f;
int n,m,a[maxn];
char s[maxn];
int cnt[maxn],sum[maxn];
int f[2][maxn][maxn];
int fac[maxn],C[maxn][maxn];
inline void solve_the_problem(){
	n=rd(),m=n-rd(),scanf("%s",s+1);
	rep(i,1,n)a[i]=rd(),cnt[a[i]]++;
	sum[0]=cnt[0];
	rep(i,1,n)sum[i]=sum[i-1]+cnt[i];
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*i%mod;
	C[0][0]=1;rep(i,1,n){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	f[0][0][cnt[0]]=1;
	rep(i,1,n){
		const int t=i&1;mem(f[t],0);
		rep(j,0,m)rep(k,0,n)if(f[t^1][j][k]){
			int rem=i-1-sum[j]+k;
			assert(rem>=0);
			//ci<=j
			if(k){
				rep(l,0,min(rem,cnt[j+1])){
					int res=C[rem][l]*fac[l]%mod*C[cnt[j+1]][l]%mod;
					adder(f[t][j+1][k-1+cnt[j+1]-l],f[t^1][j][k]*k%mod*res%mod);
				}
			}
			//ci>j
			if(s[i]=='0'){
				rep(l,0,min(rem+1,cnt[j+1])){
					int res=C[rem+1][l]*fac[l]%mod*C[cnt[j+1]][l]%mod;
					adder(f[t][j+1][k+cnt[j+1]-l],f[t^1][j][k]*res%mod);
				}
			}else{
				adder(f[t][j][k],f[t^1][j][k]);
			}
		}	
	}
	int ans=0;
	rep(i,0,m){
		adder(ans,f[n&1][i][0]*fac[sum[n]-sum[i]]%mod);
	}
	write(ans);
}
bool Med;
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	fprintf(stderr,"%.3lfMB\n",(&Mbg-&Med)/1048576.0);
	int _=1;
	rep(__,1,_)solve_the_problem();
}
/*
16:58 finished.
*/

