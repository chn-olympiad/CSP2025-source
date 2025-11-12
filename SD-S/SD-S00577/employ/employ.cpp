#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,jc=1,ans;
string s;
int c[1000005];
bool f;
int qu[1000005];
bool ch(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'||cnt>=c[qu[i]])cnt++;
		
	}
	
	if(cnt>(n-m))return 0;
	//for(int i=1;i<=n;i++)cout<<qu[i]<<" ";cout<<"\n";
	return 1;
}
bool vis[1000005];
void dfs(int x,int tot){
	if(x==n+1){
		if(ch())ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			qu[x]=i;
			vis[i]=1;
		}
		else continue;
		dfs(x+1,tot+1);
		vis[i]=0;
	}
}
int tot,jcc=1,jjc=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)tot++;
		qu[i]=i;
	}
	if(!f||m==1){
		for(int i=1;i<=n-1;i++)jc=(jc*i)%mod;
		for(int i=1;i<=m;i++)jcc=(jcc*i)%mod;
		for(int i=1;i<=n-1-tot;i++)jjc=(jjc*i)%mod;
		cout<<jcc;
		return 0;
	}
	dfs(1,1);
	cout<<ans%mod;
	return 0;
} 
