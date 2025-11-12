#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mod=998244353,ans;
int f[505];
int A(int m,int n){
	return f[n]/f[n-m];
}
void init(){
	f[0]=1;
	for(int i=1;i<=501;i++)
		f[i]=(f[i-1]*i%mod);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init(); 
	cin>>n>>m;
	for(int i=m;i<=n;i++)
		(ans+=A(i,n))%=mod;
	cout<<ans;
	return 0;
}

