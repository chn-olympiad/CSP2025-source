#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,k,ans;
LL pre[10005];
LL find(LL x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
void join(LL x,LL y){
	x=find(x);
	y=find(y);
	pre[x]=y;
	return;
}
LL r[1005][1005];
LL c[1005];
struct edge{
	LL u,v,w;
}a[10000005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				r[i][j]=2e9;
			}
		}
	}
	for(int i=1;i<=n;i++){
		pre[i]=i;
	}
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>c[j];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				r[u][v]=min(r[u][v],c[u]+c[v]);
				r[v][u]=min(r[v][u],c[u]+c[v]);
			}
		}
	}
	if(k!=0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[++m]={i,j,r[i][j]};
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(find(a[i].u)==find(a[i].v))continue;
		join(a[i].u,a[i].v);
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}//uc
