#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20,mod=998244353; 

int n,m,c[N],inv[N];
vector<bool>inp(N,false);
string s;

int dfs(int dep,int cnt){
	if(dep>=n)return (cnt>=m);
	if(cnt>=m){
		return inv[n-dep];
	}
	
	int rt=0;
	for(int i=1;i<=n;i++){
		if(inp[i])continue;
		int fl=dep-cnt;
		inp[i]=true;
		rt+=dfs(dep+1,cnt+(fl<c[i]&&s[dep]=='1'));
		rt%=mod;
		inp[i]=false;
	}
	return rt%mod;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	inv[1]=1;
	for(int i=2;i<N;i++)inv[i]=(inv[i-1]*i)%mod;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	cout<<dfs(0,0);
	return 0;
}
