#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans,i,vis[510],b[510],a[510];
char s[510];
void dfs(int x){
	int i;
	if(x==n+1){
		int cg=0,sb=0;
		for(i=1;i<=x;i++){
			if(s[i]=='1'&&sb<a[b[i]]) cg++;
			else sb++;
		}
		if(cg>=m) ans=(ans+1)%mod;
		return;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		for(i=1;i<=n;i++)
			if(s[i]=='0'||a[i]==0){
				cout<<0;
				return 0;
			}
		ans=1;
		for(i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
}
