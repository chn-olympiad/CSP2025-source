#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans,mod=998244353;
void dfs(int cnt,int k,int maxn,int l){
	if(k==n+1){
		if(cnt>(maxn*2)&&l>=3){
			ans++;
		}
		return;
	}
	else{
		dfs(cnt+a[k],k+1,max(maxn,a[k]),l+1);
		dfs(cnt,k+1,maxn,l);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0,0);
	cout<<ans<<"\n";
	return 0;
}

