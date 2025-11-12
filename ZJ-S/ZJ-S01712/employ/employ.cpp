#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[505];
int n,m,tot,ans;
string s;
int mod=998244353;
int c[505];
int a[505];
void dfs(int step){
	if(step==n+1){
		int k,sum;
		k=0;
		sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') k++;
			else if(s[i-1]=='1'&&a[i]<=k) k++;
			else sum++;
		}
		if(sum>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[step]=c[i];
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1') tot++;
	}
	if(tot<m){
		cout<<"0";
		return 0;
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}

