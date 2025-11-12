#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define fi first
#define se second
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(z);x>=(y);x--)
#define eb emplace_back
#define emp emplace
#define pob pop_back
#define tomx(x,y) x=max(x,y)
#define tomn(x,y) x=min(x,y)
#define pof pop_front
#define ull unsigned long long
#define beg begin
#define all(x) beg(x),end(x)
#define allt(x,y,z) beg(x)+y,beg(x)+z
using namespace std;
int n,m,k;
#define N 1'003'4
#define M 1'00000'6
/*
考虑对于一个图和一个边集的划分
整个图的MST边集一定包含于二者中MST的并集。
O(2^k*n*a(n))
每个状态有用的边只有O(n)条 
*/
int cnt[N],ye[N],ans,fa[N],U[M],V[M],W[M],ynt;
int c[12];
int a[12][N];
int find(int u){
	if(u==fa[u]) return u;
	return fa[u]=find(fa[u]);
}
bool merge(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v) return 0;
	if(cnt[u]>cnt[v]) swap(u,v);
	fa[u]=v;
	cnt[v]+=cnt[u];
	return 1;
}
void cle(){
	rep(i,1,n+k+1) fa[i]=i;
	rep(i,1,n+k+1) cnt[i]=1;
}
int cy,ct;
struct node{
	signed u,v;
	int w;
	node(signed _u=0,signed _v=0,int _w=0){
		u=_u;
		v=_v;
		w=_w;
	}
};
node te[1028][N],pe[13][N];
signed main(){
//	cerr<<"mem: "<<((sizeof(cnt)*15)+(sizeof U)*3+sizeof(te)+sizeof(pe))/1048576.<<"\n";
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	vi ee;
	rep(i,1,m){
		cin>>U[i]>>V[i]>>W[i];
		ee.eb(i);
	}
	sort(all(ee),[&](int x,int y){
		return W[x]<W[y];
	});
	cle();
	for(auto i:ee){
		int u,v,w;
		u=U[i];v=V[i];w=W[i];
		if(merge(u,v)){
			ye[++ynt]=i;
			ans+=w;
		}
	}
	cle();
	int al=(1<<k)-1;
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n) cin>>a[i][j];
		rep(j,1,n) pe[i][j]=node(n+i,j,a[i][j]);
		sort(allt(pe[i],1,n+1),[&](node x,node y){
			return x.w<y.w;	
		});
	}
	rep(S,1,al){
		int lb=0;
		rep(i,1,k) if((S>>(i-1))&1) lb=i;
		int T=S-(1<<(lb-1));
		if(T==0){
			cle();
			vector<node> e;
			rep(i,1,n){
				int t=ye[i];
				e.eb(U[t],V[t],W[t]);
			}
			rep(i,1,n) e.eb(pe[lb][i]);
			sort(all(e),[&](node x,node y){
				return x.w<y.w;	
			});
			int d=0;
			int res=c[lb];
			for(node&p:e){
				int u=p.u,v=p.v,w=p.w;
				if(merge(u,v)){
					res+=w;
					te[S][++d]=p;
				}
			}
			tomn(ans,res);
		}
		else{
			cle();
			int d1=1,d2=1,res=0,d=0;
			rep(i,1,k) if((S>>(i-1))&1) res+=c[i];
			for(;te[T][d1].u&&pe[lb][d2].u;){
				if(te[T][d1].w<pe[lb][d2].w){
					if(merge(te[T][d1].u,te[T][d1].v)){
						res+=te[T][d1].w;
						te[S][++d]=te[T][d1];
					}
					d1++;
				}else{
					if(merge(pe[lb][d2].u,pe[lb][d2].v)){
						res+=pe[lb][d2].w;
						te[S][++d]=pe[lb][d2];
					}
					d2++;
				}
			}
			for(;te[T][d1].u;){
				if(merge(te[T][d1].u,te[T][d1].v)){
					res+=te[T][d1].w;
					te[S][++d]=te[T][d1];
				}
				d1++;
			}
			for(;pe[lb][d2].u;){
				if(merge(pe[lb][d2].u,pe[lb][d2].v)){
					res+=pe[lb][d2].w;
					te[S][++d]=pe[lb][d2];
				}
				d2++;
			}
//			int f=find(1);
//			rep(i,1,n) assert(find(i)==f); 
			tomn(ans,res);
		}
	}
	cout<<ans;
}

