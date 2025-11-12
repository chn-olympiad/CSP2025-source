#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[100];
struct node{
	int u,v,w;
}e[2000010];
int f[10010];
int h[10010];
bool cmp(node a,node b) {
	return a.w<b.w;
}
int Find(int x) {
	if (f[x]==x) {
		return x;
	}
	return f[x]=Find(f[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		f[i]=i;
	}
	int cnt=m;
	for (int i=1;i<=m;i++) {
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for (int i=1;i<=k;i++) {
		scanf("%lld",&c[i]);
		for (int j=1;j<=n;j++) {
			scanf("%lld",&h[j]);
		}
		for (int j=1;j<=n;j++) {
			for (int g=j+1;g<=n;g++) {
				cnt++;
				e[cnt].u=j;
				e[cnt].v=g;
				e[cnt].w=h[j]+h[g];
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int ans1=0,cnt1=0;
	for (int i=1;i<=cnt;i++) {
		int xx=Find(e[i].u);
		int yy=Find(e[i].v);
		if (xx!=yy) {
			f[xx]=yy;
			cnt1++;
			ans1+=e[i].w;
		}
		if (cnt1==n-1) {
			break;
		}
	}
	cout<<ans1;
	/*for (int i=1;i<=cnt;i++) {
		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	}*/
	return 0;
}
