#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int N=10005,E=2000005;
const ll inf=1e16;

int fa[E],c[E],a[11][N];
ll ans;
int n,m,k;

struct M{
	int u,v,w;
};

M e[E];
vector<M> ee,ness;


bool cmp(M x,M y){
	return x.w<y.w;
}

void init(){
	for(int i=0;i<n+k;i++)
		fa[i]=i;
} 

int gett(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=gett(fa[x]);
}

void gete(){
	for(int i=1;i<=m;i++){
		int u=gett(e[i].u),v=gett(e[i].v),w=e[i].w;
		if(u==v)
			continue;
		fa[u]=v;
		ness.push_back(e[i]);
	}
}

int gt(int x,int y){
	return (x>>y)&1;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		e[i]={u,v,w};
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
	init();
	gete();
	ans=inf;
	for(int i=0;i<(1<<k);i++){
		ll res=0;
		for(int j=0;j<k;j++){
			if(gt(i,j)){
				res+=c[j];
				for(int l=0;l<n;l++){
					ee.push_back({n+j,l,a[j][l]});	
				}
			}
				
		}
		for(auto x:ness){
			ee.push_back(x);
		}
		sort(ee.begin(),ee.end(),cmp);
		init();
		for(int i=0;i<ee.size();i++){
			int u=ee[i].u,v=ee[i].v,w=ee[i].w;
			u=gett(u);
			v=gett(v);
			if(u==v)
				continue;
			fa[u]=v;
			res+=w; 
		}
		ans=min(ans,res);
		ee.clear();
	}
	cout<<ans;
	

	return 0;
}



