#include<bits\stdc++.h>
#define _for(i,a,b) for(int i=(a);i<=(b);i++)
#define _rof(i,a,b) for(int i=(a);i>=(b);i--)
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){
	int f=1,num=0;
	char c=getchar();
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return f*num;
}
int n,m,k;
int res;
struct e{
	int x,y,v,tp;
	bool operator>(const e& w)const{
		return v>w.v;
	}
};
priority_queue<e,vector<e>,greater<e>> q;
//vector<pair<int,int>> edge[10005];
bool usd[10005];
int c[15],d[15];
int p[15][10005];
int fa[10005];
inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
inline void solve(){
	int cnt=n-1;
	_for(i,1,n) fa[i]=i;
	while(cnt--){
		e x;
		while(1){
			x=q.top(),q.pop();
			if(find(x.x)!=find(x.y) && !usd[x.tp]) break;
		}
		
		fa[find(x.x)]=find(x.y);
//		printf("%lld %lld %lld %lld\n",x.x,x.y,x.v,x.tp);
		res+=x.v;
		
		if(x.tp){
			usd[x.tp]=1;
			_for(i,1,n) if(i!=d[x.tp]){
				q.push({d[x.tp],i,p[x.tp][i],0});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	_for(i,1,m){
		int x=read(),y=read(),v=read();
		q.push({x,y,v,0});
	}
	_for(i,1,k){
		c[i]=read();
		int mn=1e9+10,ind=1;
		_for(j,1,n){
			p[i][j]=read();
			if(p[i][j]<=mn)
				mn=p[i][j],ind=j;
		}
//		printf("%lld\n",ind);
		d[i]=ind;
		_for(j,1,n) if(j!=ind){
			q.push({ind,j,mn+c[i]+p[i][j],i});
		}
	}
	solve();
	printf("%lld\n",res);
	return 0;
}
//i love ccf
