#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,fa[N],c[15],vis[15];
int find(int x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	else return x;
}
struct node{
	int x,y,dis;
	bool operator< (const node& id)const{
		if(dis!=id.dis)return dis<id.dis;
		else{
			if(x!=id.x) return x<id.x;
			else return y<id.y;
		}
	}
};
vector<node> g;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+2;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,y;j<=n;j++){
			cin>>y;
			g.push_back({j,n+i,y+c[i]});
		}
	}
	sort(g.begin(),g.end());
	int sum=0,cnt=0,t=0,ln=n;
	for(int i=0;i<g.size();i++){
//		cout<<g[i].x<<" "<<g[i].y<<" "<<g[i].dis<<endl;
		int x=find(g[i].x),y=find(g[i].y);
		if(x!=y){
			fa[x]=y;
			if(g[i].y>n) {
				if(!vis[g[i].y-n]) vis[g[i].y-n]=1,ln++;
				else sum-=c[g[i].y-n];
//				cout<<sum<<endl;
			}
			sum+=g[i].dis;
			cnt++;
		}
		if(cnt==ln-1) break;
	}
	cout<<sum<<endl;
	return 0;
}
/*
4 4 4
Ren5Jie4Di4Ling5%
*/
