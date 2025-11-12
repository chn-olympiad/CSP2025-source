#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[5005],s[5005];
void dfs(int x,int maxx,int sum){
	if(sum+s[n]-s[x-1]<=2*maxx)return ;
	if(x==n+1){
		if(sum>2*maxx){
			ans++;
		}
		return ;
	}
	dfs(x+1,max(maxx,a[x]),sum+a[x]);
	dfs(x+1,maxx,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	dfs(1,0,0);
	cout<<ans;
}

