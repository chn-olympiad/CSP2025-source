#include <bits/stdc++.h>
using namespace std;
int n;
int a[5010];
bool vis[5010];
long long ans;
bool check(){
	int cnt=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			cnt+=a[i];
			mx=max(mx,a[i]);
		}
	}
	if(cnt>mx*2)return true;
	else return false;
}
void dfs(int x){
	if(x==n+1){
		if(check())ans=(ans+1)%998244353;
		return ;
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
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
