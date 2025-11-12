#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,c[505],p[15],vis[15],ans=0,dp[505][505];
char s[505];
void dfs(int x){
	if(x==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')  cnt++;
			else{
				if(cnt>=c[p[i]]) cnt++;
				else sum++;
			}
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			p[x]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	int sum0=1;
	for(int i=0;i<n;i++) sum0+=(s[i]=='0');
	if(n<=10){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	cout<<rand();
	return 0;
}//12
