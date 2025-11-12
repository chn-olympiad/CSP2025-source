#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e6+10;
int n,m,k;
int c[50],a[50][50010];
struct edge{
	int u,v,w;
}e[N];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int tot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int x=1;x<j;x++){
				e[++tot]={j,x,a[i][j]+a[i][x]};
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fa[fu]!=fa[fv]){
			fa[fu]=fv;
			ans+=w;
			sum++;
		}
		if(sum==n-1) break;
	}
	cout<<ans;
	return 0;
} 
