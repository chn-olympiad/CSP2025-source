#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+10,MOD=998244353;
ll n,m,k,ans;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(ll i=1;i<=m;i++){
		ll tmp;
		cin>>tmp;
	}
	if(n==m){
		cout<<1<<"\n";
		return 0;
	}
	for(ll i=m;i<=n;i++){
		ans=(ans%MOD)*(i%MOD)%MOD;
	}
	for(ll i=1;i<=(n-m);i++){
		ans=((ans*MOD)/i)%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
C(2,n)=(!n)/(!2*!(n-2))
*/
