#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
int n,m,k,flag[15],tot2,vis[505],a[N];
long long ans=0;
string s1[N],s2[N],ss1,s;
void dfs(int u,int tui,int jin){
	if(u>n){
		if(jin>=m){
			ans++;
			ans=ans%998244353;
		}
		return ;
	}
	if(n-tui<m) return ;
	int fg=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(a[i]<=tui){
				dfs(u+1,tui+1,jin);
			}
			else if(s[u-1]=='0') dfs(u+1,tui+1+fg,jin);
			else if(s[u-1]=='1') dfs(u+1,tui+fg,jin+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool fll=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') fll=1;
	}
	if(fll==0){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]>0) ans++;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
