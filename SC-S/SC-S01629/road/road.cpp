#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+100;
int n,m,k,ans;
int fa[N];
int a[N];
inline int find_(int x){ return x==fa[x]?x:fa[x]=find_(fa[x]); }
struct kru{
	int u,v,w;
}kr[N*2];
int tot;
inline bool cmp(kru x,kru y){ return x.w<y.w; }

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+1;i++)  fa[i]=i;
	for(int u,v,w,i=1;i<=m;i++){
		cin>>u>>v>>w;
		kr[++tot].u=u,kr[tot].v=v,kr[tot].w=w;
		kr[++tot].u=v,kr[tot].v=u,kr[tot].w=w;
	}
	for(int c,i=1;i<=k;i++){
		cin>>c;  bool f;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]) f=1;
		}
//		if(!c&&!f)  continue;
		for(int j=1;j<=n;j++)
			for(int q=1;q<j;q++){
				if(q==j)  continue;
//				cerr<<"u="<<j<<" v="<<q<<' ';
				kr[++tot].u=j,kr[tot].v=q,kr[tot].w=a[j]+c+a[q];
				kr[++tot].u=q,kr[tot].v=j,kr[tot].w=a[q]+c+a[j];
//				cerr<<"w="<<kr[tot].w<<'\n';
//				cerr<<"a[u]="<<a[j]<<" a[v]="<<a[q]<<'\n';
			}
	}
	sort(kr+1,kr+1+tot,cmp);
	int p=0;
	for(int i=1;i<=tot;i++){
		int x=kr[i].u,y=kr[i].v,w=kr[i].w;
		int fx=find_(x),fy=find_(y);
		if(fx==fy)  continue;
		ans+=w; p++;
		fa[fx]=fy;
		if(p==n-1)  break;
	}
	cout<<ans<<'\n';
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
*/