#include<bits/stdc++.h>
#define ll long long
const int N=1e6+10;
using namespace std;
ll n,k;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) ans++;
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
