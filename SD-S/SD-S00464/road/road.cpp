#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,tot,f[100005],cnt1[100005],x[15];
ll ans;
struct node {
	int u,v,w;
} e[5000005];
bool cmp(node x,node y) {
	return x.w<y.w;
}
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot]= {u,v,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>x[i];
		for(int j=1; j<=n; j++) {
			int c;
			cin>>c;
			e[++tot]= {n+i,j,c+x[i]};
		}
	}
	sort(e+1,e+1+tot,cmp);
	int cnt=0,num=0;
	for(int i=1; i<=n+k; i++)f[i]=i;
	for(int i=1; i<=tot; i++) {
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		if(e[i].u||e[i].v)cnt++;
		if((e[i].u>n&&!cnt1[e[i].u])||(e[i].v>n&&!cnt1[e[i].v]))num++;
		cnt1[e[i].u]++;
		cnt1[e[i].v]++;
		ans+=e[i].w;
		if(cnt==n+num-1)break;
	}
	for(int i=n+i; i<=n+k; i++)ans-=(cnt1[i]?(cnt1[i]-1)*x[i-n]:0);
	cout<<ans<<"\n";
	return 0;
}
