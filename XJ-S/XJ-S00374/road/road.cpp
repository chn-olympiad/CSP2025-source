#include<bits/stdc++.h>
#define LL long long

using namespace std; 

struct edge{
	int u,v,w;	
};

const int N=1e4+100,M=2e6+5;
int n,m,k;
edge e[M];
int c[15],a[15][N];
int fa[N];

bool cmp(edge p,edge q){
	return p.w<q.w;
}

int get_fa(int x){
	if(fa[x]==x){
		return x;
	}
	fa[x]=get_fa(fa[x]);
	return fa[x];
}

void merge(int x,int y){
	int gx=get_fa(x);
	int gy=get_fa(y);
	fa[gx]=gy;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]=(edge){u,v,w};
	}
	if(true){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int cnt=0;
		LL ans=0;
		for(int i=1;i<=m;i++){
			int u=e[i].u;
			int v=e[i].v;
			int w=e[i].w;
			if(get_fa(u)==get_fa(v)){
				continue;
			}
			merge(u,v);
			ans+=w;
			cnt++;
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
