#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int mod=998244353;
int n,m,ans;
char a[510];
int c[510];
int b[510];
bool vis[510];
void dfs(int x){
	if(x==n+1){
		int x=0,sum=0;
		for(int i=1;i<=n;i++){
			if(x>=c[b[i]]){
				x++;
			}else if(a[i]=='0'){
				x++;
			}else{
				sum++;
			}
		}
		if(sum>=m){
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		b[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+1+n);
	dfs(1);
	cout<<ans;
	return 0;
}
