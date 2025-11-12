#include<bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=(k);i<=(n);i++)
#define srep(i,n,k) for(int i=(n);i>=(k);--i)
const int N=1e4+5;
struct node{
	int l,r,w;
};
vector<node>e,ne;
int fa[N];
int fin(int n){
	if(fa[n]==n) return n;
	return fa[n]=fin(fa[n]);
}
int n,m,k;
int c[11],a[11][N],tot;
int get_num(){
	rep(i,1,n+k) fa[i]=i;
	sort(ne.begin(),ne.end(),[](node A,node B){
		return A.w<B.w;
	});
	int res=0,ans=0;
	for(auto qwq:ne){
		int l=qwq.l,r=qwq.r,w=qwq.w;
		int x=fin(l),y=fin(r);
		if(x!=y){
			fa[x]=y;
			res++;
			ans+=w;
		}
		if(res==tot-1) return ans;
	}
	return ans;
}
int dis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,n) fa[i]=i;
	rep(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		e.push_back({x,y,z});
	}
	rep(i,1,k){
		cin>>c[i];
		rep(j,1,n) cin>>a[i][j];
	}
	int S=(1<<k)-1;
	memset(dis,0x3f,sizeof dis);
	ne=e;
	dis[0]=get_num();
//	rep(s,0,S){
//		tot=n+1;
//		rep(j,1,k){
//			if((1<<(j-1))&s){
//				rep(q,1,n) ne.push_back({j,q+n,a[j][q]});
//				tot++;
//				continue;
//			}
//			ne=e;
//			rep(q,1,n) ne.push_back({j,q+n,a[j][q]});
//			dis[s|(1<<(j-1))]=min(dis[s|(1<<(j-1))],get_num()+c[j]);
//		}
//	}
//	int ans=1e9;
//	rep(i,0,S) ans=min(ans,dis[i]);
	cout<<dis[0]<<'\n';
	return 0;
}