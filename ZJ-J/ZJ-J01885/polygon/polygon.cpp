#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans;
int a[5050];
void dfs(int x,int k,int p,int sum,int g){
	if(x==g){
		if(p>=2&&sum>p) ans=(ans+1)%mod;
		return ;
	}
	dfs(x+1,k+1,p,sum+a[x],g);
	dfs(x+1,k,p,sum,g);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dfs(1,0,a[i],0,i);
	}
	cout<<ans;
	return 0;
}
