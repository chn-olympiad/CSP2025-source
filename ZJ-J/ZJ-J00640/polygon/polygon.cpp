#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod= 998244353;
const int maxn=5005;
ll n,a[maxn],ans;
void dfs(ll x,ll suma,ll maxa,ll chooses){
	if(chooses>=3&&maxa*2<suma)
		ans=(ans+1)%mod;
	for(int i=x+1;i<=n;i++)
		dfs(i,suma+a[i],max(maxa,a[i]),chooses+1);
}



void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int T=1;
	while(T--)
		solve();

	return 0;
}

