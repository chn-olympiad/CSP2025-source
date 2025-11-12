#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N];
bool f[N];
long long ans=0;
void dfs(int u,long long sum,int maxx){
	if(u>n){
		if(sum>2*maxx)ans=(ans+1)%mod;
		return;
	}
	f[u]=false;
	dfs(u+1,sum,maxx);
	f[u]=true;
	dfs(u+1,sum+a[u],max(maxx,a[u]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
