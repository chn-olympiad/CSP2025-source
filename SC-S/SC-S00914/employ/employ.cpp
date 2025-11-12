#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
string s;
int a[N];
int ans;
int vis[N];
int n,m; 
void dfs(int step,int sum){
	if(step==n+1){
		if(n-sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(s[step]=='1'&&sum<a[i]) dfs(step+1,sum);
		else dfs(step+1,sum+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	dfs(1,0);
	cout<<ans;
	return 0;
}