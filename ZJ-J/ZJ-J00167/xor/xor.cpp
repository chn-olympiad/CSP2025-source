#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a,nw,f[501000];
map<ll,ll>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		nw^=a;
		f[i]=f[i-1];
		if(mp[nw^k]) f[i]=max(f[i],f[mp[nw^k]-1]+1);
		mp[nw]=i+1;
	}
	cout<<f[n];
	return 0;
}
