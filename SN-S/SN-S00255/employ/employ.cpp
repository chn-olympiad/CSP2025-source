//00255 ÕÅº²•N 
#include<bits/stdc++.h>
#define int long long
#define maxn 998244353
using namespace std;
int n,m,k;
signed main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++)ans=(ans*i)%maxn;
	cout<<ans;
	return 0;
}

