#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll mod=998244353;
int n,m;
string s;
int c[N];
ll ans;
int p[N],vis[N];
void check(){
	int sum=0,pre=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1'&&pre<c[p[i]])sum++;
		else pre++;
	}
	if(sum>=m)ans=(ans+1)%mod;
}
void dfs(int k){
	if(k==n+1){
		check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		p[k]=i;
		vis[i]=1;
		dfs(k+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
