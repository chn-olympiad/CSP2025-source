#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,c[505],vis[505],cnt[505],ans=0;
string s;
void dfs(int x){
	if(x==n){
		int ct=0;
		int zs=0;
		for(int i=1;i<=n;i++){
			if(ct<c[cnt[i]]){
				if(s[i-1]=='1') zs++;
				else ct++;
			}
			else{
				ct++;
			}
		}
		if(zs>=m) ans=(ans+1)%MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			cnt[x+1]=i;
			dfs(x+1);
			cnt[x+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ans;
	return 0;
}
