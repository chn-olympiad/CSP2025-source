#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,a[5010];
bool vis[5005];
ll ans;
void bfs(ll Max,ll step,ll sum,ll pos){
	if(step>=3&&step<=n&&sum>2*Max&&pos<=n+1){
		ans++;
		ans%=mod;
	}
	for(int i=pos;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			bfs(max(Max,a[i]),step+1,sum+a[i],i+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bfs(0,0,0,1);
	cout<<ans;
	return 0;
}
