#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=998244353;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ll ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i+mod)%mod;
	}
	cout<<(ans+mod)%mod<<"\n";
	
	return 0;
}
