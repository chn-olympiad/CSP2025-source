#include<bits/stdc++.h>
using namespace std;
#define maxn 10004
long long side[maxn][maxn];
bool vst[maxn*maxn];
long long c[15],v[15][maxn];
struct node {
	int x,y;
	int l,r,f;
} tr[maxn*100];
int num=0;
void up(int x) {
	if(tr[x].f==0)return;
	int u=tr[x].x,v=tr[x].y;
	int fu=tr[tr[x].f].x,fv=tr[tr[x].f].y;
	if(side[u][v]<side[fu][fv]) {
		swap(tr[x].x,tr[tr[x].f].x);
		swap(tr[x].y,tr[tr[x].f].y);
		up(tr[x].f);
	}
}
void down(int x) {
	if(tr[tr[x].l].x==0&&tr[tr[x].r].x==0)return;
	int u=tr[tr[x].l].x,v=tr[tr[x].l].y;
	int fu=tr[tr[x].r].x,fv=tr[tr[x].r].y;
	if(side[u][v]<side[fu][fv]||tr[tr[x].r].x==0) {
		swap(tr[x].x,tr[tr[x].l].x);
		swap(tr[x].y,tr[tr[x].l].y);
		down(tr[x].l);
	}
	if(side[u][v]>side[fu][fv]) {
		swap(tr[x].x,tr[tr[x].r].x);
		swap(tr[x].y,tr[tr[x].r].y);
		down(tr[x].r);
	}
}
void add(int x,int y) {
	for(int i=1; i<=maxn*100; i++) {
		if(tr[i].x==0) {
			tr[i].x=x;
			tr[i].y=y;
			up(i);
			return;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		tr[i].f=i/2;
		tr[i].l=i*2;
		tr[i].r=i*2+1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			side[i][j]=-1;
		}
	}
	for(int i=1; i<=m; i++) {
		long long x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if(side[x][y]!=-1) {
			side[x][y]=min(v,side[x][y]);
			side[y][x]=min(v,side[x][y]);
		} else {
			side[x][y]=v;
			side[y][x]=v;
		}

	}
	for(int i=1; i<=k; i++) {
		scanf("%d" ,&c[i]);
		for(int j=1; j<=n; j++) {
			scanf("%d",&v[i][j]);
		}
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				if(j!=k) {
					if(side[j][k]!=-1) {
						side[j][k]=min(side[j][k],c[i]+v[i][j]+v[i][k]);
						side[k][j]=min(side[k][j],c[i]+v[i][j]+v[i][k]);
					} else {
						side[j][k]=c[i]+v[i][j]+v[i][k];
						side[k][j]=c[i]+v[i][j]+v[i][k];
					}
				}
			}
		}
	}
	int now=1;
	long long ans=0;
	vst[1]=true;
	for(int i=1; i<n; i++) {
		for(int j=1; j<=n; j++) {
			if(side[now][j]!=-1&&!vst[j]) {
				add(now,j);
			}
		}
		while(vst[tr[1].y]) {
			if(tr[1].x==0)break;
			tr[1].x=tr[1].y=0;
			down(1);
		}
		ans+=side[tr[1].x][tr[1].y];
		vst[tr[1].x]=true;
		vst[tr[1].y]=true;
		now=tr[1].y;
		tr[1].x=tr[1].y=0;
		down(1);
	}
	cout<<ans<<endl;
	return 0;
}
