#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=1e4+5,M=1e6+5;
int n,m,k;
lint ans,res;
int cnt;

lint c[15],dist[15][N];
bool build[15],vis[15];

struct edge{
	int from,to,town;
	lint cost;
}e[M<<1];

line bool cmp(edge a,edge b){
	return a.cost<b.cost;
}

int hcnt;

int fa[N],dep[N];

line int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

line void merge(int a,int b){
	if(dep[a]<dep[b]) swap(a,b);
	fa[a]=b;
	if(dep[a]==dep[b]) dep[b]+=1;
	return ;
}

lint maxl;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		e[i].from=read(),e[i].to=read();
		e[i].cost=read(),e[i].town=0;
		maxl=max(maxl,e[i].cost);
	}
	hcnt=m;
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j) dist[i][j]=read();
		for(int l=1;l<n;++l){
			if(dist[i][l]+c[i]>maxl) continue;
			for(int r=l+1;r<=n;++r){
				e[++hcnt].from=l,e[hcnt].to=r;
				e[hcnt].cost=dist[i][l]+dist[i][r];
				e[hcnt].town=i;
			}
		}
	}
	ans=(lint)(1e18);
	sort(e+1,e+1+hcnt,cmp);
	for(int p=0;p<(1<<k);++p){
		res=cnt=0;
		int pp=p;
		while(pp){
			cnt+=1;
			vis[cnt]=false;
			if(pp&1) build[cnt]=true;
			else build[cnt]=false;
			pp>>=1;
		}
		cnt=0;
		for(int i=1;i<=n;++i) fa[i]=i,dep[i]=1;
		for(int i=1;i<=hcnt;++i){
			if(cnt==n-1) break;
			int u=e[i].from,v=e[i].to;
			int A=find(u),B=find(v);
			if(A==B) continue;
			if(!e[i].town){
				merge(A,B);
				res+=e[i].cost;
				cnt+=1;
			}
			else if(e[i].town and build[e[i].town]){
				merge(A,B);
				res+=e[i].cost;
				cnt+=1;
				if(vis[e[i].town]) continue;
				res+=c[e[i].town];
				vis[e[i].town]=true;
			}
		}
		if(cnt==n-1) ans=min(ans,res);
		
//		cout<<"ans="<<ans<<"\n";
//		cout<<"res="<<res<<" cnt="<<cnt<<" hcnt="<<hcnt<<"\n";
//		cout<<"--------------------\n";
	}
	printf("%lld\n",ans);
	return 0;
}