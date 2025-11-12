#include<bits/stdc++.h>
using namespace std;
const int N=600,mod=998244353;
int n,m,c[N];
string s;
int p[N],ans=0;
bool vis[N];
inline void dfs(int now){
	if(now>n){
		int num=0,fal=0;
		for(int j=1;j<=n;j++){
			int i=p[j];
			if(fal>=c[i]){
				fal++;
				continue;
			}
			if(s[j]=='0') fal++;
			else num++;
		}
		if(num>=m){
			ans++;
			//for(int i=1;i<=n;i++) cout<<p[i]<<' ';
			//cout<<'\n';
		} 
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[now]=i;
		vis[i]=1;
		dfs(now+1);
		vis[i]=0;
	}
}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}