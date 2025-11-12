#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define p(i,j) make_pair(i,j)
using namespace std;
const int N=1e4+10;
ll n,m,x,y,z,sum,ans,tmp,cnt,now,u,v,l,r,k,T,a[N][12],w,f[N],tot,qans;
struct node{
	int u,v;
	ll w;
};
vector<node> e1,e;
map<pii,ll> mp;
int cmp(node a,node b){
	return a.w<b.w; 
}
int find(int x){
	return f[x]==x? x:f[x]=find(f[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		f[fx]=fy;
		++cnt;
	}
}
ll kus(){
	cnt=ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<e.size();i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy){
			f[fy]=fx;
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1) break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e1.push_back({u,v,w});
//		mp[p(min(u,v),max(u,v))]=w+1;
		++tot;
	}
	for(int i=1;i<=k;i++){
		cin>>a[0][i];
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
//			if(mp[p(min(i,j),max(i,j))]!=0) mp[p(min(i,j),max(i,j))]=min(mp[p(min(i,j),max(i,j))],x+y);
//			e.push_back({i,j,x+y});
//			++tot;
		}
	}
//	for(auto x:mp) e.push_back({x.first.first,x.first.second,x.second}),++tot;
	e=e1;
	if(k==0){
		cout<<kus();
	}else{
		for(int sta=0;sta<(1<<k);sta++){
			for(auto x:e1){
				u=x.u,v=x.v,w=x.w;
				if((u<=k&&(sta&(1<<u-1)))||(v<=sta&&(sta&(1<<v-1)))){//如果是城市化改造后的 
					ll tmp=2e9;
					if(u<=k) tmp=min(tmp,a[u][v]);
					if(v<=k) tmp=min(tmp,a[v][u]);
					e.push_back({u,v,tmp});
				}else e.push_back(x);
			}
			qans=min(qans,kus()); 
		}
		cout<<qans;
	}
	return 0;
}

