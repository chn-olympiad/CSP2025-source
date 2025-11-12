#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define mkp make_pair
const int inf=2e15,mod=998244353;
int n,m,c[2010];
string s;
int a[2010];
int ans=0,now[201000];
int vis[2010];
void dfs(int dep){
	if(dep==n+1){
		int dea=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0||c[now[i]]<=dea) dea++;
			else {
				sum++;
			}
			//cout<<now[i]<<" ";
		}
		if(sum>=m) ans++;
		//cout<<dea<<"\n";
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		now[dep]=i;
		dfs(dep+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int minn=1;
	for(int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		minn=min(minn,a[i]);
		minn=min(minn,c[i]);
		cin>>c[i];
	}
	if(n<=100){
		dfs(1);
		cout<<ans;
	}else{
		if(minn==0) cout<<0;
		else{
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			}cout<<ans;
		}
	}
	
 	return 0;
}
