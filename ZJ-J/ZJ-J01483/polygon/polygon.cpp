#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+5,mod=998244353;
ll n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int len=3;len<=n;len++){
		ans+=(n-len+1)%mod*(n-len+2)%mod/2;
		ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}
