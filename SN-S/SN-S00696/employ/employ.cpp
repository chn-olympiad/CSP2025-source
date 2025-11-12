#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s;
int a[510];
int f[510];
int vis[510];
int ans;
void dfs(int tot){
	if(tot==n){
		int sum=0,ss=0;
		for(int i=1;i<=n;i++){
			if(sum>=a[f[i]]){
				sum++;
				continue;
			}
			if(s[i-1]=='1'){
				ss++;
			}
			else{
				sum++;
			}
		}
		if(ss>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		f[tot+1]=i;
		dfs(tot+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
