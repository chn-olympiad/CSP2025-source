#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int _MAXn=1e4+100;
const int _MAXm=1e6+100;
const int _MAXk=12;

struct Ed{
	ll u,v,w;
	friend bool operator<(Ed a,Ed b){
		if(a.w==b.w){
			if(a.u==b.u)return a.v<b.v;
			return a.u<b.u;
		}
		return a.w<b.w;
	}
};

int n,m,k;
set<Ed> edge;
ll wei[_MAXk];
ll dis[_MAXk][_MAXn];
ll swei=0;

int fat[_MAXn];

void init(){
	for(int i=1;i<=n+k;i++)fat[i]=i;
}

int findfat(int x){
	if(fat[x]==x)return x;
	return fat[x]=findfat(fat[x]);
}

void merge(int x,int y){
	int fx=findfat(x);
	int fy=findfat(y);
	fat[fy]=fx;
}

ll kans=0;
ll Kruskal(){
	init();
	kans=0;
	for(auto i:edge){
		if(findfat(i.u)!=findfat(i.v)){
			merge(i.u,i.v);
			kans+=i.w;
		}
	}
	return kans;
}

ll ans=0x3f3f3f3f3f3f3f3f;
ll excst=0;
void dfs(int id){
	if(id==k+1){
		ll res=Kruskal();
		ans=min(ans,excst+res);
//		printf("Reach %lld+%lld\n",excst,res);
		return;
	}
	if(swei!=0)dfs(id+1);
	for(int i=1;i<=n;i++){
		edge.insert({n+id,i,dis[id][i]});
	}
	excst+=wei[id];
	dfs(id+1);
	excst-=wei[id];
	for(int i=1;i<=n;i++){
		edge.erase({n+id,i,dis[id][i]});
	}
}

ll read(){
	char ch='\0';
	ll ret=0;
	while(!(ch>='0'&&ch<='9')){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret*=10;
		ret+=(ch-'0');
		ch=getchar();
	}
	return ret;
}

int u,v,w;
Ed eds[_MAXm]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%d%d%d",&n,&m,&k);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
//		scanf("%d%d%d",&u,&v,&w);
		eds[i].u=read(),eds[i].v=read(),eds[i].w=read();
	}
	for(int i=1;i<=k;i++){
//		scanf("%lld",&wei[i]);
		wei[i]=read(); 
		swei|=wei[i];
		for(int j=1;j<=n;j++){
//			scanf("%lld",&dis[i][j]);
			dis[i][j]=read();
		}
	}
	for(int i=1;i<=m;i++){
		edge.insert(eds[i]);
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
