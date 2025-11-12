#include<bits/stdc++.h>
#define Pline puts("---------------------------")
#define ll long long
#define Spa putchar(' ')
#define Nxt puts("")
#define raed read
namespace FastIO{
	inline int read(int &x){
		x=0;
		char c=getchar();
		while(!isdigit(c))
			c=getchar();
		while(isdigit(c)){
			x=(x<<3)+(x<<1)+(c-'0');
			c=getchar();
		}
		return x;
	}
	inline void write(ll x){
		int top=0;
		int st[25];
		do{
			st[++top]=x%10;
			x/=10;
		}while(x);
		while(top)putchar(st[top--]+'0');
		return ;
	}
	void tomax(int &x,int y){
		if(x<y)x=y;
		return ;
	}
	void tomin(ll &x,ll y){
		if(x>y)x=y;
		return ;
	}
}
using namespace FastIO;
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k;
int c[15],idx[15],now[15],mx[15];
bitset<N>mark[15];
struct Edge{
	int u,v,w;
	Edge(int _u=0,int _v=0,int _w=0){
		u=_u,v=_v,w=_w;
	}
	bool operator <(const Edge &T)const{
		return w<T.w;
	}
}e1[M],e2[15][N];
struct DSU{
	int n;
	int fa[N],siz[N];
	void init(int _n=0){
		n=_n;
		for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	}
	int find(int x){
		if(x==fa[x])return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y)return ;
		if(siz[x]<siz[y])swap(x,y);
		fa[y]=x;
		siz[x]+=siz[y];
	}
}dsu;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;i++)
		read(e1[i].u),read(e1[i].v),read(e1[i].w);
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1,w;j<=n;j++){
			read(w);
			e2[i][j]=Edge(n+i,j,w);
		}
//		mx[i]=n;
		sort(e2[i]+1,e2[i]+n+1);
	}
	sort(e1+1,e1+m+1);
	//首先做一遍最小生成树，边的规模就被缩减为了 n-1 
	dsu.init(n);
	ll ans=0;
	for(int i=1,tmp=0,blo=n;i<=m;i++){
		if(dsu.find(e1[i].u)==dsu.find(e1[i].v))continue;
		ans+=e1[i].w;
		e1[++tmp]=e1[i];
		dsu.merge(e1[i].u,e1[i].v);
		blo--;
		if(blo==1)break;
	}
	m=n-1;
	//然后把每个村庄单独拿出来加入集合做一次最小生成树 
	ll sum;
	for(int i=1,blo,l,r;i<=k;i++){
		l=1,r=1,blo=n+1,sum=0;
		dsu.init(n+k);
		while(blo>1){
			if(r>n||l<n&&e1[l]<e2[i][r]){
				Edge tmp=e1[l++];
				if(dsu.find(tmp.u)==dsu.find(tmp.v))continue;
				mark[i][l-1]=1;
				dsu.merge(tmp.u,tmp.v);
				sum+=tmp.w;
			}else{
				Edge tmp=e2[i][r++];
				if(dsu.find(tmp.u)==dsu.find(tmp.v))continue;
				e2[i][++mx[i]]=tmp;
				dsu.merge(tmp.u,tmp.v);
				sum+=tmp.w;
			}
			blo--;
		}
		tomin(ans,sum+c[i]);
	}
	//然后枚举所有村庄集合 
	for(int st=1,cnt,mi;st<(1<<k);st++){
//		write(st),Nxt;
		sum=0,cnt=0,mi=n;
		mark[0].set();
		for(int i=1;i<=k;i++)
			if(st&(1<<i-1)){
				sum+=c[i];
				idx[++cnt]=i;
				now[cnt]=1;
				mark[0]&=mark[i];
				mi=min(n,mx[i]);
			}
//		Pline;
		if(sum>ans||cnt==1||mi<2)continue;
		now[0]=1,mx[0]=0;
		for(int j=1;j<=m;j++){
			if(!mark[0][j])continue;
			e2[0][++mx[0]]=e1[j];
		}
//		write(mx[0]),
		dsu.init(n+k);
		for(int blo=n+cnt;blo>1;blo--){
			while(1){
				Edge tmp=Edge(0,0,2e9);
				int p=-1;
				for(int i=0;i<=cnt;i++)
					if(now[i]<=mx[idx[i]]&&e2[idx[i]][now[i]]<tmp)
						tmp=e2[idx[i]][now[i]],p=i;
				now[p]++;
				if(dsu.find(tmp.u)==dsu.find(tmp.v))continue;
				sum+=tmp.w;
				dsu.merge(tmp.u,tmp.v);
				break;
			}
			if(sum>=ans)break;
		}
		tomin(ans,sum);
	}
	write(ans);
}
