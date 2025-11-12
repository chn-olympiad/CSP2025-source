#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int n,k,i,mi,ans,a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;mi=2e9;
	for(i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]);
	if(mi==1) cout<<n/2;
	else{
		for(i=1;i<=n;i++)
			if(a[i]==1) ans++;
		cout<<ans;
	}
	return 0;
}
