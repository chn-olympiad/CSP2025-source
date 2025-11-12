#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,v,w,id;
};
int n,m,k,ans,cnt;
int vl[15];
int a[15][1005];
node g[10000005];
int l;
bool ki[15];
int f[1005];
int find(int u){
	if(f[u]==u)return u;
	else return f[u]=find(f[u]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	srand(time(NULL));
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	scanf("%lld%lld%lld",&u,&v,&w);
    	l=l+1;
    	g[l].u=u,g[l].v=v,g[l].w=w,g[l].id=0;
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		vl[i]=c;
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				l=l+1;
				g[l].u=j,g[l].v=k,g[l].w=a[i][j]+a[i][k],g[l].id=i;
			}
		}
	}
	sort(g+1,g+1+l,cmp);
	int b=0;
	for(int i=1;i<=n;i++)f[i]=i;
	ki[0]=true;
	for(int i=1;i<=l;i++){
		if(ki[g[i].id]==false&&ki[g[i+1].id]==false){
			if(g[i].w+vl[g[i].id]>g[i+1].w+vl[g[i+1].id])swap(g[i].id,g[i+1].id),swap(g[i].u,g[i+1].u),swap(g[i].v,g[i+1].v),swap(g[i].w,g[i+1].w);
		}else if(ki[g[i].id]==false&&ki[g[i+1].id]==true){
			if(g[i].w+vl[g[i].id]>g[i+1].w)swap(g[i].id,g[i+1].id),swap(g[i].u,g[i+1].u),swap(g[i].v,g[i+1].v),swap(g[i].w,g[i+1].w);
		}
		if(find(g[i].u)!=find(g[i].v)){
			if(rand()%2==0)f[find(g[i].v)]=find(g[i].u);
			else f[find(g[i].u)]=find(g[i].v);
			if(ki[g[i].id]==false)ans+=vl[g[i].id];
			ki[g[i].id]=true;
			ans+=g[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}

