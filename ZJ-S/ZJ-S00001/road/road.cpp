#include <bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,m,k;
int u,v,w;
struct node{
	int u,v,w;
	bool operator<(const node&you)const{ return w<you.w;}
}e[N];

int c[15];
int a[15][10005];

int now;
node e0[2*N];
int cnt;

ll ans=1e18;
ll tmp;

int fa[10000+15];
int getfa(int x){ return x==fa[x]?x:fa[x]=getfa(fa[x]);}


void solve(){
	cnt=0;
	tmp=0;
	for(int i=0;i<k;i++) if(now>>i&1){
		tmp+=c[i+1];
		for(int j=1;j<=n;j++) e0[++cnt]={j,n+i+1,a[i+1][j]};
	}
	sort(e0+1,e0+cnt+1);
	for(int i=1;i<=n+k;i++) fa[i]=i;
//	cout<<"BUG  :  "<<cnt<<'\n';
	int j=1;
	for(int i=1;i<=m;i++){
		auto [u,v,w]=e[i];
		while(j<=cnt&&e0[j].w<w){
			auto [u,v,w]=e0[j++];
			int fau=getfa(u),fav=getfa(v);
			if(fau==fav) continue;
			tmp+=w;
			fa[fau]=fav;
		}
		int fau=getfa(u),fav=getfa(v);
		if(fau==fav) continue;
		tmp+=w;
		fa[fau]=fav;
	}
	
	ans=min(ans,tmp);
}
int flag=1;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i]; flag&=c[i]==0;
		for(int j=1;j<=n;j++) cin>>a[i][j],flag&=a[i][j]==0;
	}
	if(flag){//cout<<"HHH\n";
		cout<<0; return 0;
	}
	for(int i=0;i<1<<k;i++) now=i,solve();
	cout<<ans;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//0 0 0 0 0
//0 0 0 0 0
