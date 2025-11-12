#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int cnt,n,m,c[1000010];
bool vis[1000010];
string s;
void dfs(int x,int fq,int lq){
	if(x==n+1){
		if(lq>=m) cnt++,cnt%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(s[x]=='0'||c[i]<=fq){
			vis[i]=1;
			dfs(x+1,fq+1,lq);
			vis[i]=0;
		}
		else if(s[x]=='1'){
			vis[i]=1;
			dfs(x+1,fq,lq+1);
			vis[i]=0;
		}
	}
	return;
}
bool cz(){
	for(int i=1;i<=n;i++) if(s[i]!='1') return 0;
	return 1;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(cz()){
		int ans=1;
		for(int i=n;i>=1;i--) ans*=i,ans%=mod;
		cout<<ans;
	}
	else if(m==n) cout<<0;
	else{
		dfs(1,0,0);
		cout<<cnt;
	}
	return 0;
}