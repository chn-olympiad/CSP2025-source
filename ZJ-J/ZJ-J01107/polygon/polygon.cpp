#include<bits/stdc++.h>
using namespace std;
const int  mod=998244353;
int n,fns,a[1005];
bool vis[1005];
void dfs(int qd,int sum,int ans,int maxx){
	if(sum>n) return ;
	if(ans>maxx*2){
		fns=(fns+1)%mod;
	}
	for(int i=qd;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			maxx=max(maxx,a[i]);
			dfs(i,sum+1,ans+a[i],maxx);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<fns%mod;
	return 0;
}
