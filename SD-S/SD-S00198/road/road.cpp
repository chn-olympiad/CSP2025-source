#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
const int N=1e7+10;
int n,m,k;

struct ss{
	int u,v,w;
}a[N];

int fa[N];

int c[N];
int cs[12][N];

ll ans=1e18;

int u[N],v[N],w[N];

bool cmp(ss g,ss h){
	return g.w<h.w;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>cs[i][j];
		}
	}
	
	int p=1<<k-1;
	
	for(int e=1;e<=p;e++){
		ll sum=0;

		int cm=m;
		
		for(int i=1;i<=m;i++){
			a[i].u=u[i];
			a[i].v=v[i];
			a[i].w=w[i];
		}
		
		for(int j=0;j<=k;j++){
			if((e>>j)&1){
				sum+=c[j+1];
				for(int o=1;o<=n;o++){
					cm++;
					a[cm].u=j+n+1;
					a[cm].v=o;
					a[cm].w=cs[j+1][o];
				}
			}
		}
		
		for(int i=1;i<=n*k;i++){
			fa[i]=i;
		}
		
		sort(a+1,a+1+cm,cmp);
		if(e==2){
			int u=2;
		}
		for(int i=1;i<=cm;i++){
			int x=a[i].u,y=a[i].v;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				fa[fx]=fy;
				sum+=a[i].w;
			}
		}
		
		ans=min(ans,sum);
	}

	cout<<ans;
	
	return 0;
} 
