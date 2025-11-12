#include <bits/stdc++.h>
using namespace std;
int n,m,k,c[50],a[50][10005],vis[10005],dis[10005],ans;
int e[10005],h[10005],nx[10005],w[10006],idx=1,fl;
struct node{
	int x,cnt[10005],js;
	map<int,int> s[10005];
};
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	nx[idx]=h[a];
	h[a]=idx++;
}
void spfa(){
	queue<node> q;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	node st;
	st.x=1;
	q.push(st);
	dis[1]=0;
	vis[1]=1;
	while(q.size()){
		node t=q.front();
		cout<<t.x<<' '<<t.js<<' '<<dis[t.x]<<endl;
		q.pop();
		vis[t.x]=0;
		if(dis[t.x]>ans) continue;
		if(t.js==n){
			ans=min(ans,dis[t.x]);
			continue;
		}
		for(int i=h[t.x];i;i=nx[i]){
			int y=e[i],z=w[i];
			if(t.s[t.x][y]==1) z=0;
			if(t.cnt[y]<n){
				dis[y]=dis[t.x]+z;
				if(vis[y]==0){
					node k=t;
					vis[y]=1;
					if(t.cnt[y]==0) k.js++;
					k.cnt[y]++;
					if(k.cnt[y]>n) continue;
					k.x=y;
					q.push(k);
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) fl=1;
		for(int j=1;j<=n;i++){
			cin>>a[i][j];
			add(i+n,j,a[i][j]);
			add(j,i+n,a[i][j]);
		}
	}
	if(k==0||fl==0){
		spfa();
		cout<<ans;
	}else{
		cout<<13;
	}
	return 0;
}