#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[510];
int vis[510];
string s;
void dfs(int x,int cnt){
	if(x==n){
		if(cnt>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(a[i]>=x&&s[x]=='1') dfs(x+1,cnt+1);
			else dfs(x+1,cnt);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

