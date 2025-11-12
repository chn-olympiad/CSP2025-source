#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,cnt;
ll a[5005],c[5005];
void dfs(ll t){
	if(t==n+1){
		ll x=0,y=0,t1=0;
		for(ll i=1;i<=n;i++){
			if(c[i]==1){
				t1++;
				x+=a[i];
				y=max(y,a[i]);
			}
		}
		if(t1>=3&&x>y*2){
			cnt++;
		}
		return ;
	}
	c[t]=1;
	dfs(t+1);
	c[t]=0;
	dfs(t+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1);
	cout<<cnt;
	return 0;
}

