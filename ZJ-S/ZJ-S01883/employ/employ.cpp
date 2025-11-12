#include<bits/stdc++.h>
using namespace std;

const int N=510;
int c[N],p[N],vis[N];
char s[N];
int n,m,ans;
void dfs(int dep){
	if(dep==n+1){
		int tmp=0,res=0;
		for(int i=1;i<=n;i++){
			if(tmp>=c[p[i]]){
				tmp++;
				continue;
			}
			if(s[i]=='1')res++;
			else tmp++;
		}
		if(res>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
