//employ
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e2+5;
const int mod=998244353;

string s;
int n,m,d,x,ans;
int fac[N],inv[N],t[N],f[(1<<18)+5][20];

inline int mi(int a,int b=mod-2){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

inline int C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>t[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);++i){
		int c=0;
		for(int j=0;j<n;++j) c+=((i>>j)&1); 
		for(int j=0;j<n;++j){
			if((i>>j)&1) continue;
			for(int k=0;k<=n;++k){
				if(t[j+1]<=k||(s[c]=='0')) (f[i|(1<<j)][k+1]+=f[i][k])%=mod;
				else (f[i|(1<<j)][k]+=f[i][k])%=mod;
			}
		}
	}
	for(int i=m;i<=n;++i){
		(ans+=f[(1<<n)-1][n-i])%=mod;
	}
	cout<<ans;
	return 0;
}
