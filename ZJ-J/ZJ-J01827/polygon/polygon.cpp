#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cnt,cnt1;
ll a[10005];

void dfs(ll k,ll ans){
	if(k==n)return;
	for(int i=k+1;i<=n;i++){
		if(ans>a[i]){
			cnt++;
			cnt%=998244353;
		}
		dfs(i,ans+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt1++;
	}
	if(cnt1==n){
		cout<<((n*n-3*n+2)/2)%998244353;
		return 0;
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
		dfs(i,a[i]);
	cout<<cnt;
	return 0;
}
