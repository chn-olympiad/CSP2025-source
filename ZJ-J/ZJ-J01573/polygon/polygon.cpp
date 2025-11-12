#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5010];
int ans=0;
int n;
int mod=998244353;
void dfs(int k,int tot,int maxx,int ch){
	if(k==n+1){
		if(ch>=3&&maxx*2<tot){
			ans++;
			ans%=mod;
		}return;
	}dfs(k+1,tot+a[k],max(maxx,a[k]),ch+1);
	dfs(k+1,tot,maxx,ch);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}dfs(1,0,0,0);
	cout <<ans%mod;
	return 0;
}
