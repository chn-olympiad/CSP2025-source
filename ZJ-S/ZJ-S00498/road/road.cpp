#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++(i))
using namespace std;
const int N=1e4+10;
const int M=2e6+10;

ll n,m,k,f[N],t[N],ans,p[20][N];
vector<pair<ll,ll> > g[N];
struct node{
	ll x,y,w;
}e[M];
bool flg=0;

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1,x,y,w;i<=m;++i){
    	cin>>e[i].x>>e[i].y>>e[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>t[i];
		if(t[i]) flg=1;
		for(int j=1;j<=n;++j){
			cin>>p[i][j];
		}
	}
	if(flg==0){
		ans=0;
		for(int i=1;i<=k;++i){
			e[++m].w=t[i];
			e[m].x=n+k+i;
			e[m].y=n+i;
			for(int j=1;j<=n;++j){
				e[++m].w=p[i][j];
				e[m].x=n+i;
				e[m].y=j;
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n+k+k;++i) f[i]=i;
		for(int i=1;i<=m;++i){
			int root1=find(e[i].x),root2=find(e[i].y);
			if(root1==root2) continue;
//			cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].w<<'\n';
			ans+=e[i].w;
			f[root1]=root2;
			g[e[i].x].push_back({e[i].w,e[i].y});
			g[e[i].y].push_back({e[i].w,e[i].x});                          
		}
		for(int i=n+1;i<=n+k;++i){
			if(g[i].size()<=2){
				for(auto [w,y]:g[i]){
					ans-=w;
				}
			}
		}
		cout<<ans<<'\n';
	}
	else{
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
//    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}