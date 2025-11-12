#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int mod=998244353;

#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FORG(i,u) for(int i=head[u];~i;i=nxt[i])
int c[N],pre[N];
int n,m;
int a[N];
int ans;
void dfs(int now,int pos){
	if(pos>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]>=pre[i])cnt++;
		}
		if(cnt>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if((1<<(i-1))&now)continue;
		a[pos]=i;
		dfs(now|(1<<(i-1)),pos+1);
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	FOR(i,1,n){
		pre[i]=pre[i-1];
		if(s[i]=='1')pre[i]++;
	}
	FOR(i,1,n)cin>>c[i];
	dfs(0,1);
	cout<<ans;
	return 0;
} 
