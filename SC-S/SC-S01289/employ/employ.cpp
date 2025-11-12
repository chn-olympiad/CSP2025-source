#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define il inline
#define fi first
#define se second
using namespace std;
const int N=20,p=998244353;
int n,m,c[N];
string s;
int vis[N];
int ans=0;
void dfs(int stp,int num){
//	cout<<stp<<" "<<num<<"\n";
	if(n-stp<m-num) return;
	if(stp==n){
		if(num>=m) ans=(ans+1)%p;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int nn=num;
		if(s[stp+1]=='1'&&stp-num<c[i]) nn++;
		dfs(stp+1,nn);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	s=" "+s;
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}