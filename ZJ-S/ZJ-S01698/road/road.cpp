#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
//fast read?
const int B=1<<20;
char buf[B],*p1=buf,*p2=buf;
#define gc (p1==p2 && (p2=(p1=buf)+fread(buf,1,B,stdin)), *p1++)

void read(int &x) {
//	scanf("%d",&x);
	char ch=gc; x=0;
	while(!isdigit(ch)) ch=gc;
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-48,ch=gc;
}
void read(LL &x) {
//	scanf("%d",&x);
	char ch=gc; x=0;
	while(!isdigit(ch)) ch=gc;
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-48ll,ch=gc;
}

const int M=1e6+5,N=1.2e4;
int n,m,k,cnt,fa[N];
LL ans,cost[N],sum[1<<10];

struct xxx{
	int x,y; LL z;
}e[M],g[M];
bool operator <(xxx a,xxx b) {
	return a.z<b.z;
}
int getfa(int x) {
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
vector<xxx>edge[1<<10],hv[10];
void merge(vector<xxx>&flag,const vector<xxx>&a,const vector<xxx>&b) {
	flag.resize(a.size()+b.size());
	int p1=0,p2=0;
	for(int i=0;i<flag.size();i++)
		flag[i]=(p2==b.size()||(p1<a.size()&&a[p1]<b[p2]))?
			a[p1++]:b[p2++];
}
void solve(vector<xxx>&us,LL sum) {
	vector<xxx>nw;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(auto i:us) {
		if(getfa(i.x)!=getfa(i.y)) {
			fa[fa[i.x]]=fa[i.y];
			nw.push_back(i);
			sum+=i.z;
		}
	}
	us=nw; ans=min(ans,sum);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
		read(e[i].x),read(e[i].y),read(e[i].z);
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++) {
		int x=e[i].x,y=e[i].y,w=e[i].z;
		if(getfa(x)!=getfa(y)) {
			edge[0].push_back(e[i]);
			ans+=w,fa[fa[x]]=fa[y];
		}
	}
	for(int i=0;i<k;i++) {
		read(cost[i]);
		for(int j=1;j<=n;j++) {
			LL w; read(w);
			hv[i].push_back({n+1+i,j,w});
		}
		sort(hv[i].begin(),hv[i].end());
	}
	for(int i=1;i<1<<k;i++) {
		int j = __builtin_ctz(i);
		merge(edge[i],edge[i^1<<j],hv[j]);
		solve(edge[i],sum[i]=sum[i^1<<j]+cost[j]);
	}
	printf("%lld",ans);
	
	return 0;
}
/*

*/
