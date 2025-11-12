#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
int mark[N];
int pre[N];
int n,k,ans=0;
void dfs(int dep,int cnt){
	if(dep==n+1){
		ans=max(ans,cnt-1);
		return;
	}
	int pos=-1;
	for(int i=dep;i>mark[cnt-1];i--){
		if((pre[dep]^pre[i-1])==k){
			pos=i;
			mark[cnt]=dep;
			dfs(dep+1,cnt+1);
			break;
		}
	}
	dfs(dep+1,cnt);
	return;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	dfs(1,1);
	cout<<ans;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}