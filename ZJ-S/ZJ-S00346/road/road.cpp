#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
#define ri register int
#define mp make_pair
#define pb push_back
using namespace std;
namespace IO{
	#define gh() getchar()
	inline int r(){
		int a=1,b=0;
		char c=gh();
		while(c>'9'||c<'0'){if(c=='-')a=-1,c=gh();}
		while(c<='9'&&c>='0'){b=(b<<1)+(b<<3)+(c^48);c=gh();}
		return a*b;
	}
	inline char gc(){char ch=gh();while(ch<=' ')ch=gh();return ch;}
	inline string gs(){char ch=gh();string S="";while(ch<=' ')ch=gh();while(ch>' '){S+=ch;ch=gh();}return S;}
	inline void wr(int x){
		if(x==0)return;if(x<0){x=-x;putchar('-');}
		wr(x/10);putchar((x%10)^48);
	}
	inline void ww(int x){if(x==0)putchar('0');else wr(x);putchar(' ');}
	inline void wln(int x){if(x==0)putchar('0');else wr(x);putchar('\n');}
	inline void w(int x){if(x==0)putchar('0');else wr(x);}
}
using namespace IO;
const int N=1e4+20,M=1e6+7;
namespace D1n0{
	bool St;
	int n,m,k,fa[N],val[12][N],c[12];
	inline int getfa(int x){
		if(fa[x]==x)return x;
		return fa[x]=getfa(fa[x]);
	}
	struct e{
		int u,v,w;
	}e1[M],e2[M],ee[1025][N];
	bool En;
	bool operator<(e _,e __){
		return _.w<__.w;
	}
	inline void Zyt(){
		n=r();m=r();k=r();
		for(ri i=1;i<=m;++i){
			e1[i].u=r();e1[i].v=r();e1[i].w=r();
		}
		for(ri i=1;i<=k;++i){
			c[i]=r();
			for(ri j=1;j<=n;++j)val[i][j]=r();
		}
		sort(e1+1,e1+1+m);
		for(ri i=1;i<=n;++i)fa[i]=i;
		int ans=1e18,sum=0,cnt=0;
		for(ri i=1;i<=m;++i){
			int x=getfa(e1[i].u),y=getfa(e1[i].v);
			if(x!=y){
				fa[x]=y;
				sum+=e1[i].w;
				ee[0][++cnt]=e1[i];
			}
		}
		ans=sum;
		for(ri i=1;i<(1<<k);++i){
			m=0;cnt=0;
			int cost=0;
			for(ri j=1,f=1;j<=k;++j)if((i>>j-1)&1){
				cost+=c[j];
				if(f)for(ri k=1;k<=n;++k)e2[++m]=(e){j+n,k,val[j][k]};
				f=0;
			}
			int lst=i-(i&(-i));
			int siz=n+__builtin_popcount(lst)-1;
			for(ri j=1;j<=siz;++j)e2[++m]=ee[lst][j];
			sort(e2+1,e2+1+m);
			sum=0;
			for(ri j=1;j<=n+k;++j)fa[j]=j;
			for(ri j=1;j<=m;++j){
				int x=getfa(e2[j].u),y=getfa(e2[j].v);
				if(x!=y){
					fa[x]=y;
					sum+=e2[j].w;
					ee[i][++cnt]=e2[j];
				}
			}
			ans=min(ans,sum+cost);
		}
		w(ans);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	D1n0::Zyt();
}
