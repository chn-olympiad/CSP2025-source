#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,c[15],a[12][N];
struct edge{
	int u,v,w;
	bool operator<(const edge &ano)const{
		return w<ano.w;
	}
}e[M];
ll sum;
int fa[M<<1];
multiset<edge> s;
//priority_queue<edge> q;
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
void solve1(){
	ll ans=0x3f3f3f3f3f3f3f;
	for(int st=0;st<(1<<k);st++){
		int g=0;
		ll now=0;
		int cnt=0;
		init();
		for(int j=0;j<k;j++){
			if((st>>j)&1){
				for(int l=1;l<=n;l++){
					s.insert({n+1+j,l,a[j][l]});
				}
				now+=c[j];
				g++;
			}
		}
		for(auto it:s){
			//cout<<it.u<<" "<<it.v<<" "<<it.w<<"\n";
			int u=it.u;
			int v=it.v;
			ll w=it.w;
			int ru=find(u);
			int rv=find(v);
			if(ru==rv) continue;
			fa[ru]=rv;
			now+=w;
			cnt++;
			if(cnt==n+g-1) break;
		}
		ans=min(ans,now);
		for(int j=0;j<k;j++){
			if((st>>j)&1){
				for(int l=1;l<=n;l++){
					s.erase({n+1+j,l,a[j][l]});
				}
			}
		}
		//cout<<now<<"\n";
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		s.insert({e[i].u,e[i].v,e[i].w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
	}
	if(sum==0) cout<<"0\n";
	else solve1();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 0 0 0 0
0 0 0 0 0
*/