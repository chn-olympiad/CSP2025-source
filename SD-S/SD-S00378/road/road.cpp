#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000105;

int n,m,k,cnt,c[15],a[15][10005],fa[N];
pair<int,pair<int,int> > d[N];

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[++cnt].first=w;
		d[cnt].second.first=u;
		d[cnt].second.second=v;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			int u=j,v=n+i,w=a[i][j];
			d[++cnt].first=w;
			d[cnt].second.first=u;
			d[cnt].second.second=v;		
		}
	}
	m=cnt;
	for(int i=1;i<=m;i++){
		fa[i]=i;
	}
	ll ans=0;
	sort(d+1,d+m+1);
	for(int i=1;i<=m;i++){
		int x=find(d[i].second.first),y=find(d[i].second.second);
		if(x==y)continue;
		ans+=1LL*d[i].first;
		fa[x]=y;
	}
	printf("%lld",ans);
} 

