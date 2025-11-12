#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;bool vis[5010];
void check(){
	long long cnt=0,sum=0,mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			sum+=a[i];
			mx=max(mx,a[i]);
			cnt++;
		}
	}
	if(cnt>=3&&mx*2<sum){
		ans=(ans+1)%998244353;
	}
}
void dfs(int x){
	if(x==n+1){
		check();	
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}