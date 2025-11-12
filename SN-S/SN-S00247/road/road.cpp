#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=50015,maxm=2000005;

ll c[15],ansf=0x3f3f3f3f3f3f3f3f,b[maxm][4],h[15][maxn],ans[2000];
int fa[maxn],n,m,k,tot,cnt[15],flag1[15];

int get_f(int x){

	if(fa[x]==x) return x;
	else{
		int y=get_f(fa[x]);
		fa[x]=y;
		return fa[x];
	}
}

struct node{
	int u,v,pos,t;
	ll cast;
	bool operator <(const node &x)const{
		return cast>x.cast;
	}
}g[maxm];

priority_queue <node >q;

void Init(){
	for(int i=1;i<=m;i++) cin>>b[i][1]>>b[i][2]>>b[i][3];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>h[i][j];
	}
}

void solve1(){
	for(int i=1;i<=m;i++){
		ll x,y,z; x=b[i][1],y=b[i][2],z=b[i][3];
		g[++tot].cast=z; g[tot].pos=0;
		g[tot].u=x,g[tot].v=y;
		q.push(g[tot]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int x=h[i][j];
			g[++tot].cast=x; g[tot].u=n+i,g[tot].v=j; g[tot].pos=i;
			q.push(g[tot]);
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	while(!q.empty()){
		node x=q.top();
		q.pop();
		if(get_f(x.u)==get_f(x.v)) continue;
		cnt[x.pos]++;
		fa[get_f(x.u)]=x.v;
		ansf+=x.cast;
	}
	cout<<ansf<<endl;
}

void preper(){
	tot=0;
	while(!q.empty()) q.pop();
	for(int i=1;i<=n+k+5;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		ll x,y,z; x=b[i][1],y=b[i][2],z=b[i][3];
		g[++tot].cast=z; g[tot].pos=0;
		g[tot].u=x,g[tot].v=y; g[tot].t=(1<<(k))-1;
		q.push(g[tot]);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			int x=h[i][j];
			g[++tot].cast=x; g[tot].u=n+i,g[tot].v=j;
			g[tot].pos=i; g[tot].t=(1<<(i-1));
			q.push(g[tot]);
		}
	}
}

void solve2(){
	for(int i=0;i<(1<<(k));i++){
		preper();
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))) ans[i]+=c[j];
		}
		while(!q.empty()){
			node x=q.top();
			q.pop();
			if((x.t&i)==0&&x.t!=((1<<k)-1)) continue;
			if(get_f(x.u)==get_f(x.v)) continue;
			fa[get_f(x.u)]=get_f(x.v);
			ans[i]+=x.cast;
		}
	}
	for(int i=0;i<(1<<k);i++) ansf=min(ansf,ans[i]);
	cout<<ansf;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k; int flag=0;
	Init();
	for(int i=1;i<=k;i++) if(c[i]) flag=1;
	if (!flag) solve1();
	else solve2();
}
