#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,M=2e4+5;
#define int long long
int n,m,k,ans,c[15],f[M],cnt;
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void kruskal(){
	n+=k;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x==y) continue;
		f[x]=y;
		ans+=a[i].w;
		cnt++;
		if(cnt==n-1) return;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			int x;
			scanf("%lld",&x);
			a[++m]=(node){n+i,j,x};
		}
	}
	kruskal();
	printf("%lld",ans);
	return 0;
}
