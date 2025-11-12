#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000];
int main(){
	freopen("employ.in","w",stdin);
	freopen("employ.out","a",stdout);
	
	ll n,m;
	cin>>n>>m;
	
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=1;
	for(ll i=1;i<=m;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0;
} 
