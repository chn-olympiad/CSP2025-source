#include<bits/stdc++.h>
#define N 10000005
#define pb push_back
#define ll long long
using namespace std;
int n,m,a[N],c[N],vis[N];
ll ans;
string s;
const ll M=998244353;
void add(ll &x,int y) {
	if((x+=y)>M) x-=M;
}
void dfs(int x) {
	if(x>n) {
		int he=0,cs=0;
		for(int i=1;i<=n;i++) {
			if(c[a[i]]<=cs) {
				cs++;continue;
			}
			if(s[i-1]=='1') he++;
			else {
				cs++;
			} 
		} if(he>=m) add(ans,1);
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		a[x]=i;vis[i]=1;
		dfs(x+1);vis[i]=0;
	}
}
void solve() {
	cin>>n>>m;cin>>s;bool f=1;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(s[i-1]=='0') f=0;
	}
	if(f) {
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%M;
	} 
	dfs(1);printf("%lld",ans);
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);int t=1;
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	while(t--) {solve();}
	
	return 0;
} 
