#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int u,nxt;
	int to,value;
}e[300005];
int cnt,fa[100005];
int c,k,n,m;
int mp[10005][10005];
bool cmp(node a,node b){
	return a.value<b.value;
}
void add(int u,int v,int s){
	++cnt;
	e[cnt].u=u;
	e[cnt].to=v;
	e[cnt].value=s;
}
int vc[15],cc[15][10005];
int find(int a){
	if(fa[a]!=a)return fa[a]=find(fa[a]);
	else return fa[a];
}

void kruskal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	int op=0;
	int ans=0;
	int now=1;
	while(op<n-1&&now<=cnt){
		int fu=find(e[now].u),fv=find(e[now].to);
		if(fu!=fv){
			ans+=e[now].value;
			fa[fu]=fv;
//			find(e[now].u);
			op++;
		}
		now++;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)mp[i][j]=-1;
	for(int i=1;i<=m;i++){
		int u,v,value;
		scanf("%lld%lld%lld",&u,&v,&value);
		mp[u][v]=mp[v][u]=value;
	}
/*	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++)printf("%d ",mp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=k;i++){
		scanf("%lld",&vc[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&cc[i][j]);
		}
		for(int j=1;j<=n;j++)
			if(cc[i][j]==0){
				for(int sk=1;sk<=n;sk++)
					if(mp[sk][j]==-1)
						mp[sk][j]=cc[i][sk];
					else mp[sk][j]=min(cc[i][sk],mp[sk][j]);
				for(int sk=1;sk<=n;sk++)
					if(mp[j][sk]==-1)mp[j][sk]=cc[i][sk];
					else mp[j][sk]=min(cc[i][sk],mp[j][sk]);
			}
	}
/*	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++)printf("%d ",mp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=-1)add(i,j,mp[i][j]);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	kruskal();
}
/*
5 8 1
1 2 2
2 3 3
3 4 6
2 5 4
1 4 3
1 5 7
3 5 6
2 4 1
0 1 1 2 0 1*/

