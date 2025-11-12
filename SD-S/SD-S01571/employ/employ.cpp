#include<bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=(l); i<=(r); ++i)
using namespace std;
const int N=1e6+50,INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;

int n,m,ans;
int c[N];
bool t[N],vis[N];

void DFS(int p,int pat){
//	cout<<p<<' '<<pat<<'\n';
	if(p>n) return (ans+=(n-pat>=m))%=mod, void();
	F(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;
		DFS(p+1,pat+(pat>=c[i] || t[p]==0));
		vis[i]=0;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	string s; cin>>s;
	F(i,0,n-1) t[i+1]=s[i]-'0';
	F(i,1,n) cin>>c[i];
	DFS(1,0);
	cout<<ans<<'\n';
	
	return 0;
}
