#include <bits/stdc++.h>
using namespace std;

#define int long

const int N=505;
int n,m,c[N],vis[N],ans;
string s;

void dfs(int x,int cnt,int dis){
	if(x==n+1){
		ans+=cnt>=m;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			int t=(s[x-1]=='1'&&dis<c[i]);
			dfs(x+1,cnt+t,dis+(t==0));
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

