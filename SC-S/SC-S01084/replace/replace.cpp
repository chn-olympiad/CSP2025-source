#include<bits/stdc++.h>
#define mf(a,b) make_pair(a,b)
using namespace std;
const int N=1e7;
int n,m,k;
int head[2*N],to[2*N],w[2*N],ne[2*N],tot;
int d[2*N],vis[2*N];
void add(int x,int y,int v){
	to[++tot]=y;
	ne[tot]=head[x];
	head[x]=tot;
	w[tot]=v;
}
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		d[i]=2e9+10;
	}
	priority_queue<pair<int,int> >q;
	q.push(mf(0,s));
	d[s]=0;
	while(!q.empty()){
		int x=q.top().second;
		q.pop() ;
		for(int i=head[x];i;i=ne[i]){
			int y=to[i];
			if(vis[y]) continue;
			vis[y]=1;
			if(d[y]>d[x]+w[i]){
				d[y]=d[x]+w[i];
				q.push(mf(-d[y],y));
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cout<<0<<"\n" ;
	}
	return 0;
}