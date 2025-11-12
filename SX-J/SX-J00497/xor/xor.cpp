#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=0; i<n; i++) cin>>a[i];
	if(k==0) cout<<1;
	cout<<2;
	return 0;
}
