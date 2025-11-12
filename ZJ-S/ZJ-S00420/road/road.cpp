#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,k,u,v,w,newcityw[15],ttt;
struct edge{
	ll u_,v_,w_;
	inline bool operator<(edge a)const{
		return w_<a.w_;
	}
	inline bool operator>(edge a)const{
		return w_>a.w_;
	}
}; 
edge yuan[1000005];
vector<edge>sheng,newroads[15];
ll fa[10505],size[10505];
inline ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline ll merge(ll a,ll b){
	a=find(a);b=find(b);
	if(a==b)return 0;
	if(size[a]>size[b]){
		swap(a,b);
	}
	fa[a]=b;
	size[b]+=size[a];
	return 1;
}
ll ans;ll maxnw; 
inline ll getans(ll x){
	ll nans=0,cnt=0;
	for(register int i=0;i<sheng.size();i++){
		yuan[++cnt]=sheng[i];
	}
	for(register int i=0;i<k;i++){
		if((x>>i)&1){
			nans+=newcityw[i];
			for(int j=0;j<n;j++){
				if(newroads[i][j].w_>=maxnw)break;
				yuan[++cnt]=newroads[i][j];
			}
		}
	}
	for(register int i=1;i<=n+k+5;i++){
		fa[i]=i;
		size[i]=1;
	}
	sort(yuan+1,yuan+1+cnt);
	for(register int i=1;i<=cnt;i++){
		if(merge(yuan[i].u_,yuan[i].v_)){
			nans+=yuan[i].w_;
		}
	}
	return nans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(register int i=1;i<=m;i++){
		cin>>u>>v>>w;
		yuan[i]={u,v,w};
	}
	maxnw=-1;
	for(register int i=0;i<k;i++){
		cin>>newcityw[i];
		for(int j=1;j<=n;j++){
			cin>>ttt;
			newroads[i].push_back({i+1+n,j,ttt});
		}
		sort(newroads[i].begin(),newroads[i].end());
	}
	for(register int i=1;i<=n;i++){
		fa[i]=i;size[i]=1;
	}
	sort(yuan+1,yuan+1+m);
	for(register int i=1;i<=m;i++){
		if(merge(yuan[i].u_,yuan[i].v_)){
			sheng.push_back(yuan[i]);
			maxnw=max(maxnw,yuan[i].w_);
		}
	}
	ans=1145141919810000;
	for(register int i=0;i<(1<<k);i++){
		ans=min(ans,getans(i));
	}
	cout<<ans;
	return 0;
}
//注意到k很小，考虑状压
//可以先求最小生成树，只留下剩下的边 
//O(mlogm+2^k*nk(logn+logk))
//20000000+122400000*16
//若大于原有边，直接不加 
//这个优化是否有点太强了 。。。 
