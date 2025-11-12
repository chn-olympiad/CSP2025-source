#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,s[505],c[505],cnt=0,jc=1,a[505],vis[505];
string s1;
void dfs(int u,int cntt){
	int i,j;
	if(u>n){
//		for(i=1;i<=n;i++){
//			printf("%d ",c[a[i]]);
//		}
//		printf("%d",n-cntt);
//		printf("\n");
		cnt+=(n-cntt>=m);
		return;
	}
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[u]=i;
		j=(s[u]&&cntt<c[i]);
		cntt+=(!j);
		dfs(u+1,cntt);
		cntt-=(!j);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i,j;
	bool ss=1;
	cin>>n>>m;
	cin>>s1;
	for(i=0;i<n;i++){
		s[i+1]=s1[i]-'0';
		if(!s[i+1]) ss=0;
	}
	for(i=1;i<=n;i++){
		cin>>c[i];
		jc=jc*i%mod;
	}
	sort(c+1,c+1+n);
	if(m==n){
		for(i=1;i<=n;i++){
			if(s[i]==0||c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	if(ss){
		for(i=1;i<=n;i++){
			if(c[i]<=cnt){
				cnt++;
			}
		}
		if(n-cnt<m){
			cout<<0;
			return 0;
		}
		if(c[i]){
			cout<<jc;
			return 0;
		}
		cout<<jc-n;
		return 0;
	}
	dfs(1,0);
	cout<<cnt;
	return 0;
}
