#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}
	return x*y;
}
void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
const ll N=1e4+10,M=3e6+10,K=15;
ll n,m,k;
struct Edge{ll u,v,w,nxt;}e[M];
ll head[N],cnt;
inline void _add(ll u,ll v,ll w){
	e[++cnt]=(Edge){u,v,w,head[u]};
	head[u]=cnt;
}
inline void add(ll u,ll v,ll w){
	_add(u,v,w);
	_add(v,u,w);
}

struct Node{
	ll ind,dis;
	Node(){
	}
	Node(ll a,ll b){
		ind=a,dis=b;
	}
	bool operator <(Node x)const{
		return dis>x.dis;
	}
};
ll diss[N];
bool vis[N];

//bool constructed[K];
//ll a[K][N];
//inline ll Fnd(ll u,ll v){
//	ll mn=1145141919810233;
//	for(ll i=1;i<=k;i++){
//		if(constructed[i]){
//			mn=(a[i][u])
//		}
//	}
//}
ll Prim(){
	priority_queue<Node>q;
	memset(diss,0x1f,sizeof diss);
	memset(vis,0,sizeof vis);
	diss[1]=0;
	q.push(Node(1,0));
	ll Ans=0;
	while(q.size()){
		Node t=q.top();q.pop();
		ll u=t.ind;
		if(vis[u]) continue;
		vis[u]=1;Ans+=t.dis;
		for(ll i=head[u];i;i=e[i].nxt){
			ll v=e[i].v,w=e[i].w;
			
			if(w<diss[v])
				q.push(Node(v,diss[v]=w));
		}
	}
	return Ans;
}
ll kkk[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=readl(),m=readl(),k=readl();
	for(ll i=1;i<=m;i++){
		ll u=readl(),v=readl(),w=readl();
		add(u,v,w);
	}
	if(k==0){
//		ll tm=clock();
		writel(Prim());
//		cerr<<clock()-tm;
		return 0;
	}else{
		ll sss=0;
		for(ll i=1;i<=k;i++){
			ll x=readl();ll t=1;sss+=x;
			for(ll j=1;j<=n;j++){
				kkk[j]=readl();
				if(kkk[t]>kkk[j]) t=j;
			}
			sss+=kkk[t];
			for(ll j=1;j<=n;j++)
				if(j!=t)add(t,j,kkk[j]);
		}
		writel(Prim()+sss);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
