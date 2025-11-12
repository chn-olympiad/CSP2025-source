#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],ans,vis[500010];
void dfs(int st,long long sum,long long mx,int cnt){
	if(cnt>=3&&sum>mx*2&&vis[st-1]){
		ans++;
//		for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
//		cout<<'\n';
	}
	if(st>n)return;
	vis[st]=1;
	dfs(st+1,sum+a[st],max(mx,a[st]),cnt+1);
	vis[st]=0;
	dfs(st+1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
