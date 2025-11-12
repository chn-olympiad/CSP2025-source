//16:29: what? why not dir do?
#include<bits/stdc++.h>

#define _vc_(_6,_5,_4,_3,_2,_1,_,...) _
#define _vc(a...) _vc_(a,6,5,4,3,2,1)
#define _ct_(a,b) a##b
#define _ct(a,b) _ct_(a,b)
#define deb1(a) <<#a<<"="<<(a)<<"; "
#define deb2(a,b...) deb1(a)deb1(b)
#define deb3(a,b...) deb1(a)deb2(b)
#define deb4(a,b...) deb1(a)deb3(b)
#define deb5(a,b...) deb1(a)deb4(b)
#define deb6(a,b...) deb1(a)deb5(b)
#define deb(a...) cerr<<string(_dep*3,' ')<<"deb"<<__LINE__<<"|:" _ct(deb,_vc(a)) (a) <<endl
unsigned _dep;

using namespace std;

const int maxn=510, mod=998244353;

int n,m;
char S[maxn];

int c_leq[maxn];

//int
long long f[2][maxn][maxn];
//prefix [i], select [j], and fix [k] bad


signed main(){
	
//	cerr<<(sizeof f  >> 20);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>(char(&)[maxn])S[1];
	for(int i=1,c;i<=n;++i)cin>>c,++c_leq[c];
	for(int i=1;i<=n;++i)c_leq[i]+=c_leq[i-1];
	
	f[0][0][0] = 1;
	int cnt_0=0;
	for(int i=1;i<=n;++i){
		memset(f[i&1],0,sizeof f[0]);
		
		if(S[i] == '0'){
			++cnt_0;
			for(int j=0;j<i;++j)
				for(int k=0;k<i;++k)
					f[i&1][j][k] = f[~i&1][j][k];
		}else{
			//select
			
			for(int j=0;j<i;++j){
				for(int k=0;k<i;++k){
					(f[i&1][j+1][k] += f[~i&1][j][k])%=mod;
					f[i&1][j+1][k+1]=(f[i&1][j+1][k+1] 
						- 1ll*f[~i&1][j][k] * max((int)0,(int)(c_leq[min(n,i-j-1)] - k)) )%mod;
				}
			}
			
			//unselect
			
			for(int j=0;j<i;++j){
				for(int k=0;k<i;++k){
					f[i&1][j][k+1]=(f[i&1][j][k+1]
						+ 1ll*f[~i&1][j][k] * max((int)0,(int)(c_leq[min(n,i-j-1)] - k)) )%mod;
				}
			}
		}
	}
	
	long long ans=0;
	for(int j=m;j<=n;++j){
		long long fac=1;
		for(int k=n;~k;--k){
			
//			deb(j,k,f[n&1][j][k], fac);
			
			(ans += f[n&1][j][k] * fac) %= mod;
			(fac *= n-k+1) %= mod;
		}
	}
	
	cout<<(ans+mod)%mod;
}

