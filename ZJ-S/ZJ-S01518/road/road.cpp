#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u;
	int v;
	int w;
};
vector<edge> e;
int n,m,k,ans,c[501],cnt,cntr[500],minr[500],a[500][50055],fa[50011],x1,x2,x3;
int findfa(int x){
	return (fa[x]==x?x:(fa[x]=findfa(fa[x])));
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x1>>x2>>x3;
		e.push_back({x1,x2,x3});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		minr[i]=1e18;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			minr[i]=min(minr[i],a[i][j]+c[i]);
			e.push_back({j,n+i,a[i][j]+c[i]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=0;i<e.size();i++){
		int fau=findfa(e[i].u),fav=findfa(e[i].v);
		if(fau!=fav){
			fa[fau]=fav;
			ans+=e[i].w;
			if(e[i].v>n)cntr[e[i].v-n]++;
			cnt++;
		}
		if(cnt==n+k-1){
			for(int j=1;j<=k;j++){
				if(cntr[j]==1){
					ans-=minr[j];
				}
				if(cntr[j]>1){
					ans=ans-(cntr[j]-1)*c[j];
				}
			}
			cout<<ans<<"\n";
			break;
		}
	}
	return 0;
}
