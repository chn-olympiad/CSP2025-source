#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct edge {
	int u,v,w;
};
vector<edge>e;
vector<pair<int,int> >ee[20];
ll c[20],fa[10050],sum[20];
int n,m,k;
bool cmp(edge a,edge b) {return a.w<b.w;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back(edge{u,v,w});
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			int x;
			cin>>x;
			e.push_back(edge{j,n+i,x+c[i]});
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	ll ans=0;
	for(int i=0;i<e.size();i++) {
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) {
			fa[find(u)]=find(v);
			ans+=w;
			if(v>n) ee[v-n].push_back(make_pair(u,w)),sum[v-n]+=w;
		}
	}
	for(int i=1;i<=k;i++) {
		ll ss=0;
		if(ee[i].size()<=1) {
			ans-=sum[i];
			continue;
		}
		ans-=(ee[i].size()-1)*c[i];
		sum[i]-=(ee[i].size()-1)*c[i];
	}
	cout<<ans<<endl;
	return 0;
}
