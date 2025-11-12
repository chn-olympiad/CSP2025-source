#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=105;
int n,m,ans,p[N],vis[N];
string s;
void dfs(int x,int cnt,int sm){
//	cout<<x<<" "<<cnt<<" "<<sm<<"\n";
	if(x==0&&cnt>=m){
		ans++;
		ans%=mod;
//		for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
//		cout<<"\n";
		return;
	}
	if(cnt+x<m) return;
	for(int i=1;i<=n;i++){
		if(p[i]<=sm) return;
//		cout<<p[i]<<" "<<sm<<"\n";
		if(!vis[i]){
			vis[i]=x;
			if(s[i]=='0')
				dfs(x-1,cnt,sm+1);
			else dfs(x-1,cnt+1,sm);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>p[i];
	sort(p+1,p+n+1);
	dfs(n,0,0);
	cout<<ans<<"\n";
	return 0;
}
/*
3 2
101
1 1 2
*/
