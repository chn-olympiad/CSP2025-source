#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>

using namespace std;
const int N = 2e6 ,K=12;
int n,m,k,f[N],sz[N];
ll ans,c[K];
int first[N],idx;
struct edge {
	int u,v;
	ll w;
} ed[N<<1];

vector<edge> E,KE,EE,FE;
bool cmp(edge l,edge r) {
	return l.w<r.w;
}
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
inline void merge(int x,int y) {
	if(sz[x]>sz[y]) f[y]=x,sz[x]+=sz[y];
	else f[x]=y,sz[y]+=sz[x];
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) f[i]=i;
	for(int i=1; i<=m; i++) scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	sort(ed+1,ed+1+m,cmp);
	for(int i=1; i<=m; i++) {
		int u=ed[i].u,v=ed[i].v,fu=find(u),fv=find(v);
		if(fu!=fv) {
			f[fv]=fu;
			ans+=ed[i].w;
			E.push_back(ed[i]);
		}
	}
	sort(E.begin(),E.end(),cmp);
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++) {
			edge t;
			scanf("%d",&t.w);
//			if(t.w==0) cout<<i<<" "<<j<<" "<<endl;
			t.u=n+i,t.v=j;
			KE.push_back(t);
		}
	}
	sort(KE.begin(),KE.end(),cmp);
	for(int i=1; i<(1<<k); i++) {
		for(int j=1; j<=n+k; j++) f[j]=j,sz[j]=1;
		ll fans=0;
		for(int j=0; j<k; j++) if((1<<j)&i) fans+=c[j+1];
		for(auto it:KE)  if((1<<(it.u-n-1))&i) EE.push_back(it);
		int t=0;
		for(int j=0; j<E.size(); j++) {
			while(t<EE.size()&&EE[t].w<E[j].w) FE.push_back(EE[t++]);
			FE.push_back(E[j]);
		}
		for(int j=t; j<EE.size(); j++) FE.push_back(EE[j]);
//		cout<<FE.size()<<endl;
//		for(auto it:FE) printf("*%d %d %d %d\n",it.w,it.u,it.v,fans);//  cout<<it.w<<" "<<it.u<<" "<<it.v<<endl; 
		for(int j=0; j<FE.size(); j++) {
			int u=FE[j].u,v=FE[j].v,fu=find(u),fv=find(v);
			if(fu!=fv) {
				merge(fu,fv);
				fans+=FE[j].w;
			}
		}
		if(fans<ans) ans=fans;
		EE.clear();
		FE.clear();
//		cout<<fans<<endl; 
	}
	cout<<ans;
	return 0;
}
