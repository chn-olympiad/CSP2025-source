#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m,k,fa[10010],jj[1010][1010];
struct node{
	int u,v,w;
}g[1000010];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		g[i].w=1e9;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[i].w=min(g[i].w,w);
		g[i].u=u,g[i].v=v;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	if(k==0){
		int sum=0,cnt=0;
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=m;i++){
			int eu=find(g[i].u),ev=find(g[i].v);
			if(ev==eu){
				continue;
			}
			fa[ev]=eu;
			cnt++;
			sum+=g[i].w;
			if(cnt==n-1){
				break;
			}
		}
		cout<<sum;
	}
	memset(jj,0x3f,sizeof jj);
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			int y;
			scanf("%d",&y);
			jj[x][j]=y;
		}
	}
	for(int j=1;j<=m;j++){
		g[j].w=min(g[j].w,jj[g[j].u][g[j].v]);
		g[j].w=min(g[j].w,jj[g[j].v][g[j].u]);
	}
	ll sum=0,cnt=0;
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=m;i++){
		int eu=find(g[i].u),ev=find(g[i].v);
		if(ev==eu){
			continue;
		}
		fa[ev]=eu;
		cnt++;
		sum+=g[i].w;
		cout<<g[i].w<<' '<<sum<<endl;
		if(cnt==n-1){
			break;
		}
	}
	cout<<sum;
	return 0;
}
