#include <bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,z,fx,fy,mst,flag,v[20],w[20][20010],f[20010];
struct no {
	int x,y,z;
}g[1100010];
bool cmp(no q,no h) {
	return q.z<h.z;
}
int find(int x) {
	if(x==f[x]) return f[x];
	else return f[x]=find(f[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=n;i++) {
		cin>>x>>y>>z;
		g[++t].x=x;g[t].y=y;g[t].z=z;
	}
	for(int i=1;i<=k;i++) {
		cin>>v[i];
		if(v[i]!=0) flag=1;
		for(int j=1;j<=n;j++) {
			cin>>w[i][j];
			if(w[i][j]!=0) flag=1;
		}
	}
	if(!flag) return cout<<0,0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<n;j++) {
			for(int l=j+1;l<=n;l++) {
				x=j;y=l;z=w[i][j]+w[i][l]+v[i];
				g[++t].x=x;g[t].y=y;g[t].z=z;
			}
		}
	sort(g+1,g+1+t,cmp);
	for(int i=1;i<=t;i++) {
		x=g[i].x;y=g[i].y;
		z=g[i].z;
		fx=find(x);fy=find(y);
		if(fx!=fy) f[fx]=fy,mst+=z;
	}
	cout<<mst;
	return 0;
}
/*
60 pts
14.19 MiB
*/

