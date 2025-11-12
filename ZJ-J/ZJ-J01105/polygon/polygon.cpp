#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5001];
ll n,ans;
ll C[5001][5001];
const ll mod=998244353;
void init(){
	for(ll i=1;i<=5000;i++){
		for(ll j=1;j<=i;j++){
			if(i==j||j==1)C[i][j]=1;
			else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}
void dfs(ll num,ll maxx,ll sum,ll sitck){
	if(sitck>=3){
		if(maxx*2<sum){
			ans++;
		}
		ans%=mod;
	}
	if(num==n)return;
	for(ll i=num+1;i<=n;i++){
		dfs(i,max(maxx,a[i]),sum+a[i],sitck+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		init();
		for(ll i=3;i<=n;i++){
			ans=ans+(C[n+1][i+1])%mod;
		}
	}
	else{
		dfs(0,INT_MIN,0,0);
	}
	cout<<ans%mod;
	return 0;
}//#Shang4Shan3Ruo6Shui4

