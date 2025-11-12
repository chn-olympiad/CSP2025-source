#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
constexpr int N=1e4+20,M=1.1e6+10,K=10+10;using int64=long long;using namespace std;void solve();
int n,m,k,u[M],v[M],w[M],val[K],len[K][N];
struct edge{
	int id,u,v,w;
	friend bool operator<(const edge &lhs,const edge &rhs){return lhs.w<rhs.w;}
}edges[M];int eid[N];
int fa[N];
void init(){forUp(i,1,n+k)fa[i]=i;}
int find(int x){return x==fa[x]?x:find(fa[x]);}
int64 kruskal(bool need,int n,int m){
	int cnt=0;int64 ans=0;init();
	sort(edges+1,edges+m+1);
	forUp(i,1,m){
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		if(find(u)==find(v))continue;
		fa[find(u)]=find(v);++cnt;
		if(need)eid[cnt]=edges[i].id;
		ans+=w;
		if(cnt==n-1)break;
	}
	return ans;
}
int64 ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	forUp(i,1,m){
		cin>>u[i]>>v[i]>>w[i];
		edges[i]={i,u[i],v[i],w[i]};
	}
	forUP(i,0,k){
		cin>>val[i];
		forUp(j,1,n)cin>>len[i][j];
	}
	ans=kruskal(true,n,m);
	forUP(S,1,1<<k){
		int tot=0,num=n;int64 sum=0;
		forUP(i,1,n)edges[++tot]={0,u[eid[i]],v[eid[i]],w[eid[i]]};
		forUP(i,0,k)if(S>>i&1){
			sum+=val[i],++num;
			forUp(j,1,n)edges[++tot]={0,i+n+1,j,len[i][j]};
		}
		ans=min(ans,sum+kruskal(false,num,tot));
	}
	cout<<ans;
	return 0;
}