#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],b[505],p[505];
bool vis[505];
long long ans,ml[505];
void dfs(int ind,int ptt,int cnt){
	if(cnt==m){
		ans+=ml[n-ind+1];
		ans%=mod;
		return;
	}
	if(ind==n+1) return;
	if(ptt>=b[1]) return;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		p[ind]=i;
		if(a[ind]==0) dfs(ind+1,ptt+1,cnt);
		else if(ptt>=b[i]) dfs(ind+1,ptt+1,cnt);
		else dfs(ind+1,ptt,cnt+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	a[0]=1;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	ml[0]=1;
	for(int i=1;i<=n;i++){
		ml[i]=ml[i-1]*i;
		ml[i]%=mod;
	}
	sort(b+1,b+n+1,greater<int>());
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
