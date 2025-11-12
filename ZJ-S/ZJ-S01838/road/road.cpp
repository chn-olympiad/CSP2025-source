#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans=0,a[11][10050],c[11],vis[11],v[10050],d[10050];
struct node{
	int u,v;
};
vector<node> w[10050];
queue<int> q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(d,0x3fffff,sizeof(d));
	for(int i=0;i<m;i++){
		int x,y,u;
		cin>>x>>y>>u;
		w[x].push_back({y,u});
		w[y].push_back({x,u});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	q.push(1);
	v[1]=1,d[1]=0;
	while(!q.empty()){
		int t=q.front(),fl=0x3fffff,fa,f=0,fg;
		q.pop();
		for(int i=0;i<w[t].size();i++){
			if(fl>w[t][i].v&&v[w[t][i].u]==0)
				fl=w[t][i].v,fa=i;
		}
		for(int i=0;i<10;i++)
			for(int j=1;j<=n;j++){
				if(vis[i]==0){
					if(fl>a[i][t]+a[i][j]+c[i]&&v[j]==0)
						fl=a[i][t]+a[i][j]+c[i],fa=j,f=1,fg=i;
				}else{
					if(fl>a[i][t]+a[i][j]&&v[j]==0)
						fl=a[i][t]+a[i][j],fa=j,f=1;
				}
			}
		if(f){
			v[fa]=1;
			ans+=fl;
			vis[fg]=1;
			q.push(fg);
		}else{
			vis[w[t][fa].u]=1;
			ans+=fl;
			q.push(w[t][fa].u);
		}
	}
}
