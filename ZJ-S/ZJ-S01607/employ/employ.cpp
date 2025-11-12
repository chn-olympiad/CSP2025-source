#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
char a[100010];
int b[100010];
bool vis[100010];
int c[100010];
int ans=0;
int mod=998244353;
void dfs(int k){
	if(k==n+1){
		int la=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'||la>=b[c[i]])la++;
		}if(n-la>=m)ans++;
		ans%=mod;
		return;
	}for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			c[k]=i;
			dfs(k+1);
			vis[i]=0;
			c[k]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		cin >>b[i];
	}
	dfs(1);
	cout <<ans%mod;
	return 0;
}
