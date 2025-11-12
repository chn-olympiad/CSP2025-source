#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m,cal[maxn],fac[maxn];
char str[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>(str+1);
	for(int i=1;i<=n;i++) cin>>cal[i];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	if(n==m){
		int tag=1;
		for(int i=1;i<=n;i++) tag&=(str[i]=='1');
		for(int i=1;i<=n;i++) tag&=(cal[i]>=1);
		if(tag) cout<<fac[n]<<"\n";
		else cout<<"0\n";
	}
	else cout<<"0\n";
	return 0;
}