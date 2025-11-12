#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+15;
const int mod=998244353;
int t,n,f[N],c[N],m,k,ans,a[N],vis[N];
char s[N];
void dfs(int dep){
	if(dep>n){
		cout<<dep;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){
				cnt++;
				continue;
			}
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
		}
		if(n-cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		a[dep]=i;
		vis[i]=1;
		dfs(dep+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)cin>>c[i];
	if(n<=20){
		dfs(1);
		cout<<ans;	
	}
	else{
		cout<<0;
	}
	return 0;
}
