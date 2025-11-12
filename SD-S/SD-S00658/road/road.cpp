#include<iostream>
#include<algorithm>
#include<cstdio>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define ll long long
using namespace std;

const int MAXN=1e4+10,MAXM=1e6+10,MAXK=15;

struct node{
	int u,v,w;
}e[MAXM],a[MAXK][MAXN],tmp[MAXK][MAXM];

bool cmp(node x,node y){return x.w<y.w;}

ll ans=linf,res;
int c[MAXK],fa[MAXN+MAXK],n,m,k,num;

void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	return;
}

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

void krus(){
	init();ll Res=res;
	for(int i=1;i<=num;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[y]=x;Res+=e[i].w;
	}
	ans=min(ans,Res);
	return;
}

void dfs(int now){
	if(now>k){
		krus();
		return;
	}
	dfs(now+1);
	int Num=num,i=1,j=1;
	for(i=1;i<=num;i++) tmp[now][i]=e[i];
	i=1,j=1,num=0;
	for(;i<=Num&&j<=n;){
		if(tmp[now][i].w<a[now][j].w) e[++num]=tmp[now][i++];
		else e[++num]=a[now][j++];
	}
	while(i<=Num) e[++num]=e[i++];
	while(j<=n) e[++num]=a[now][j++];
	res+=c[now];
	dfs(now+1);
	res-=c[now];
	for(i=1;i<=Num;i++) e[i]=tmp[now][i];num=Num;
	return;
}

int main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].w,a[i][j].u=n+i,a[i][j].v=j;
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	init();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y) continue;
		fa[y]=x;e[++num]=e[i];
	}
	dfs(1);cout<<ans<<endl;
	return 0;
}
