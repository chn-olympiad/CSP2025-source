#include<bits/stdc++.h>
using namespace std;
int n,a[5009];
int ans;
bool vis[5009];
void dfs(int m,int sum,int ma,int now){
	if(m==0){
		if(sum>ma*2) ans++;
		return;
	}
	for(int i=now;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(m-1,sum+a[i],max(a[i],ma),max(now,i));
		vis[i]=0;
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++) dfs(i,0,0,1);
	cout<<ans<<'\n';
	return 0;
}
