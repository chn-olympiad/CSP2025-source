#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
long long vis[5005];
void dfs(long long x,long long ax,long long h){
	if(x == n+1){
		if(ax*2<h){
			ans++;
			ans%= 998244353;
		}
		return;
	}
	dfs(x+1,max(ax,a[x]),a[x]+h);
	dfs(x+1,ax,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
