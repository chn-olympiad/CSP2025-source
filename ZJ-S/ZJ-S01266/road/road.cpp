#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct node{
	int x,y;
	int w;
}g[10000010];
bool cmp(node xx,node yy){
	return xx.w<yy.w;
}
int cnt;
int cun[20][10010];
int fa[100010];
bool vis[20];
bool vis2[20];
int finds(int x){
	return fa[x]==x?x:fa[x]=finds(fa[x]);
}
int solve(){
	for(int i=0;i<=n+100;i++) fa[i]=i;
	int ans=0;
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		int fx=finds(g[i].x);
		int fy=finds(g[i].y);
		if(fx!=fy){
			if(g[i].y>n) vis2[g[i].y-n]=1;
			if(g[i].x>n) vis[g[i].x-n]=1;
//			cout<<g[i].x<<" "<<g[i].y<<" "<<g[i].w<<endl;
			fa[fx]=fy;
			ans+=g[i].w;
		}
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].x>>g[i].y>>g[i].w;
	}
	cnt=m;
	sort(g+1,g+1+cnt,cmp);
	int ans=solve();
//	cout<<ans<<endl;
	for(int i=1;i<=k;i++){
		cin>>cun[i][0];
		for(int j=1;j<=n;j++){
			cin>>cun[i][j];
		}
	}
//	for(int i=1;i<=k;i++) cout<<cun[i][0]<<" "<<endl;
	for(int i=1;i<=n;i++){
		for(int p=1;p<=k;p++){
			g[++cnt]={n+p,i,cun[p][i]+cun[p][0]};
		}
	}
//	cout<<cnt<<endl;
	for(int i=1;i<=k;i++){
		g[++cnt]={0,n+i,cun[i][0]};
	}
	sort(g+1,g+1+cnt,cmp);
//	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		if(g[i].x>n){
			g[i].w-=cun[g[i].x-n][0];
		}
	}
	int kkk=solve();
	for(int i=1;i<=k;i++){
		if(vis2[i]==1 && !vis[i]) kkk-=cun[i][0];
	}
	ans=min(ans,kkk);
//	cout<<kkk<<endl;
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/