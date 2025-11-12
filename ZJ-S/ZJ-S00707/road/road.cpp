#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+100,M=1e6+100;
ll read(){
	ll x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
int a,b,k;
struct node{
	int u,v;
	ll w;
}e[M];
struct so{
	int v;
	ll w;
};
vector<so>ve[N];
ll ci[12][N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int f[N];
int find(int x){
	if(x==f[x])return x;
	else return f[x]=find(f[x]);
}
void kruskal(){
	sort(e+1,e+b+1,cmp);
	for(int i=1;i<=a;i++){
		f[i]=i;
	}
	int tot=0;
	int u,v;
	ll w;
	int f1,f2;
	for(int i=1;i<=b;i++){
		u=e[i].u;
		v=e[i].v;
		w=e[i].w;
		f1=find(u),f2=find(v);
		if(f1==f2)continue;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
		f[f1]=f2;
		tot++;
		if(tot==a-1)break;
	}
}
struct ko{
	int id;
	ll minn;
	ll tot;
	ll to[N];
	ll cost;
	vector<int>sp;
	bool yes=false;
}t[12];
struct bian{
	ll w;
	int type=0;
	int cha;
	ll yw;
}fa[N];
void dfs(int x,int fas){
	for(int i=0;i<ve[x].size();i++){
		if(ve[x][i].v==fas)continue;
		fa[ve[x][i].v].w=ve[x][i].w;
		fa[ve[x][i].v].yw=fa[ve[x][i].v].w;
		dfs(ve[x][i].v,x);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	a=read(),b=read(),k=read();
	int u,v,w;
	for(int i=1;i<=b;i++){
		u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	kruskal();
	for(int i=1;i<=k;i++){
		t[i].cost=read();
		ll u=0x3f3f3f3f,fp=-1;
		for(int j=1;j<=a;j++){
			t[i].to[j]=read();
			if(u>t[i].to[j]){
				u=t[i].to[j];
				fp=j;
			}
		}
		t[i].minn=u;
		t[i].id=fp;
	}
	dfs(1,0);
	fa[1].w=-1;
	//for(int T=1;T<=10;T++)
	int type;
	//for(int T=1;T<=10;T++)
	for(int i=1;i<=k;i++){
		ll was=t[i].cost+t[i].minn;
		int id=t[i].id;
		for(int j=2;j<=a;j++){
			if(id==j)continue;
			if(t[i].to[j]<fa[j].w){
				was+=t[i].to[j]-fa[j].w;
			}
		}
		if(was>=0)continue;
		t[i].tot=was;
		for(int j=2;j<=a;j++){
			type=fa[j].type;
			if(id==j)continue;
			if(t[i].to[j]<fa[j].w){
				if(fa[j].type==0){
					fa[j].type=i;
					fa[j].cha=t[i].to[j]-fa[j].w;
					fa[j].w=t[i].to[j];
					t[i].sp.push_back(j);
				}else{
					t[type].tot-=fa[j].cha;
					if(t[type].tot>=0){
						for(int l=0;l<t[type].sp.size();l++){
							if(fa[t[type].sp[l]].type==type){
								fa[t[type].sp[l]].w=fa[t[type].sp[l]].yw;
								fa[t[type].sp[l]].type=0;
							}
						}
						t[type].sp.clear();
						t[type].yes=false;
					}
					fa[j].type=i;
					fa[j].cha=t[i].to[j]-fa[j].w;
					fa[j].w=t[i].to[j];
					t[i].sp.push_back(j);
				}
			}
		}
		t[i].yes=true;
	}
	ll ans=0;
	for(int i=2;i<=a;i++){
		ans+=fa[i].w;
	}
	for(int j=1;j<=k;j++){
		if(t[j].yes)ans+=t[j].minn+t[j].cost;
	}
	cout<<ans;
	
	return 0;
}