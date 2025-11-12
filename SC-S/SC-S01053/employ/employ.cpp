#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
	}
	ll ans=1;
	for(int i=n;i>=1;i--){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}