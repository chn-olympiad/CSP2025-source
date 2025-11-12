#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x){x=0;ll f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}x*=f;}
template <typename T,typename ...Args>
void read(T &x,Args &...args){read(x);read(args...);}
template <typename T>
void write(T x){if(x<0){x=-x;putchar('-');}if(x>9)write(x/10);putchar(x%10+48);}
template <typename T,typename ...Args>
void write(T x,Args ...args){write(x);if(sizeof...(args)){putchar(' ');write(args...);}}
const ll N=1e4+5,M=1e6+5,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,k;
struct edge{
	ll u,v,w;
	ll c;
	friend bool operator < (edge a,edge b){
		return a.w>b.w;
	} 
}a[M<<2];
ll fa[N],c[15];
bitset<N> vis;
ll to[15][N];
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
ll aha[15];
ll opp[N];
priority_queue<edge> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,k);
	memset(opp,0x3f,sizeof opp);
	for(int i=1;i<=n;i++)fa[i]=i;
	vis=0;
	ll cnt=n-1;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		read(u,v,w);
		a[i]={u,v,w,0};
		q.push(a[i]);
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		ll mi=inf;
		for(int j=1;j<=n;j++){
			read(to[i][j]);
			if(to[i][j]<mi)mi=to[i][j],aha[i]=j;
			
		}
		for(int j=1;j<=n;j++)q.push({aha[i],j,c[i]+to[i][j]+to[i][aha[i]],i});
	}
	ll ans=0;
	while(!q.empty()){
		if(!cnt)break;
		edge p=q.top();
		q.pop();
		if(find(p.u)==find(p.v)){
//			cerr<<"--\n";
			continue;
		}
		if(p.c){
			if(vis[p.c])continue;
//			cerr<<"-------------------------buy "<<" +"<<c[p.c]<<'\n';
			vis[p.c]=1;
			for(int i=1;i<=n;i++){
				q.push({aha[p.c],i,to[p.c][i],0});
				if(opp[i]<0x3f3f3f3f3f3f3f3f&&opp[i]>to[p.c][i]){
					cerr<<"=="<<i;
					ans+=to[p.c][i]-opp[i];
					opp[i]=to[p.c][i];
				}
			}
			if(aha[p.c]!=p.v){
				ans+=to[p.c][p.v];
				cnt--;
			}
			ans+=c[p.c];
			ans+=to[p.c][aha[p.c]];
//			cerr<<cnt<<':'<<p.u<<' '<<p.v<<"(+"<<to[p.c][aha[p.c]]+to[p.c][p.v]<<")"<<'\n';
			fa[find(aha[p.c])]=p.v;
			continue;
		}
//		cerr<<cnt<<':'<<p.u<<' '<<p.v<<"(+"<<p.w<<")"<<'\n';
		cnt--;
		fa[find(p.u)]=p.v;
		opp[p.u]=min(opp[p.u],p.w);
		opp[p.v]=min(opp[p.v],p.w);
		ans+=p.w;
	}
	write(ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


4 3 1
1 2 999
1 3 1
3 4 10
10 1 1 9999 9
*/

