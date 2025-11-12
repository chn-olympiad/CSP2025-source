#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=1e17;
constexpr int mod=998244353;
int n,m;
bool s[505];
int c[505];
int p[505];
bool vis[505];
int ans=0;
void dfs(int x){
	if(x==n+1){
		int num=0;
		for(int i=1;i<=n;i++)
			if((!s[i])||num>=c[p[i]])
				num++;
		if(n-num>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans%mod;
	return 0;
}
