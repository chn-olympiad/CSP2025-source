#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int cnt,ans,h[maxn];

struct edge{
	int nxt,to,w;
}a[maxn];

struct node{
	int leng,dian;
	bool operator < (node x){
		return leng>x.leng;
	}
};

int add(int u,int v,int w){
	a[++cnt].nxt=h[u];
	a[cnt].to=v;
	a[cnt].w=w;
	h[u]=cnt;
}

priority_queue<node> q;

void dijistra(){
	q.push(node{0,0});
	while(!q.empty()){
		int u=q.top().leng;
		int x=q.top().dian;
		q.pop();
		for(int i=u;i;i=a[x].to){
			ans=max(ans,ans+a[u].w);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u,v,w;
		add(u,v,w);
	}
	dijistra();
	cout<<ans<<'\n';
	return 0;
}
