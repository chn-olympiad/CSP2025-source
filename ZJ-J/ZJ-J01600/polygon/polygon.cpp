#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MOD 998244353
using namespace std;
int n,a[5003],sum[5003],maxx[5003];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
		maxx[i] = max(a[i],maxx[i-1]);
	}
	if(sum[n]>maxx[n]*2)cout<<1<<endl;
	else cout<<0<<endl;	
	return 0;
}
