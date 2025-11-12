#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+15,M=1e6+5,K=2e5+5,inf=1e18;
int n,m,k,len,u,v,w,eu,ev,f,i,j;
int c[20],fa[N],a[20][N];
struct node {
	int u,v,w;
} edge[M],noww[K],pree[N];
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y) {
	return x.w<y.w;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	for(int i=1; i<=n; i++) fa[i]=i;
	int sum=0;
	int minn=inf,num=0;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1; i<=m; i++) {
		if(sum==n-1) break;
		u=edge[i].u,v=edge[i].v,w=edge[i].w;
		eu=find(u),ev=find(v);
		if(eu!=ev) {
			num+=w;
			sum++;
			fa[ev]=eu;
			noww[++len]=edge[i];
			pree[len]=edge[i];
		}
	}
	minn=num;
	for(i=1; i<(1<<(k)); i++) {
		num=0,sum=0;
		int cnt=n;
		len=n-1;
		for(j=1;j<=n-1;j++) noww[j]=pree[j];
		for(j=1; j<=n+k+1; j++) fa[j]=j;
		for(j=1; j<=k; j++) {
			if((i>>(j-1))&1) {
				cnt++;
				num+=c[j];
				for(f=1; f<=n; f++) noww[++len]=(node){f,n+j,a[j][f]};
			}
		}
		sort(noww+1,noww+1+len,cmp);
		for(j=1; j<=len; j++) {
			if(sum==cnt-1) break;
			u=noww[j].u,v=noww[j].v,w=noww[j].w;
			eu=find(u),ev=find(v);
			if(eu!=ev) {
				num+=w;
				sum++;
				fa[eu]=ev;
			}
		}
		minn=min(minn,num);
	}
	cout<<minn;
	return 0;
}