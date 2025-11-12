#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int n,m,k,a[10][50005],q,f[50005],c[50005];
struct node{
	int x,y,c;
}g[3000005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int found(int x){
	if(f[x]==x)return x;
	f[x]=found(f[x]);
	return f[x];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		g[++q].x=x,g[q].y=y,g[q].c=w;
		g[++q].x=y,g[q].y=x,g[q].c=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				g[++q].x=j,g[q].y=k,g[q].c=a[i][j]+a[i][k];
				g[++q].x=k,g[q].y=j,g[q].c=a[i][j]+a[i][k];
			}
		}
	}
	sort(g+1,g+1+q,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=q;i++){
		int u=g[i].x,v=g[i].y,w=g[i].c;
		if(found(u)==found(v))continue;
		f[f[u]]=f[v];
		ans+=w;
	}
	cout<<ans;
}
/*
4 4 0
2 3 7
1 4 6
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
