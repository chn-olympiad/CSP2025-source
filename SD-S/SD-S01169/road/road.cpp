#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1e6+20;
const long long inf=1e18+7;
long long read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int n,m,k,cnt,f[N],sz[N];
long long ans,c[20],anss,ans1;
struct edg {
	int x,y;
	long long val;
} e[M],nw[20][N],tr[N][20];
bool cmp(edg n1,edg n2) {
	return n1.val<n2.val;
}
int findf(int x) {
	return x==f[x]?x:f[x]=findf(f[x]);
}
int merge(int x,int y) {
	int xx=findf(x),yy=findf(y);
	if(xx!=yy) {
		if(sz[xx]<sz[yy]) f[xx]=yy;
		else if(f[yy]<f[xx]) f[yy]=xx;
		else {
			f[xx]=yy;
			++sz[yy];
		}
		return 1;
	}
	return 0;
}
void dfs(int x) {
	if(x==k+1) {
		ans1=anss;
		for(int i=1;i<=cnt;i++) ans1+=tr[i][k].val;
		ans=min(ans,ans1);
		return;
	}
	for(int i=1;i<=cnt;i++) tr[i][x]=tr[i][x-1];
	dfs(x+1);
	int p=1,q=1,cntt=0;
	tr[cnt+1][x-1].val=inf;
	for(int i=1;i<=n+k;i++) {
		f[i]=i;
		sz[i]=0;
	}
	while(cntt<=cnt) {
		if(tr[p][x-1].val<=nw[x][q].val) {
			if(merge(tr[p][x-1].x,tr[p][x-1].y)) tr[++cntt][x]=tr[p][x-1];
			p++;
		} else {
			if(merge(nw[x][q].x,nw[x][q].y)) tr[++cntt][x]=nw[x][q];
			q++;
		}
	}
	++cnt;
	anss+=c[x];
	dfs(x+1);
	anss-=c[x];
	--cnt;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) {
		e[i].x=read();e[i].y=read();e[i].val=read();
	}
	for(int i=1;i<=k;i++) {
		c[i]=read();
		for(int j=1;j<=n;j++) {
			nw[i][j].val=read();
			nw[i][j].x=i+n;
			nw[i][j].y=j;
		}
		sort(&nw[i][1],&nw[i][n+1],cmp);
		nw[i][n+1].val=inf;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) {
		if(merge(e[i].x,e[i].y)) {
			ans+=e[i].val;
			tr[++cnt][0]=e[i];
			if(cnt>=n-1) break;
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
