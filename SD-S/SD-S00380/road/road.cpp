#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
int n,m,k,ans=1e18+10;
bool bo[10*N];
struct edge{
	int w,v,s;
};
struct node{
	int c;
	vector<int>w;
}ru[15];
vector<edge>g[N];
struct ufs{
	int num=1,ind;
	bool bo=false;
	ufs* f;
};
typedef ufs* ut;
ut a[N];
ut find(int x){
	ut r=a[x],rr=a[x];
	while(r->f!=r)r=r->f;
	while(rr->f!=rr){
		ut ff=rr->f;
		rr->f=r;
		rr=ff;
	}
	return r;
}
void Union(int x,int y){
	ut rx=find(x),ry=find(y);
	if(rx==ry)return;
	if(rx->num<ry->num)swap(rx,ry);
	rx->num+=ry->num;
	ry->f=rx;
}
bool cmp(edge a,edge b){
	return a.w>b.w;
}
void dfs(int i,int state,int sum,int now,vector<edge> g[]){
	if(state==1){
		for(int j=1;j<=n;j++){
			g[now].push_back((edge){ru[i].w[j],j,now});
			g[j].push_back((edge){ru[i].w[j],now,j});
		}
	}
	if(i>=k){
		int tol=now;
		if(state==1)tol++;
		for(int j=1;j<=tol;j++){
			a[j]=new ufs;
			a[j]->f=a[j];
			a[j]->ind=j;
		}
		vector<edge>ed;
		for(int j=1;j<=tol;j++){
			for(int p=0;p<g[j].size();p++){
				ed.push_back(g[j][p]);
			}
		}
		sort(ed.begin(),ed.end(),cmp);
		for(int j=0;j<ed.size();j++){
			if((find(ed[j].s)!=find(ed[j].v))&&(!a[ed[j].s]->bo || !a[ed[j].v]->bo)){
				a[ed[j].s]->bo=true;
				a[ed[j].v]->bo=true;
				sum+=ed[j].w;
				Union(ed[j].s,ed[j].v);
			}
			if(find(1)->num>=tol)break;
		}
		ans=min(ans,sum);
		return;
	}
	dfs(i+1,0,sum,now,g);
	if(i+1<=k)dfs(i+1,1,sum+ru[i+1].c,now+1,g);
	
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scanf("%lld%lld%lld",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		g[u].push_back((edge){w,v,u});
		g[v].push_back((edge){w,u,v});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&ru[i].c);
		ru[i].w.resize(n+3);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			ru[i].w[j]=w;
		}
	}
	dfs(1,0,0,n,g);
	if(k>0)dfs(1,1,ru[1].c,n+1,g);
	printf("%lld\n",ans);
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
