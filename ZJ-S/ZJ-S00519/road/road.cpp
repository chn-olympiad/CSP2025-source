//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
#define N 2000005
#define M 2005
using namespace std;
int n,m,k;
struct node {
	int u,v,w,f;
} edge[N],Edge[N];
int fa[M];
int tot=0;
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
struct vill{
	int a[M],c,wovop;
}g[15];
bool Cmp(vill x,vill y){
	if(x.c==y.c){
		return x.wovop<y.wovop;
	}
	return x.c<y.c;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v)swap(u,v);
		edge[++tot]=(node)<%u,v,w,0%>;
	}
	for(int i=1; i<=k; i++) {
		cin>>g[i].c;
		for(int j=1; j<=n; j++) {
			cin>>g[i].a[j];
			g[i].wovop+=g[i].a[j];
		}
	}
	for(int i=1; i<=n+k; i++) {
		fa[i]=i;
	}
	int ans=0;
	sort(edge+1,edge+tot+1,cmp);
	for(int i=1; i<=tot; i++) {
		int u=edge[i].u,v=edge[i].v;
		u=find(u);
		v=find(v);
		if(u!=v) {
			fa[u]=v;
			edge[i].f=1;
			ans+=edge[i].w;

		}
	}
	int oto=0;
	//cout<<ans<<"\n";
	sort(g+1,g+k+1,Cmp);
	for(int i=1; i<=tot; i++) {
		if(edge[i].f==1) {
			Edge[++oto]=edge[i];
		}
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n+k; j++) {
			fa[j]=j;
		}

		int sum=0;
		for(int j=1; j<=n; j++) {
			Edge[++oto]=(node)<%n+i,j,g[i].a[j],i%>;
		}
		sort(Edge,Edge+oto+1,cmp);

		for(int _=1; _<=oto; _++) {
			if(Edge[_].f!=i)continue;
			int u=Edge[_].u,v=Edge[_].v;
			u=find(u);
			v=find(v);
			if(u!=v) {
				fa[u]=v;
				Edge[_].f=i+1;
				sum+=Edge[_].w;
			}
		}
		//cout<<sum<<"\n";
		for(int s=1; s<=i; s++) {
			int to=0;sum+=g[s].c;
			for(int _=1; _<=oto; _++) {
				if(Edge[_].u==n+s&&Edge[_].f==1+i) {
					to++;
				}
			}
			//cout<<s<<" "<<to<<" "<<sum<<"\n";
			if(to==0)sum-=g[s].c;
			if(to==1) {
				sum-=g[s].c;
				for(int _=1; _<=oto; _++) {
					if(Edge[_].u==n+s&&Edge[_].f==i+1) {
						Edge[_].f==0;
						sum-=Edge[_].w;
					}
				}
			}
			//cout<<sum<<"\n";
		}
		//cout<<ans<<" "<<sum<<"\n";
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}

