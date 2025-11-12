#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5100],s[5100],cnt,vis[5100],f=1;
const ll N=998244353;
void dfs(ll l,ll sum,ll st,ll mx){
	if(l>n)return;
	if(l>2&&sum>mx*2){
		cnt++;
		cnt%=N;
	}
	for(int i=st;i<=n;i++){
		if(vis[i]==0||l<3&&vis[i]==0){
			vis[i]=1;
			dfs(l+1,sum+a[i],i,max(mx,a[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		ll x=1;
		for(int i=4;i<=n;i++){
			x=x*2+(i-1)*(i-2)/2;
			x%=N;
		}
		cout<<x;
	}
	else{
		dfs(0,0,1,-1);
		cout<<cnt;
	}
	return 0;
}
