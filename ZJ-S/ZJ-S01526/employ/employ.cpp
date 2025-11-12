#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5e2+5;
int n,m,ans;
char s[N];
int inv[N];
int a[N];
int vis[N];
void dfs1(int st,int nw,int fq){
	if(nw==m){
		ans=(ans+inv[n-st+1])%mod;
		return;
	}
	if(nw+n-st+1<m)
		return;
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		if(a[i]>fq&&s[st]=='1')	dfs1(st+1,nw+1,fq);
		else	dfs1(st+1,nw,fq+1);
		vis[i]=0;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int r=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1')	r++;
	if(r<m){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	inv[0]=1;
	for(int i=1;i<=n;i++)
		inv[i]=inv[i-1]*i%mod;
	if(n<=18){
		dfs1(1,0,0);
		cout<<ans;
		return 0;
	}
	ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*(a[i]-i+1))%mod;
	}
	cout<<ans;
	return 0;
}
