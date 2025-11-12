#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nm,k,ans,s;
ll a[15][10005],c[15],fa[1000005],rd[200005],dis[200005];
struct node{
	ll u,v,w;
}t[1000005];
struct Node{
	ll v,w;
	bool operator <(const Node &ss)const {
		return ss.w<w;
	}
};
struct NOde{
	ll v,w,tv,tw;
	bool operator <(const NOde &ss)const {
		return ss.w<w;
	}
};
vector<Node>g[200005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}return fa[x]=find(fa[x]);
}
void dij(){
	priority_queue<Node>q;
	q.push({s,0});
	while(q.size()){
		Node p=q.top();
		q.pop();
		for(auto t:g[p.v]){
			if(dis[t.v]>dis[p.v]+t.w){
				dis[t.v]=dis[p.v]+t.w;
				q.push({t.v,dis[t.w]});
			}
		}
	}
}void dij2(){
	priority_queue<NOde>q;
	q.push({s,0,0,0});
	while(q.size()){
		NOde p=q.top();
		q.pop();
		for(auto ti:g[p.v]){
			if(dis[ti.v]>dis[p.v]+ti.w){
				dis[ti.v]=dis[p.v]+ti.w;
				if(ti.v<=n&&p.v>n){
					t[++m].u=p.tv;
					t[m].v=ti.v;
					t[m].w=p.tw+ti.w+c[p.v-n];
					q.push({ti.v,dis[ti.w],0,0});
				}else if(ti.v>n&&p.v<=n){
					q.push({ti.v,dis[ti.w],p.v,ti.w});
				}
			}
		}
	}
}
int main(){   
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);  
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t[i].u=u;
		t[i].v=v;
		t[i].w=w;
	}
	nm=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
//			g[i].push_back({j,a[i][j]})
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(t[i].u),y=find(t[i].v);
		if(x!=y){
//			cout<<t[i].u<<" "<<t[i].v<<"\n";
			fa[find(x)]=find(y);
			g[t[i].u].push_back({t[i].v,t[i].w});
			g[t[i].v].push_back({t[i].u,t[i].w});
			rd[t[i].u]++;
			rd[t[i].v]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(rd[i]==1){
			s=i;
			break;
		}
	}
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[s]=0;
	dij();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			g[n+i].push_back({j,a[i][j]});
			g[j].push_back({n+i,a[i][j]});
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
	dij2();
	
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=find(t[i].u),y=find(t[i].v);
		if(x!=y){
//			cout<<t[i].u<<" "<<t[i].v<<"\n";
			fa[find(x)]=find(y);
			ans+=t[i].w;
		}
	}
	cout<<ans;
	return 0;
}
/*
Ren5Jie4Di4Ling5%

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/