#include<bits/stdc++.h>
using namespace std;
const int inf=1e7;
long long n,n1,m,k,l,h[inf],dis[inf];
bool vis[inf],vis1[inf];
struct node{
	int u,v,next;
	long long w;
}e[inf];
struct edge{
	int u;
	long long dis;
	edge(int x,long long y){
	    u=x;dis=y;
	}
	bool operator>(const edge a)const{
		return dis<a.dis;
	}
};
priority_queue<edge,vector<edge>,greater<edge>> q;
void read(){
	for(int i=1;i<=m;i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		e[++l].u=ui;
		e[l].v=vi;
		e[l].w=wi;
		e[l].next=h[ui];
		h[ui]=l;
	    e[++l].u=vi;
		e[l].v=ui;
		e[l].w=wi;
		e[l].next=h[vi];
		h[vi]=l;
	}
	long long c;
	cin>>c;
	for(int i=1;i<=k;i++){
	    for(int j=1;j<=n;j++){
		    int ui=++n,vi=i,wi;
			cin>>wi;
			e[++l].u=ui;
			e[l].v=vi;
			e[l].w=wi+c/2;
			e[l].next=h[ui];
			h[ui]=l;
			e[++l].u=vi;
			e[l].v=ui;
			e[l].w=wi+c/2;
			e[l].next=h[vi];
			h[vi]=l;
	    }
	}
}
void dijis(int s){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	q.push(edge(s,0));
	dis[s]=0;
	while(!q.empty()){
		int r=q.top().u;
		long long wi=q.top().dis;
		q.pop();
		vis[r]=1;
		for(int i=h[r];i;i=e[i].next){
			int vi=e[i].v;
			if(dis[vi]>dis[r]+wi){
				dis[vi]=dis[r]+wi;
			}
		    if(!vis[vi]){
				q.push(edge(vi,dis[vi]));
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	read();
	dijis(1);
	cout<<dis[n];
	return 0;
}