#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
const int N=1e4,M=2e6,K=10;
struct node{
	ll w;
	int u,v;
}a[M+5];
int n,m,k;
ll ans;
int cnt;
int c[15],ca[15][N+5],local[15],f[N+5];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void kruskal(){
	sort(a,a+1+cnt,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int x=a[i].u;
		int y=a[i].v;
		int xx=find(x);
		int yy=find(y);
		if(xx==yy) continue;
		cnt++;
		ans+=a[i].w;
		f[xx]=yy;
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&ca[i][j]);
			if(ca[i][j]==0) local[i]=j;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(ca[i][j]==0) continue;
			a[++cnt].w=ca[i][j];
			a[cnt].u=local[i];
			a[cnt].v=j;
		}
	}
	kruskal();
	printf("%lld",ans);
	return 0;
}


