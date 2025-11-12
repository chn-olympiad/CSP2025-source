#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=1e4+500;
const int M=1e6+500;
int a[20][N];
struct EdGe{
	int u,v,w;
}ife[M];
bool cmp(EdGe a,EdGe b){
	return a.w<b.w;
}
int c[20];
struct BCJ{
	int f[N];
	void init(int n){
		FOR(i,1,n) f[i]=i;
	}
	int f_find(int x){
		return (f[x]==x ? x : f[x]=f_find(f[x]));
	}
	void f_push(int x,int y){
		int fx=f_find(x),fy=f_find(y);
		f[fx]=fy;
	}
}cb;
int n,m,k;

EdGe nd[M];
EdGe bk[N];
int tot;

ll ans;
int bj[20];

void pan(){
	ll res=0;
	FOR(i,1,k) if(bj[i]) res+=c[i];
	int fz=tot;
	FOR(i,1,k){
		if(!bj[i]) continue;
		FOR(j,1,n){
			nd[++tot].u=i+n;
			nd[tot].v=j;
			nd[tot].w=a[i][j];
		}
	}
	sort(nd+1,nd+tot+1,cmp);
	cb.init(n+k);
	FOR(i,1,tot){
		int u=nd[i].u,v=nd[i].v;
		if(cb.f_find(u)==cb.f_find(v)) continue;
		cb.f_push(u,v);
		res+=nd[i].w;
	}
	tot=fz;
	FOR(i,1,tot) nd[i]=bk[i];
	ans=min(ans,res);
}
void dfs(int x){
	if(x>k){
		pan();//update
		return ;
	}
	bj[x]=1;
	dfs(x+1);
	bj[x]=0;
	dfs(x+1);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//input
	n=iread();
	m=iread();
	k=iread();
	FOR(i,1,m){
		ife[i].u=iread();
		ife[i].v=iread();
		ife[i].w=iread();
	}
	FOR(i,1,k){
		c[i]=iread();
		FOR(j,1,n) a[i][j]=iread();
	}
	
	//kur
	sort(ife+1,ife+m+1,cmp);
	cb.init(n);
	FOR(i,1,m){
		int u=ife[i].u,v=ife[i].v;
		if(cb.f_find(u)==cb.f_find(v)) continue;
		cb.f_push(u,v);
		nd[++tot]=ife[i];
		ans+=ife[i].w;
	}
	
	FOR(i,1,tot) bk[i]=nd[i];
	dfs(1);
	
	//output
	printf("%lld",ans);
	return 0;
}


