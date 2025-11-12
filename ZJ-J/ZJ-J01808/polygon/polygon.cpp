#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5;
const int MOD=998244353;
int n,a[N],ans;

void dfs(int u,int fa,int sum,int m){
	if(u>=3&&sum>m*2)ans++;
	for(int i=fa+1;i<=n;i++)
		dfs(u+1,i,sum+a[i],max(m,a[i]));
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)dfs(2,i,a[i],a[i]);
	cout<<ans;
	return 0;
}