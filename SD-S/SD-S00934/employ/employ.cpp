#include<iostream>
#include<cstdio>
#define mod 998244353
using namespace std;
using ll=long long;
const int N=505,M=19;
int n,m,s[N],a[N];
ll f[1<<M][M]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){char ch;cin>>ch;s[i]=ch-'0';}
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		ll f=1;
		for(int i=1;i<=n;i++){
			if(!s[i]||!a[i])return cout<<0<<endl,0;
			f=f*i%mod;
		}
		cout<<f<<endl;
		return 0;
	}
	f[0][0]=1;
	for(int S=0;S<(1<<n);S++){
		int t=__builtin_popcount(S)+1; 
		for(int i=0;i<t;i++){
			if(!f[S][i])continue;
			for(int j=0;j<n;j++){
				if((S>>j)&1)continue;
				if(s[t]&&t-i-1<a[j+1])(f[S|(1<<j)][i+1]+=f[S][i])%=mod;
				else (f[S|(1<<j)][i]+=f[S][i])%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++)(ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans<<endl;
	return 0;
}
/*
我太没用了 
baka
*/

